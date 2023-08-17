set(LIB_NAME taalpso)

set(LIB_PUBLIC_HEADERS
  psodefs.h
  GraphicsPipeline.h
  RenderGraph.h
  SetScissorState.h
  SetViewportState.h
  View.h
)

set(SOURCES
  ${LIB_PUBLIC_HEADERS}
  GraphicsPipeline.cpp
  RenderGraph.cpp
  SetScissorState.cpp
  SetViewportState.cpp
  View.cpp
)

add_library(
    ${LIB_NAME}
    ${LIB_PUBLIC_HEADERS}
    ${SOURCES}
)

set_target_properties(${LIB_NAME} PROPERTIES
  PUBLIC_HEADER "${LIB_PUBLIC_HEADERS}"
)


target_link_libraries(${LIB_NAME} PUBLIC vsg::vsg)

install(TARGETS ${LIB_NAME} EXPORT taalpsoTargets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  PUBLIC_HEADER DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${LIB_NAME}"
  )
