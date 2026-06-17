#include <iostream>
#include <string>
#include <utility> 


template <typename T>
class Box {
private:
    T value;

public:
  
    Box(T val) : value(std::move(val)) {}


    T getValue() const {
        return value;
    }

 
    void setValue(T newValue) {
        value = std::move(newValue);
    }
};

int main() {

    Box<int> intBox(10);

    std::cout << "Wartosc intBox: "
              << intBox.getValue() << std::endl;

    intBox.setValue(25);

    std::cout << "Nowa wartosc intBox: "
              << intBox.getValue() << std::endl;

    std::cout << std::endl;

 
    Box<std::string> stringBox("Hello");

    std::cout << "Wartosc stringBox: "
              << stringBox.getValue() << std::endl;

    stringBox.setValue("World");

    std::cout << "Nowa wartosc stringBox: "
              << stringBox.getValue() << std::endl;

    return 0;
}