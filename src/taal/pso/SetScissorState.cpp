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

int SetScissorState::compare(const Object& rhs_object) const
{
    if (int result = Object::compare(rhs_object); result != 0)
    {
        return result;
    }

    auto& rhs = static_cast<decltype(*this)>(rhs_object);
    if (int result = vsg::compare_value(firstScissor, rhs.firstScissor); result != 0)
    {
        return result;
    }
    return vsg::compare_value_container(scissors, rhs.scissors);
}

void SetScissorState::read(vsg::Input& input)
{
    StateCommand::read(input);
    input.read("firstScissor", firstScissor);
    scissors.resize(input.readValue<uint32_t>("scissors"));
    for (auto& scissor : scissors)
    {
        input.read("x", scissor.offset.x);
        input.read("y", scissor.offset.y);
        input.read("width", scissor.extent.width);
        input.read("height", scissor.extent.height);
    }
}

void SetScissorState::write(vsg::Output& output) const
{
    StateCommand::write(output);
    output.write("firstScissor", firstScissor);
    output.writeValue<uint32_t>("scissors", scissors.size());
    for (auto& scissor : scissors)
    {
        output.write("x", scissor.offset.x);
        output.write("y", scissor.offset.y);
        output.write("width", scissor.extent.width);
        output.write("height", scissor.extent.height);
    }
}

