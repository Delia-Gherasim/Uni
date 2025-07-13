cmake_minimum_required(VERSION 3.10)
project(OpenGLApp)

set(CMAKE_CXX_STANDARD 17)

# Add GLAD and your source files
add_executable(OpenGLApp main.cpp glad.c)

# Include directories
include_directories("C:/msys64/mingw64/include")

# Link directories
link_directories("C:/msys64/mingw64/lib")

# Link necessary OpenGL libraries
target_link_libraries(OpenGLApp
        glfw
        glew32
        freeglut
        opengl32
        glu32
        glfw3  # Make sure glfw3 is linked correctly, if it's in the lib folder
)
