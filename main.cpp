#include <iostream>
#include <cstdlib>

#include "VeApplication.h"

int main()
{
    ve::VeApplication application;

    try
    {
        application.Run();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}