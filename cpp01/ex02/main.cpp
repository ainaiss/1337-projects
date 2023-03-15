#include <iostream>
#define string std::string

int main()
{
    string str = "HI THIS IS BRAIN";
    string *stringPTR = &str;
    string &stringREF = str;

    std::cout << "memory address of the string variable \n" << &str << std::endl;
    std::cout << "memory address held by stringPTR \n" << stringPTR << std::endl;
    std::cout << "memory address held by stringREF \n" << &stringREF << std::endl;

    std::cout << "----------------------" << std::endl;

    std::cout << "value of the string variable \n" << str << std::endl;
    std::cout << "The value pointed to by stringPTR \n" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF\n" << stringREF << std::endl;
}