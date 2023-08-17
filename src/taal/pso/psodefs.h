// Copyright (c) 2023 Timothy Moore

#pragma once

#include <cstdint>

namespace taal
{
    namespace pso
    {
        inline constexpr uint32_t maxBoundDescriptors = 8;
        inline constexpr uint32_t psoSlot = 0;
        inline constexpr uint32_t viewportSlot = maxBoundDescriptors + 1;
        inline constexpr uint32_t scissorSlot = maxBoundDescriptors + 2;
    }
}
