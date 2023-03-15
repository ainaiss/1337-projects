#include "Base.hpp"
#include <cstdlib>

int main()
{
    Base *pointer;
    Base *reference;

    pointer = generate();
    identify(pointer);  
    reference = generate();
    identify(*reference);
    
    return (0);
}