// Copyright (c) 2023 Timothy Moore

#include "View.h"

#include "psodefs.h"
#include "SetScissorState.h"
#include "SetViewportState.h"

#include <vsg/core/ConstVisitor.h>
#include <vsg/vk/ResourceRequirements.h>
#include <vsg/vk/State.h>

#include <algorithm>

using namespace taal;
using namespace taal::pso;

void View::accept(vsg::ConstVisitor& visitor) const
{
    auto* resourceCollector = dynamic_cast<vsg::CollectResourceRequirements*>(&visitor);
    if (resourceCollector)
    {
        resourceCollector->requirements.maxSlot = std::max(resourceCollector->requirements.maxSlot,
                                                           scissorSlot);
    }
    vsg::View::accept(visitor);
}

void View::accept(vsg::RecordTraversal& visitor) const
{
    if ((visitor.traversalMask & (visitor.overrideMask | mask)) == vsg::MASK_OFF)
    {
        return;
    }
    if (camera)
    {
        auto* state = visitor.getState();
        auto viewportState = camera->viewportState;
        auto viewportCmd = SetViewportState::create(0, viewportState->viewports);
        state->stateStacks[viewportCmd->slot].push(viewportCmd);
        auto scissorsCmd = SetScissorState::create(0, viewportState->scissors);
        state->stateStacks[scissorsCmd->slot].push(scissorsCmd);
        state->dirty = true;
        vsg::View::accept(visitor);
        state->stateStacks[viewportCmd->slot].pop();
        state->stateStacks[scissorsCmd->slot].pop();
        state->dirty = true;
    }
    else
    {
        vsg::View::accept(visitor);
    }
}

