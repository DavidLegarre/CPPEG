cmake_minimum_required(VERSION 3.15)
project(GameEngineStarter)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Set source files
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.h)

# Add SDL2 (you need to install SDL2 beforehand)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Add GLAD
include_directories(external/glad/include)
add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

# Add GLFW (used to initialize OpenGL context)
add_subdirectory(external/glfw)
include_directories(external/glfw/include)

# Add glm (math library)
include_directories(external/glm)

add_executable(GameEngine ${SOURCES} ${HEADERS})

target_link_libraries(GameEngine
    ${SDL2_LIBRARIES}
    glad
    glfw
    dl
)
target_include_directories(GameEngine PRIVATE include)
