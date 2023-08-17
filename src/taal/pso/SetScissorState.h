// Copyright (c) 2023 Timothy Moore

#pragma once

#include <vsg/state/StateCommand.h>
#include <vsg/state/ViewportState.h>

namespace taal
{
    namespace pso
    {
        class SetScissorState : public vsg::Inherit<vsg::StateCommand, SetScissorState>
        {
        public:
            SetScissorState();
            SetScissorState(uint32_t in_firstScissor, vsg::Scissors in_scissors);

            uint32_t firstScissor = 0;
            vsg::Scissors scissors;

            void record(vsg::CommandBuffer& commandBuffer) const override;
        };
    }
}
