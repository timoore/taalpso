// Copyright (c) 2023 Timothy Moore

#include "GraphicsPipeline.h"

#include <vsg/state/DynamicState.h>
#include <vsg/state/ViewportState.h>

using namespace taal;
using namespace taal::pso;

namespace
{
    vsg::ref_ptr<vsg::DynamicState> createDynamicState()
    {
        return vsg::DynamicState::create(VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR);
    }

    void addViewportStates(GraphicsPipeline& pipeline)
    {
        pipeline.pipelineStates.push_back(createDynamicState());
        // Add a viewport state. This will be overriden by the dynamic state, but it will keep the
        // pipeline from being recompiled on window resize. Also, the number of viewports and
        // scissors is set by this too.
        pipeline.pipelineStates.push_back(vsg::ViewportState::create(0, 0, 0, 0));
    }
}

GraphicsPipeline::GraphicsPipeline()
{
    addViewportStates(*this);
}

GraphicsPipeline::GraphicsPipeline(vsg::PipelineLayout* pipelineLayout, const vsg::ShaderStages& shaderStages,
                                   const vsg::GraphicsPipelineStates& pipelineStates, uint32_t subpass)
    : Inherit(pipelineLayout, shaderStages, pipelineStates, subpass)
{
    addViewportStates(*this);
}


GraphicsPipeline::GraphicsPipeline(const vsg::GraphicsPipeline& rhs)
    : Inherit(rhs)
{
    addViewportStates(*this);
}
