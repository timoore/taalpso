// Copyright (c) 2023 Timothy Moore

#pragma once

#include <vsg/state/StateCommand.h>
#include <vsg/state/ViewportState.h>

namespace taal
{
    namespace pso
    {
        class SetViewportState : public vsg::Inherit<vsg::StateCommand, SetViewportState>
        {
        public:
            SetViewportState();
            SetViewportState(uint32_t in_firstViewport, vsg::Viewports in_viewports);

            uint32_t firstViewport = 0;
            vsg::Viewports viewports;

            void record(vsg::CommandBuffer& commandBuffer) const override;

            int compare(const vsg::Object& rhs) const override;

            void read(vsg::Input& input) override;
            void write(vsg::Output& output) const override;
        };
    }
}
