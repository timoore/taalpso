// Copyright (c) 2023 Timothy Moore

#include "SetLineWidthState.h"

#include "psodefs.h"

#include <vsg/vk/CommandBuffer.h>

using namespace taal;
using namespace taal::pso;

SetLineWidthState::SetLineWidthState()
    : Inherit(lineWidthSlot)
{
}

void SetLineWidthState::record(vsg::CommandBuffer& commandBuffer) const
{
    vkCmdSetLineWidth(commandBuffer, lineWidth);
}

int SetLineWidthState::compare(const Object& rhs_object) const
{
    if (int result = Object::compare(rhs_object); result != 0)
    {
        return result;
    }

    auto& rhs = static_cast<decltype(*this)>(rhs_object);
    return vsg::compare_value(lineWidth, rhs.lineWidth);
}

void SetLineWidthState::read(vsg::Input& input)
{
    StateCommand::read(input);
    input.read("lineWidth", lineWidth);
}

void SetLineWidthState::write(vsg::Output& output) const
{
    StateCommand::write(output);
    output.write("lineWidth", lineWidth);
}

