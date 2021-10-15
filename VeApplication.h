#pragma once

#include "VeWindow.h"

namespace ve
{
    class VeApplication
    {
    public:
        static constexpr int WIDTH = 800;
        static constexpr int HEIGHT = 600;

    private:
        VeWindow window {WIDTH, HEIGHT, "Triangle"};

    public:
        void Run();
    };
}