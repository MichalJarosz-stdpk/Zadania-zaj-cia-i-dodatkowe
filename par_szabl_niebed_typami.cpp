#include <iostream>

template <typename T, int size>
class StaticArray {
private:
    T data[size];

public:
    int getSize() const {
        return size;
    }

    void set(int index, T value) {
        data[index] = value;
    }

    T get(int index) const {
        return data[index];
    }
};

int main() {

    StaticArray<int, 5> intArray;

    StaticArray<double, 10> doubleArray;


    std::cout << "Rozmiar intArray: "
              << intArray.getSize() << std::endl;

    std::cout << "Rozmiar doubleArray: "
              << doubleArray.getSize() << std::endl;


    intArray.set(0, 100);
    intArray.set(1, 200);

    doubleArray.set(0, 3.14);
    doubleArray.set(1, 2.71);

    
    std::cout << "intArray[0] = "
              << intArray.get(0) << std::endl;

    std::cout << "intArray[1] = "
              << intArray.get(1) << std::endl;

    std::cout << "doubleArray[0] = "
              << doubleArray.get(0) << std::endl;

    std::cout << "doubleArray[1] = "
              << doubleArray.get(1) << std::endl;

    return 0;
}