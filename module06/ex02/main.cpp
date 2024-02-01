#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <string>
#include <iostream>

int Randomize(int i) {
    srand(time(NULL));
    return (rand() % i);
}

Base *generate(void) {
    Base *base;
    int index;

    Base *list[] = {new A(), new B(), new C()};
    index = Randomize(3);
    base = list[index];
    for (int i = 0; i < 3; i++)
    {
        if (i != index)
        {
            delete list[i];
        }
    }
    return base;
}

void identify(Base *p) {
    int type = 0;

    std::string typeList[] = {"Unknown", "A", "B", "C"};
    if (dynamic_cast<A*>(p) != NULL)
        type = 1;
    else if (dynamic_cast<B*>(p) != NULL)
        type = 2;
    else if (dynamic_cast<C*>(p) != NULL)
        type = 3;
    std::cout << "the object pointed by p is of type " << typeList[type] << std::endl;
}

void identify(Base &p) {
    Base b;
     try
    {
        b = dynamic_cast<A &>(p);
        std::cout << "passed arguments is instance of type : A" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        b = dynamic_cast<B &>(p);
        std::cout << "passed arguments is instance of type : B" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }

    try
    {
        b = dynamic_cast<C &>(p);
        std::cout << "passed arguments is instance of type : C" << std::endl;
        return;
    }
    catch (const std::exception &e)
    {
    }
    std::cout << "passed arguments has UnKnown type." << std::endl;
}

int main() {
    std::cout << "-----------Using Pointer--------" << std::endl;
    Base *b1 = NULL;
    b1 = generate();
    identify(b1);
    delete b1;
    std::cout << "----------Using Reference-------" << std::endl;
    Base *b2 = NULL;
    b2 = generate();
    identify(b2);
    delete b2;
}