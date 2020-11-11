cmake_minimum_required(VERSION 3.17)
project(BASIC_OGRE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")

set(CMAKE_MODULE_PATH
    "${BASIC_OGRE_SOURCE_DIR}/CMake"
    "${BASIC_OGRE_SOURCE_DIR}/CMake/Utils"
    "${BASIC_OGRE_SOURCE_DIR}/CMake/Packages"
)
MESSAGE("${BASIC_OGRE_SOURCE_DIR}")
MESSAGE("${CMAKE_MODULE_PATH}")

set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG=1 -D_DEBUG=1" )

OPTION(USE_SYSTEM_OGRE "Use the systemwide installed Version of Ogre" True)
set(M_OGRE_PATH "/path/to/ogre-next" CACHE "PATH" "Ogre Path" )
set(M_OGRE_BUILD_PATH "${M_OGRE_PATH}/build" CACHE "PATH" "Ogre Build Path")


if(USE_SYSTEM_OGRE)
    find_package(OGRE)
    SET(M_OGRE_INCLUDE_DIRS
        ${OGRE_INCLUDE_DIR}
        ${OGRE_INCLUDE_DIR}/Hlms
        ${OGRE_INCLUDE_DIR}/Hlms/Common
        ${OGRE_HlmsUnlit_INCLUDE_DIR}
        ${OGRE_HlmsPbs_INCLUDE_DIR}
        ${OGRE_Plugin_ParticleFX_INCLUDE_DIR}
        ${OGRE_RenderSystem_GL3Plus_INCLUDE_DIR})
    SET(M_OGRE_LIBS
        ${OGRE_LIBRARY_DBG}
        ${OGRE_HlmsUnlit_LIBRARY_DBG}
        ${OGRE_HlmsPbs_LIBRARY_DBG}
        ${OGRE_Plugin_ParticleFX_LIBRARY_DBG}
        ${OGRE_RenderSystem_GL3Plus_LIBRARY_DBG})
else()
    set(M_OGRE_INCLUDE_DIRS
            ${M_OGRE_BUILD_PATH}/include
            ${M_OGRE_PATH}/OgreMain/include
            ${M_OGRE_PATH}/Components/Hlms/Pbs/include
            ${M_OGRE_PATH}/Components/Hlms/Unlit/include
            ${M_OGRE_PATH}/Components/Hlms/Common/include
            ${M_OGRE_PATH}/RenderSystems/GL3Plus/include
            ${M_OGRE_PATH}/RenderSystems/GL3Plus/include/GLSL
            ${M_OGRE_PATH}/PlugIns/ParticleFX/include
            ${M_OGRE_PATH}/RenderSystems/Direct3D11/include)
    SET(M_OGRE_LIBS
        ${M_OGRE_BUILD_PATH}/lib/libOgreMain_d.so
        ${M_OGRE_BUILD_PATH}/lib/libOgreHlmsPbs_d.so
        ${M_OGRE_BUILD_PATH}/lib/libOgreHlmsUnlit_d.so
        ${M_OGRE_BUILD_PATH}/lib/libOgreOverlay_d.so
        ${M_OGRE_BUILD_PATH}/lib/RenderSystem_GL3Plus_d.so
        ${M_OGRE_BUILD_PATH}/lib/RenderSystem_NULL_d.so)
endif()

include_directories(
    ${BASIC_OGRE_SOURCE_DIR}
    ${M_OGRE_INCLUDE_DIRS}
)

include_directories(
        ${OGRE_INCLUDE_DIR}
        ${OGRE_INCLUDE_DIR}/Hlms
        ${OGRE_INCLUDE_DIR}/Hlms/Common
        ${OGRE_HlmsUnlit_INCLUDE_DIR}
        ${OGRE_HlmsPbs_INCLUDE_DIR}
        ${OGRE_Plugin_ParticleFX_INCLUDE_DIR}
        ${OGRE_RenderSystem_GL3Plus_INCLUDE_DIR}
)

add_executable(BasicOgre
        yEngine.cpp
        main.cpp)
target_link_libraries(BasicOgre
        ${M_OGRE_LIBS}
)
