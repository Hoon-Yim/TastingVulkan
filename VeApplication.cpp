#include "VeApplication.h"

namespace ve
{
    void VeApplication::Run()
    {
        while(!window.ShouldClose())
        {
            glfwPollEvents();
        }
    }
}
