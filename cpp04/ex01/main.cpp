#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

int main()
{
	int arr_size = 4;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	Animal* animals[arr_size];

	for (int k = 0; k < (arr_size / 2); k++)
		animals[k] = new Dog();
	for (int k = (arr_size / 2); k < arr_size; k++)
		animals[k] = new Cat();
		std::cout << "--------------------------------------" << std::endl;
	for ( int k = 0; k < arr_size; k++)
		delete animals[k];

	delete j;	//should not create a leak
	delete i;

//test deep copy
	// Dog rex;
    // {
    //     Dog rex_copy = rex;
    // }
	return 0;
}



