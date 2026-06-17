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


    bool operator==(const Vector2D& other) const {
        return (x == other.x) && (y == other.y);
    }


    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }


    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec);
};


std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    os << "(" << vec.x << ", " << vec.y << ")";
    return os;
}

int main() {
    Vector2D v1(3.0, 4.0);
    Vector2D v2(1.0, 2.0);


    Vector2D suma = v1 + v2;
    Vector2D roznica = v1 - v2;


    std::cout << "v1 = " << v1 << std::endl;
    std::cout << "v2 = " << v2 << std::endl;

    std::cout << v1 << " + " << v2
              << " = " << suma << std::endl;

    std::cout << v1 << " - " << v2
              << " = " << roznica << std::endl;


    std::cout << std::boolalpha;

    std::cout << "Czy v1 == v2? "
              << (v1 == v2) << std::endl;

    std::cout << "Czy v1 != v2? "
              << (v1 != v2) << std::endl;

    return 0;
}