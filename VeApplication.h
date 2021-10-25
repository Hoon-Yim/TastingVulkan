#pragma once

#include "VeDevice.h"
#include "VeSwapChain.h"
#include "VeWindow.h"

namespace ve
{
    class VeApplication
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

    private:
        VeWindow window {WIDTH, HEIGHT, "TastingVulkan"};
        VeDevice device{window};
        VeSwapChain swapChain{device, window.GetExtent()};

    public:
        void Run();
    };
}