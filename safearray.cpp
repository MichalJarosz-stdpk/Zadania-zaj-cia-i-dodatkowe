#include <iostream>
#include <string>
#include <stdexcept>


template <typename T, int size>
class SafeArray {
private:
    T data[size];

public:

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Blad: indeks poza zakresem!");
        }
        return data[index];
    }


    const T& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Blad: indeks poza zakresem (const)!");
        }
        return data[index];
    }


    int getSize() const {
        return size;
    }
};


int main() {
    SafeArray<std::string, 5> arr;

    try {

        arr[0] = "Czerwony";
        arr[1] = "Zielony";
        arr[2] = "Niebieski";

        std::cout << "Elementy tablicy:\n";
        for (int i = 0; i < arr.getSize(); i++) {
            std::cout << i << ": " << arr[i] << "\n";
        }

     
        std::cout << "\nProba dostepu do arr[-1]...\n";
        std::cout << arr[-1] << "\n"; 

    } catch (const std::out_of_range& e) {
        std::cout << "Zlapano wyjatek: " << e.what() << "\n";
    }

    try {
        std::cout << "\nProba dostepu do arr[10]...\n";
        std::cout << arr[10] << "\n"; 
    } catch (const std::out_of_range& e) {
        std::cout << "Zlapano wyjatek: " << e.what() << "\n";
    }

    return 0;
}