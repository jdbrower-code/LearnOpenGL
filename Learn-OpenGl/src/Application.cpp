#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


/*Initiate callback function for user window resize*/
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main()
{
	/*Initial GLFW*/
	glfwInit();
	/*Set glfw version*/
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	/*Set GLFW Profile*/
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	/*Create GLFW Window object*/

	GLFWwindow* window = glfwCreateWindow(
		800,			/*Window Width*/
		600,			/*Window Height*/
		"LearnOpenGl",	/*Window Title*/
		NULL,			/*Selected monitor for full screen, NULL if Windowed*/
		NULL);			/*The window whose context to share resources with, NULL to not share resources.*/

	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	/*Make the context of our window the main context on the current thread.*/
	glfwMakeContextCurrent(window);

	/*Initialize GLAD*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to Initialize GLAD" << std::endl;
		return -1;
	}

	/*Create Viewport...
	The size of the rendering window so OpenGL knows how we want 
	to display the data and coordinates with respect to the window*/
	glViewport(
		0,		/*x coord of lower left corner of window*/
		0,		/*Y coord of lower left corner of window*/
		800,	/*Width*/
		600);	/*Height*/

	/*Tell GLFW the window size was changed*/
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*Main Loop*/

	while (!glfwWindowShouldClose(window)/*checks if window has been instructed to close*/)
	{
		/*swap the color buffer 
		(a large 2D buffer that contains color values for each pixel in GLFW's window) 
		that is used to render to during this render iteration and show it as output to the screen.*/
		glfwSwapBuffers(window);
		/*checks if any events are triggered (like keyboard input or mouse movement events), 
		updates the window state, and calls the corresponding functions 
		(which we can register via callback methods)*/
		glfwPollEvents();
	}	

	glfwTerminate();

}
