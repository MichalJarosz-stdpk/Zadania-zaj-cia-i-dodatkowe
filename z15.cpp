#include <iostream>
#include <string>

template <typename T>
T znajdzWiekszy(T a, T b) {
    return (a > b) ? a : b;
}

class Employee {
    int id;
public:
    Employee(int i) : id(i) {}

    bool operator>(const Employee& other) const {
        return id > other.id;
    }

    void display() const {
        std::cout << "Employee ID: " << id << std::endl;
    }
};

int main() {
    std::cout << znajdzWiekszy(3, 7) << std::endl;
    std::cout << znajdzWiekszy(3.5, 2.1) << std::endl;
    std::cout << znajdzWiekszy(std::string("Ala"), std::string("Zosia")) << std::endl;

    Employee e1(1), e2(5);
    Employee bigger = znajdzWiekszy(e1, e2);
    bigger.display();

    return 0;
}