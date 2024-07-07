#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <vector>
#include <optional>


namespace cruz
{
	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() const {
			return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};


	class Application
	{
	public:
		void run();

	private:
		void initWindow();
		void initVulkan();
		void mainLoop();
		void cleanup();
		void createInstance();
		bool checkValidationLayerSupport();
		std::vector<const char*> getRequiredExtensions();
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

		static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData);

		void setupDebugMessenger();
		void pickPhysicalDevice();
		bool isDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
		void createLogicalDevice();
		void createSurface();

		GLFWwindow* window;
		VkInstance instance;
		
		VkDebugUtilsMessengerEXT debugMessenger;
		VkSurfaceKHR surface;
		
		VkPhysicalDevice physicalDevice;
		VkDevice device;
		
		VkQueue graphicsQueue;
		VkQueue presentQueue;
	};
}