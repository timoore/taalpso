// Copyright (c) 2023 Timothy Moore

#include "View.h"
#include "psodefs.h"

#include <vsg/core/ConstVisitor.h>
#include <vsg/vk/ResourceRequirements.h>

#include <algorithm>

namespace taal
{
    namespace pso
    {
        void View::accept(vsg::ConstVisitor& visitor) const
        {
            auto* resourceCollector = dynamic_cast<vsg::CollectResourceRequirements*>(&visitor);
            if (resourceCollector)
            {
                resourceCollector->requirements.maxSlot = std::max(resourceCollector->requirements.maxSlot,
                                                                   scissorSlot);
            }
            Inherit::accept(visitor);
        }

        void View::accept(vsg::RecordTraversal& visitor) const
        {
            if ((visitor.traversalMask & (visitor.overrideMask | mask)) == vsg::MASK_OFF)
            {
                return;
            }
            
        }
    }
}
