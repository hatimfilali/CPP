#include <iostream>
#include <stdlib.h>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal *animals[10];

    // copy Dog
    const Dog *puppy = new Dog();
    const Dog *puppy2 = new Dog(*puppy);
    std::cout << "puppy Brain Add > " << puppy->getBrain() << " puppy2 Brain Add > " << puppy2->getBrain() << std::endl;
    // Copy Cats
    const Cat *camel = new Cat();
    const Cat *batman = new Cat(*camel);
    std::cout << "camel Brain Add > " << camel->getBrain() << " batman Brain Add > " << batman->getBrain() << std::endl;

    for (int i = 0; i < 10; i++)
    {
        if (i < 5)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        animals[i]->makeSound();
    }
    for (int i = 0; i < 10; i++)
    {
        delete animals[i];
    }
    delete puppy;
    delete puppy2;
    delete camel;
    delete batman;
    return 0;
}