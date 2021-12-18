cmake_minimum_required(VERSION 3.0.0)
project(Crafter VERSION 0.1.0)

include(CTest)
enable_testing()

#manual adding of cpp files to linkage
add_executable(Crafter 
main.cpp #main

#everything here on out is manual additions
src/debug/log.cpp
src/debug/glfwErrorCallback.cpp
src/mesh.cpp
src/chunk.cpp
src/deltaTime.cpp
src/shaderCode/shaderCode.cpp
src/explicitIO/explicitIO.cpp
)
#end manual additions

#set opengl to a new version
set(OpenGL_GL_PREFERENCE GLVND)

#manual inclusion of /source/
include_directories(${CMAKE_SOURCE_DIR})

#glfw directory management
add_subdirectory(glfw-3.3.6)
include_directories(glfw-3.3.6/include)
include_directories(glfw-3.3.6/src)

#glfw linkages
target_link_libraries(Crafter glfw ${GLFW_LIBRARIES})
target_link_libraries(Crafter glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})


#glm directory management
add_subdirectory(glm)
include_directories(glm/glm)

#glm linkages
target_link_libraries(Crafter glm ${GLM_LIBRARIES})

#glad directory management
add_subdirectory(glad)
include_directories(glad/include)
include_directories(glad/src)

#glad linkages
target_link_libraries(Crafter glad ${GLAD_LIBRARIES})

#manual inclusion of OpenGL
find_package(OpenGL REQUIRED)

#manual OpenGL linkage
target_link_libraries(Crafter OpenGL::GL)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set_target_properties( Crafter
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}"
)