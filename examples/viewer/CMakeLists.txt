set(SOURCES
  vsgviewer.cpp
)

SET(TARGET_SRC ${SOURCES})

add_executable(psoviewer ${SOURCES})

target_link_libraries(psoviewer PUBLIC taalpso vsg::vsg vsg::vsg)

if (vsgXchange_FOUND)
  target_compile_definitions(psoviewer PRIVATE vsgXchange_FOUND)
  target_link_libraries(psoviewer PRIVATE vsgXchange::vsgXchange)
endif()

install(TARGETS psoviewer
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

