// Copyright (c) 2023 Timothy Moore

#include "SetScissorState.h"

#include "psodefs.h"

#include <vsg/vk/CommandBuffer.h>

using namespace taal;
using namespace taal::pso;

SetScissorState::SetScissorState()
    : Inherit(scissorSlot)
{
}

SetScissorState::SetScissorState(uint32_t in_firstScissor,  vsg::Scissors in_scissors) :
    Inherit(scissorSlot),
    firstScissor(in_firstScissor),
    scissors(std::move(in_scissors))
{
}

void SetScissorState::record(vsg::CommandBuffer& commandBuffer) const
{
    vkCmdSetScissor(commandBuffer, firstScissor, static_cast<uint32_t>(scissors.size()), scissors.data());
}

