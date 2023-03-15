#include "Convert.hpp"

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        Convert c;
        c.defineType(argv[1]);
        c.convert(argv[1]);
        c.printConverted();
    }
    else 
        std::cout << "Error Argument!!" << std::endl;
    return (0);
}

