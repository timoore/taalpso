// Copyright (c) 2023 Timothy Moore

#include "SetViewportState.h"

#include "psodefs.h"

#include <vsg/vk/CommandBuffer.h>

using namespace taal;
using namespace taal::pso;

SetViewportState::SetViewportState()
    : Inherit(viewportSlot)
{
}

SetViewportState::SetViewportState(uint32_t in_firstViewport,  vsg::Viewports in_viewports) :
    Inherit(viewportSlot),
    firstViewport(in_firstViewport),
    viewports(std::move(in_viewports))
{
}

void SetViewportState::record(vsg::CommandBuffer& commandBuffer) const
{
    vkCmdSetViewport(commandBuffer, firstViewport, static_cast<uint32_t>(viewports.size()), viewports.data());
}

int SetViewportState::compare(const Object& rhs_object) const
{
    if (int result = Object::compare(rhs_object); result != 0)
    {
        return result;
    }

    auto& rhs = static_cast<decltype(*this)>(rhs_object);
    if (int result = vsg::compare_value(firstViewport, rhs.firstViewport); result != 0)
    {
        return result;
    }
    return vsg::compare_value_container(viewports, rhs.viewports);
}

void SetViewportState::read(vsg::Input& input)
{
    StateCommand::read(input);
    input.read("firstViewport", firstViewport);
    viewports.resize(input.readValue<uint32_t>("viewports"));
    for (auto& viewport : viewports)
    {
        input.read("x", viewport.x);
        input.read("y", viewport.y);
        input.read("width", viewport.width);
        input.read("height", viewport.height);
        input.read("minDepth", viewport.minDepth);
        input.read("maxDepth", viewport.maxDepth);

    }
}

void SetViewportState::write(vsg::Output& output) const
{
    StateCommand::write(output);
    output.write("firstViewport", firstViewport);
    output.writeValue<uint32_t>("viewports", viewports.size());
    for (auto& viewport : viewports)
    {
        output.write("x", viewport.x);
        output.write("y", viewport.y);
        output.write("width", viewport.width);
        output.write("height", viewport.height);
        output.write("minDepth", viewport.minDepth);
        output.write("maxDepth", viewport.maxDepth);
    }
}
