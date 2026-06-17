#include <iostream>
#include <string>

class Employee {
protected:   
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}

    void display() {
        std::cout << "Employee ID: " << id << " Name: " << name << std::endl;
    }
};

class Manager : public Employee {
private:
    float bonus_percentage;

public:
    Manager(std::string n, int i, float bonus)
        : Employee(n, i), bonus_percentage(bonus) {}

    void display() {
        std::cout << "Manager ID: " << id << " Name: " << name
                  << " Bonus: " << bonus_percentage << "%"
                  << std::endl;
    }
};

int main() {

    Manager mgr("Adam", 101, 20.0);

    mgr.display();

    

    return 0;
}