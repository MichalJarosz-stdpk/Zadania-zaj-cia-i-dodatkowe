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


    bool operator==(const Vector2D& other) const {
        return (x == other.x) && (y == other.y);
    }


    bool operator!=(const Vector2D& other) const {
        return !(*this == other);
    }

 
    void display() const {
        std::cout << "[" << x << ", " << y << "]" << std::endl;
    }
};

int main() {
    
    Vector2D v1(3.0, 4.0);
    Vector2D v2(3.0, 4.0);
    Vector2D v3(1.0, 2.0);


    std::cout << "v1 = ";
    v1.display();

    std::cout << "v2 = ";
    v2.display();

    std::cout << "v3 = ";
    v3.display();


    std::cout << std::boolalpha;

    
    std::cout << "\nCzy v1 == v2? " << (v1 == v2) << std::endl;
    std::cout << "Czy v1 == v3? " << (v1 == v3) << std::endl;

 
    std::cout << "Czy v1 != v2? " << (v1 != v2) << std::endl;
    std::cout << "Czy v1 != v3? " << (v1 != v3) << std::endl;

    return 0;
}