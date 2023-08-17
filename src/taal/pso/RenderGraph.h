// Copyright (c) 2023 Timothy Moore

#pragma once

#include <vsg/app/RenderGraph.h>
#include <vsg/app/View.h>

namespace taal
{
    namespace pso
    {
        class RenderGraph : public vsg::Inherit<vsg::RenderGraph, RenderGraph>
        {
        public:
            RenderGraph() = default;
            explicit RenderGraph(vsg::ref_ptr<vsg::Window> in_window, vsg::ref_ptr<vsg::View> view = {});
            // Hook into resource collection
            void accept(vsg::ConstVisitor& visitor) const override;
            void accept(vsg::RecordTraversal& recordTraversal) const override;
        };
    }
}
    
