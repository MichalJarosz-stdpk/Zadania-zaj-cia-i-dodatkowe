#include <iostream>
#include <string>


template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    T getValue() const {
        return value;
    }
};


template <>
class Box<bool> {
private:
    bool value;

public:
    Box(bool v) : value(v) {}

    bool getValue() const {
        return value;
    }

    std::string getStatus() const {
        if (value)
            return "TAK";
        else
            return "NIE";
    }
};

int main() {

    Box<int> intBox(123);

    std::cout << "Wartosc intBox: "
              << intBox.getValue() << std::endl;

    
    Box<bool> boolBox1(true);
    Box<bool> boolBox2(false);

    std::cout << "boolBox1: "
              << boolBox1.getStatus() << std::endl;

    std::cout << "boolBox2: "
              << boolBox2.getStatus() << std::endl;

    return 0;
}