#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

class Data;
class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &copy);

public:
    Serializer &operator=(const Serializer &copy);
    ~Serializer();

    static uintptr_t Serialize(Data *ptr);
    static Data *Deserialize(uintptr_t raw);
};


#endif