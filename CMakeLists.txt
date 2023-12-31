cmake_minimum_required(VERSION 3.22)

project(taalpso
        VERSION 0.0.0
        DESCRIPTION "Pipeline State Object management for VSG"
        LANGUAGES CXX C
)

SET(TAALPSO_RELEASE_CANDIDATE 0)

# build all examples into the bin directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# Change the default build type to Release
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE)

# find the vsg
if (VULKAN_SDK)
    set(ENV{VULKAN_SDK} ${VULKAN_SDK})
endif()

find_package(vsg 1.0.8)

vsg_setup_dir_vars()
vsg_setup_build_vars()

# find vsgXchange that can be used for reading and range of image and 3d model formats and shader compilation
find_package(vsgXchange 1.0.2 QUIET)

# set the use of C++17 globally as all examples require it
set(CMAKE_CXX_STANDARD 17)

if (MSVC)
    add_compile_options(/bigobj)
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

vsg_add_target_clang_format(
    FILES
        ${CMAKE_SOURCE_DIR}/*/*/*.h
        ${CMAKE_SOURCE_DIR}/*/*/*.cpp
        ${CMAKE_SOURCE_DIR}/*/*/*/*.h
        ${CMAKE_SOURCE_DIR}/*/*/*/*.cpp
)
vsg_add_target_clobber()
vsg_add_target_cppcheck(
    FILES
        examples/
)
vsg_add_target_docs(
    FILES
        examples/
)
vsg_add_target_uninstall()

include_directories(${taalpso_SOURCE_DIR}/src)

add_subdirectory(src/taal/pso)
add_subdirectory(examples/viewer)

vsg_add_feature_summary()
