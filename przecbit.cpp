#include <iostream>

class Vector2D {
private:
    double x;
    double y;

public:

    Vector2D(double xValue = 0.0, double yValue = 0.0) {
        x = xValue;
        y = yValue;
    }


    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }


    void display() const {
        std::cout << "[" << x << ", " << y << "]" << std::endl;
    }
};

int main() {

    Vector2D v1(5.0, 3.0);
    Vector2D v2(2.0, 1.0);


    Vector2D suma = v1 + v2;


    Vector2D roznica = v1 - v2;

    std::cout << "Wektor v1: ";
    v1.display();

    std::cout << "Wektor v2: ";
    v2.display();

    std::cout << "Suma v1 + v2: ";
    suma.display();

    std::cout << "Roznica v1 - v2: ";
    roznica.display();

    return 0;
}