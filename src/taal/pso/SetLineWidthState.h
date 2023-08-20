// Copyright (c) 2023 Timothy Moore

#pragma once

#include <vsg/state/StateCommand.h>

namespace taal
{
    namespace pso
    {
        class SetLineWidthState : public vsg::Inherit<vsg::StateCommand, SetLineWidthState>
        {
        public:
            SetLineWidthState();
            float lineWidth = 1.0f;
            void record(vsg::CommandBuffer& commandBuffer) const override;

            int compare(const vsg::Object& rhs) const override;

            void read(vsg::Input& input) override;
            void write(vsg::Output& output) const override;
        };
    }
}
