#include <glad/glad.h>
#include <GLFW/glfw3.h> //open gl

#include <iostream>

using namespace std;
int main()

{
	//buffer - an array of bytes of memory, a blob a memory where we can
      // push bytes in, in gpu with graphics
	//	shader - program that runs on the gpu, gpu will read the dataand joint up the positions to draw a triangle
	glfwInit(); //initilizates the GLFW library
	//GLFW will try to create an OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glf window hint sets the specified window hint to the desired value
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//GLFW_CONTEXT_VERSION_MAJOR and GLFW_CONTEXT_VERSION_MINOR
	//specify the client API version that the 
	//created context must be compatible with. 
	//The exact behavior of these hints 
	//depend on the requested client API.
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//GLFW_OPENGL_PROFILE indicates the OpenGL profile used by the context
    //https://www.khronos.org/opengl/wiki/OpenGL_Context 
	//Think of a context as an object that holds all of OpenGL
	//GLFW_OPENGL_PROFILE specifies which OpenGL profile to create the context for. 
	//Possible values are one of GLFW_OPENGL_CORE_PROFILE

	GLFWwindow* window = glfwCreateWindow(800, 600, "Shape Window", NULL, NULL);

	//glfwCreateWindow is a function that creates the window passing these self explanatory  paramaters
	//the last two parameters null, and null are passing in arguments for monitor and shared. If you wanted a full screen, pass 
	//GLFWwindow* monitor.
	//the last parameter null is to share the resource
	if (window == NULL)
	{
		cout << "Error";
		glfwTerminate();
		return -1;

	}
	glfwMakeContextCurrent(window);

//GLFW window function pointer type for window position callbacks
	//GlAD
	//We pass GLAD the function to load the address of the OpenGL function pointers which is OS - 
		//specific.GLFW gives us glfwGetProcAddress that defines the correct function based on which OS we're compiling for.
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		cout << "Failed to initialize GLAD"<< endl;
		return -1;
	}

	
	//loop for window so that it doesn't close once it draws an image
	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}