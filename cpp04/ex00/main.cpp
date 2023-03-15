#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {   
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << "----------------------------------" << std::endl;
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        std::cout << "----------------------------------" << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        std::cout << "----------------------------------" << std::endl;
		delete i;
		delete j;
		delete meta;
	}
    std::cout << "----------------------------------" << std::endl;
	{
		const WrongAnimal *a = new WrongAnimal();
		const WrongAnimal *b = new WrongCat();
		std::cout << "----------------------------------" << std::endl;
		std::cout << a->getType() << " " << std::endl;
		std::cout << b->getType() << " " << std::endl;
		std::cout << "----------------------------------" << std::endl;
		a->makeSound();
		b->makeSound();
		std::cout << "----------------------------------" << std::endl;
		delete a;
		delete b;
	}
}


