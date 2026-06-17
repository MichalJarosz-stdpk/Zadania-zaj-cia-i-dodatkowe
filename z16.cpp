#include <iostream>
#include <stdexcept>

double podziel(double licznik, double mianownik) {
    if (mianownik == 0) {
        throw std::invalid_argument("Nie mozna dzielic przez zero!");
    }
    return licznik / mianownik;
}

int main() {
    try {
        std::cout << "Wynik: " << podziel(10, 2) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Blad: " << e.what() << std::endl;
    }

    try {
        std::cout << "Wynik: " << podziel(10, 0) << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Blad: " << e.what() << std::endl;
    }

    return 0;
}