// Copyright (c) 2023 Timothy Moore

#include "RenderGraph.h"

#include "psodefs.h"
#include "SetScissorState.h"
#include "SetViewportState.h"

#include <vsg/state/ViewportState.h>
#include <vsg/vk/ResourceRequirements.h>
#include <vsg/vk/State.h>

using namespace taal;
using namespace taal::pso;

RenderGraph::RenderGraph(vsg::ref_ptr<vsg::Window> in_window, vsg::ref_ptr<vsg::View> view)
    : Inherit(in_window, view)
{
}

void RenderGraph::accept(vsg::ConstVisitor& visitor) const
{
    auto* resourceCollector = dynamic_cast<vsg::CollectResourceRequirements*>(&visitor);
    if (resourceCollector)
    {
        resourceCollector->requirements.maxSlot = std::max(resourceCollector->requirements.maxSlot,
                                                           scissorSlot);
    }
    vsg::RenderGraph::accept(visitor);
}

void RenderGraph::accept(vsg::RecordTraversal& recordTraversal) const
{
    auto* state = recordTraversal.getState();
    // XXX Eventually need to coordinate multiple viewports with pipelines that expect them
    // XXX cache this
    VkViewport viewport = {static_cast<float>(renderArea.offset.x),
                                        static_cast<float>(renderArea.offset.y),
                                        static_cast<float>(renderArea.extent.width),
                                        static_cast<float>(renderArea.extent.height),
                                        0.0f, 1.0f};
    auto viewportCmd = SetViewportState::create(0, vsg::Viewports{viewport});
    auto scissorsCmd = SetScissorState::create(0, vsg::Scissors{renderArea});
    state->stateStacks[viewportCmd->slot].push(viewportCmd);
    state->stateStacks[scissorsCmd->slot].push(scissorsCmd);
    state->dirty = true;
    vsg::RenderGraph::accept(recordTraversal);
    state->stateStacks[viewportCmd->slot].pop();
    state->stateStacks[scissorsCmd->slot].pop();
    state->dirty = true;
}
