#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>

namespace cruz
{
	class Application
	{
		const uint32_t WIDTH = 800;
		const uint32_t HEIGHT = 600;
	public:
		void run();

	private:

#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else
		const bool enableValidationLayers = true;
#endif

		const std::vector<const char*> validationLayers
		{
			"VK_LAYER_KHRONOS_validation"
		};

		void initWindow();
		void initVulkan();
		void mainLoop();
		void cleanup();
		void createInstance();
		bool checkValidationLayerSupport();

		GLFWwindow* window;
		VkInstance instance;
	};
}