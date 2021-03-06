#include <Blob/VK/Instance.hpp>

// Blob
#include <Blob/VK/Exception.hpp>
#include <Blob/VK/Window.hpp>

// glfw
#include <GLFW/glfw3.h>

// std
#include <cstring>
#include <iostream>
#include <ostream>

namespace Blob::VK {
/*
Instance::Instance() {
loadExtentions();
loadLayers();
if (enableValidationLayers && !checkLayerSupport()) {
    throw std::runtime_error("validation layers requested, but not available!");
}

VkApplicationInfo appInfo = {};
appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
appInfo.pApplicationName = "Hello Triangle";
appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
appInfo.pEngineName = "No Engine";
appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
appInfo.apiVersion = VK_API_VERSION_1_0;

VkInstanceCreateInfo createInfo = {};
createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
createInfo.pApplicationInfo = &appInfo;

if (enableValidationLayers) {
    createInfo.enabledLayerCount =
static_cast<uint32_t>(validationLayers.size()); createInfo.ppEnabledLayerNames =
validationLayers.data(); } else { createInfo.enabledLayerCount = 0;
}

uint32_t glfwExtensionCount = 0;
const char **glfwExtensions;

glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

std::vector<const char *> extensions(glfwExtensions, glfwExtensions +
glfwExtensionCount);

if (enableValidationLayers) {
    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
}

createInfo.enabledExtensionCount = (uint32_t) extensions.size();
createInfo.ppEnabledExtensionNames = extensions.data();

if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
    throw Exception("Unable to create VK instance");

if (enableValidationLayers)
    setDebugCallback();
}

Instance::~Instance() {
if (enableValidationLayers)
    destroyDebugCallback();
vkDestroyInstance(instance, nullptr);
}

void Instance::loadExtentions() {
uint32_t pPropertyCount = 0;

if (vkEnumerateInstanceExtensionProperties(nullptr, &pPropertyCount, nullptr) !=
VK_SUCCESS) throw Exception("Unable to get Extentions");

extensions.resize(pPropertyCount);

if (vkEnumerateInstanceExtensionProperties(nullptr, &pPropertyCount,
extensions.data()) != VK_SUCCESS) throw Exception("Unable to get Extentions");
}

void Instance::loadLayers() {
uint32_t pPropertyCount = 0;

if (vkEnumerateInstanceLayerProperties(&pPropertyCount, nullptr) != VK_SUCCESS)
    throw Exception("Unable to get Layers");

layers.resize(pPropertyCount);

if (vkEnumerateInstanceLayerProperties(&pPropertyCount, layers.data()) !=
VK_SUCCESS) throw Exception("Unable to get Layers");
}

bool Instance::checkLayerSupport() {
for (const char *layerName : validationLayers) {
    bool layerFound = false;

    for (const auto &layerProperties : layers) {
        if (strcmp(layerName, layerProperties.layerName) == 0) {
            layerFound = true;
            break;
        }
    }
    if (!layerFound)
        return false;
}

return true;
}

std::ostream &operator<<(std::ostream &os, const Instance &p) {
os << "Vulkan Instance :" << std::endl;

if (p.enableValidationLayers)
    os << "Validation layers : ON" << std::endl;
else
    os << "Validation layers : OFF" << std::endl;

os << "Available extensions:" << std::endl;

for (const auto &extension : p.extensions)
    os << "\t" << extension.extensionName << std::endl;

os << "Available layers:" << std::endl;

for (const auto &layer : p.layers)
    os << "\t" << layer.description << "(" << layer.layerName << ")" <<
std::endl;

return os;
}

void Instance::setDebugCallback() {
VkDebugUtilsMessengerCreateInfoEXT createInfo = {};
createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT |
                             VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT; createInfo.messageType =
VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                         VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
createInfo.pfnUserCallback = debugCallback;
createInfo.pUserData = nullptr;

auto func = (PFN_vkCreateDebugUtilsMessengerEXT) vkGetInstanceProcAddr(instance,
"vkCreateDebugUtilsMessengerEXT"); if (func == nullptr) throw Exception("Debug
extention not present");

if (func(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS)
    throw Exception("Debug extention cration fail");
}

void Instance::destroyDebugCallback() {
auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)
vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT"); if (func !=
nullptr) { func(instance, debugMessenger, nullptr);
}
}

VkBool32 Instance::debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT
messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const
VkDebugUtilsMessengerCallbackDataEXT *pCallbackData, void *pUserData) {
// throw Exception(std::string("validation layer Error : ") +
pCallbackData->pMessage);

std::cout << "validation layer: " << pCallbackData->pMessage << std::endl;

return VK_FALSE;
}

const std::vector<VkExtensionProperties> &Instance::getExtensions() const {
return extensions;
}

VkInstance Instance::getInstance() const {
return instance;
}
 */

Instance::Instance(const Blob::GLFW::Window &window) {
    if (enableValidationLayers && !checkValidationLayerSupport()) {
        throw std::runtime_error(
            "validation layers requested, but not available!");
    }

    {
        VkApplicationInfo appInfo = {};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = "BlobAttack";
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "BlobEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo = {};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        uint32_t count;
        const char **extensions = glfwGetRequiredInstanceExtensions(&count);

        memset(&createInfo, 0, sizeof(VkInstanceCreateInfo));
        createInfo.enabledExtensionCount = count;
        createInfo.ppEnabledExtensionNames = extensions;

        if (enableValidationLayers) {
            createInfo.enabledLayerCount = (uint32_t) validationLayers.size();
            createInfo.ppEnabledLayerNames = validationLayers.data();
        } else {
            createInfo.enabledLayerCount = 0;
        }

        if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
            throw std::runtime_error("failed to create instance!");
    }

    /// setupDebugCallback

    {
        if (!enableValidationLayers)
            return;

        VkDebugReportCallbackCreateInfoEXT createInfo = {};
        createInfo.sType =
            VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
        createInfo.flags =
            VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
        createInfo.pfnCallback = debugCallback;

        auto func = (PFN_vkCreateDebugReportCallbackEXT) vkGetInstanceProcAddr(
            instance,
            "vkCreateDebugReportCallbackEXT");
        if (func == nullptr)
            throw std::runtime_error(
                "failed to create debug callback function!");
        auto r = func(instance, &createInfo, nullptr, &debugReportCallbackEXT);
        if (r != VK_SUCCESS)
            throw std::runtime_error("failed to set up debug callback!");
    }
}

bool Instance::checkValidationLayerSupport() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

    std::vector<VkLayerProperties> availableLayers(layerCount);
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

    for (const char *layerName : validationLayers) {
        bool layerFound = false;

        for (const auto &layerProperties : availableLayers) {
            if (strcmp(layerName, layerProperties.layerName) == 0) {
                layerFound = true;
                break;
            }
        }

        if (!layerFound) {
            return false;
        }
    }

    return true;
}

VKAPI_ATTR VkBool32 VKAPI_CALL
Instance::debugCallback(VkDebugReportFlagsEXT flags,
                        VkDebugReportObjectTypeEXT objType,
                        uint64_t obj,
                        size_t location,
                        int32_t code,
                        const char *layerPrefix,
                        const char *msg,
                        void *userData) {
    // SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Vulkan Error", msg,
    // NULL);
    throw Exception(msg);
    return VK_FALSE;
}

Instance::~Instance() {
    auto func = (PFN_vkDestroyDebugReportCallbackEXT) vkGetInstanceProcAddr(
        instance,
        "vkDestroyDebugReportCallbackEXT");
    if (func != nullptr)
        func(instance, debugReportCallbackEXT, nullptr);

    vkDestroyInstance(instance, nullptr);
}
} // namespace Blob::VK