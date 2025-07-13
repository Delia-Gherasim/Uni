// #include <GLFW/glfw3.h>
//
// int main(void)
// {
//     GLFWwindow* window;
//     if (!glfwInit())
//         return -1;
//
//     window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
//     if (!window)
//     {
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//
//     while (!glfwWindowShouldClose(window))
//     {
//         glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//
//     glfwTerminate();
//     return 0;
// }
// // daca rulezi din msys2 mingw64: la pathu /c/Facultation/sem6/grafica/lab3
// // $ g++ -o lab3 C:/Facultation/sem6/grafica/lab3/lab3.cpp -I"C:/msys64/mingw64/include" -L"C:/msys64/mingw64/lib" -lglfw3 -lglew32 -lfreeglut -lopengl32 -lglu32
//
