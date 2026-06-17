#include <iostream>
#include <string>
#include <utility>

template <typename T>
class Box {
private:
    T value;

public:

    Box(T val);


    T getValue() const;


    void setValue(T newValue);
};


template <typename T>
Box<T>::Box(T val) : value(std::move(val)) {}


template <typename T>
T Box<T>::getValue() const {
    return value;
}


template <typename T>
void Box<T>::setValue(T newValue) {
    value = std::move(newValue);
}

int main() {

    Box<int> intBox(100);

    std::cout << "Wartosc intBox: "
              << intBox.getValue() << std::endl;

    intBox.setValue(250);

    std::cout << "Nowa wartosc intBox: "
              << intBox.getValue() << std::endl;

    std::cout << std::endl;


    Box<std::string> stringBox("C++");

    std::cout << "Wartosc stringBox: "
              << stringBox.getValue() << std::endl;

    stringBox.setValue("Szablony");

    std::cout << "Nowa wartosc stringBox: "
              << stringBox.getValue() << std::endl;

    return 0;
}