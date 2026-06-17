#include <iostream>
#include <stdexcept>
#include <type_traits>


template <typename T>
class SimpleContainer {
private:
    T value;

public:
    SimpleContainer(T v = T{}) : value(v) {}


    T getValue() const noexcept {
        return value;
    }


    void checkAndSet(T val) {
        if constexpr (std::is_same_v<T, int>) {
            if (val < 0) {
                throw std::out_of_range("Wartosc nie moze byc ujemna (int)");
            }
        }
        value = val;
    }
};


template <typename T>
void safe_call(T obj) {

    if constexpr (noexcept(obj.getValue())) {
        std::cout << "[SAFE] getValue() nie rzuca wyjatkow\n";
    } else {
        std::cout << "[UNSAFE] getValue() moze rzucic wyjatek\n";
    }


    std::cout << "Wartosc: " << obj.getValue() << "\n";
}


int main() {
    SimpleContainer<int> a(10);
    SimpleContainer<int> b;

    std::cout << "Sprawdzenie noexcept (kompilacyjnie):\n";
    std::cout << std::boolalpha;
    std::cout << "getValue(): "
              << noexcept(a.getValue()) << "\n";

    std::cout << "checkAndSet(-5): "
              << noexcept(a.checkAndSet(-5)) << "\n";

    std::cout << "\n--- safe_call ---\n";

    safe_call(a);

    try {
        b.checkAndSet(-10); 
    } catch (const std::exception& e) {
        std::cout << "Zlapano wyjatek: " << e.what() << "\n";
    }

    return 0;
}