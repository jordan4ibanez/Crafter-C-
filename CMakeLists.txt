cmake_minimum_required(VERSION 3.0.0)
project(Crafter VERSION 0.1.0)

include(CTest)
enable_testing()

#manual adding of cpp files to linkage
add_executable(Crafter 
main.cpp #main

#everything here on out is manual additions
src/mesh.cpp
)
#end manual additions

#manual inclusion of /source/
include_directories(${CMAKE_SOURCE_DIR})

#glfw directory management
add_subdirectory(glfw-3.3.6)
include_directories(glfw-3.3.6/include)
include_directories(glfw-3.3.6/src)

#glfw linkages
target_link_libraries(Crafter glfw ${GLFW_LIBRARIES})
target_link_libraries(Crafter glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})

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