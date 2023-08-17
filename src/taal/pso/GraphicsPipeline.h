// Copyright (c) 2023 Timothy Moore

#pragma once

#include <vsg/state/GraphicsPipeline.h>

namespace taal
{
    namespace pso
    {
        class GraphicsPipeline : public vsg::Inherit<vsg::GraphicsPipeline, GraphicsPipeline>
        {
        public:
            GraphicsPipeline();
            GraphicsPipeline(vsg::PipelineLayout* pipelineLayout, const vsg::ShaderStages& shaderStages,
                             const vsg::GraphicsPipelineStates& pipelineStates, uint32_t subpass = 0);
            explicit GraphicsPipeline(const vsg::GraphicsPipeline& rhs);
        };
    }
}
