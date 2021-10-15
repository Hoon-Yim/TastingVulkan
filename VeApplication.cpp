#include "VeApplication.h"

void ve::VeApplication::Run()
{
    while(!window.ShouldClose())
    {
        glfwPollEvents();
    }
}
