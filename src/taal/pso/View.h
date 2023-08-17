// Copyright (c) 2023 Timothy Moore

#pragma once

#include <vsg/app/View.h>

namespace taal
{
    namespace pso
    {
        class View : public vsg::Inherit<vsg::View, View>
        {
        public:
            View() = default;

            explicit View(vsg::ref_ptr<vsg::Camera> in_camera, vsg::ref_ptr<vsg::Node> in_scenegraph = {})
                : Inherit(in_camera, in_scenegraph)
            {
            }

            // Hook into resource collection
            void accept(vsg::ConstVisitor& visitor) const override;
            // Guts of the implementation
            void accept(vsg::RecordTraversal& visitor) const override;
        };
    }
}
