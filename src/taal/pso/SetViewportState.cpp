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
