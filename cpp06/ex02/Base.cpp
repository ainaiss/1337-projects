#include "Base.hpp"

Base* generate(void)
{
    int x;
    Base *ptr[] = {new BaseA(), new BaseB(), new BaseC()};
    srand(time(0));
    x = rand() % 3 + 1;
    std::cout << "random number :" << x << std::endl;
    return ptr[x - 1];
}

void identify(Base* p)
{
    BaseA *pA = dynamic_cast<BaseA*>(p);
    BaseB *pB = dynamic_cast<BaseB*>(p);
    BaseC *pC = dynamic_cast<BaseC*>(p);
    
    if (pA == nullptr && pB == nullptr)
        std::cout << "C" << std::endl;
    else if (pA == nullptr && pC == nullptr)
        std::cout << "B" << std::endl;
    else if (pC == nullptr && pB == nullptr)
        std::cout << "A" << std::endl;
}

void identify(Base& p)
{
    BaseA refA;
    BaseB refB;
    BaseC refC;
    
    try {
        refC = dynamic_cast<BaseC&>(p);
        std::cout << "C" << std::endl;
    } catch(std::exception &e)
    {}
    
    try {
        refB = dynamic_cast<BaseB&>(p);
        std::cout << "B" << std::endl;
    }catch (std::exception &e)
    {}
    
    try {
        refA = dynamic_cast<BaseA&>(p);
        std::cout << "A" << std::endl;
    } catch (std::exception &e)
    {}
}
