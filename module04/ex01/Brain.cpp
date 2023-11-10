#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor Called" << std::endl;
}
Brain::Brain(const Brain &copy)
{
    std::cout << "Brain Copy constructor Called" << std::endl;
    *this = copy;
}

Brain &Brain::operator=(const Brain &copy)
{
    std::cout << "Brain Copy operator Called" << std::endl;
    if (this != &copy)
    {
        for (size_t i = 0; i < 100; i++)
            this->ideas[i] = copy.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor Called" << std::endl;
}
