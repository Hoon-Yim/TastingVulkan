#pragma once

#include "VeWindow.h"
#include "VeDevice.h"

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

    public:
        void Run();
    };
}