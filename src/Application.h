#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>

namespace cruz
{
	class Application
	{
	public:
		void run();

	private:
		GLFWwindow* window;
		VkInstance instance;
	};
}