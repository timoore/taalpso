// Copyright (c) 2023 Timothy Moore

#pragma once

#include <cstdint>

namespace taal
{
    namespace pso
    {
        inline constexpr uint32_t maxBoundDescriptors = 8;
        enum Slot : uint32_t
        {
            psoSlot = 0,
            viewportSlot = maxBoundDescriptors + 1,
            scissorSlot,
            lineWidthSlot,
            maxPsoSlots
        };

        constexpr uint32_t maxSlot()
        {
            return maxPsoSlots - 1;
        }
    }
}
