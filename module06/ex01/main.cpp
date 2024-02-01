#include "Serializer.hpp"

class Data {
    private:
        int value;
    public: 
        int getValue() {
            return (this->value);
        };
        void setValue(int value) {
            this->value = value;
        };
};

int main () {
    Data *data1 = new Data();

    data1->setValue(120);

    std::cout << "The adress of the Data is " << data1  << " And its value is " << data1->getValue() << std::endl;

    uintptr_t ptr = Serializer::Serialize(data1);
    std::cout << "The data has been serialized" << std::endl;
    
    data1 = Serializer::Deserialize(ptr);

    std::cout << "The data has been deserialized" << std::endl;

    std::cout << "the adress of the Data after Serialization process is " << data1  << " And its value is " << data1->getValue() << std::endl;
}