#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}

    void display() {
        std::cout << "Employee ID: " << id  << " Name: " << name << std::endl;
    }
};

class Manager : public Employee {
private:
    float bonus_percentage;

public:
    Manager(std::string n, int i, float b)
        : Employee(n, i), bonus_percentage(b) {}

    void display() {
        std::cout << "Manager ID: " << id
                  << " Name: " << name
                  << " Bonus: " << bonus_percentage << "%"
                  << std::endl;
    }
};

int main() {

    Employee* staff[2];  

    staff[0] = new Employee("Bob", 1);
    staff[1] = new Manager("Adam", 2, 25.0);

    for(int i = 0; i < 2; i++) {
        staff[i]->display();
    }

    for(int i = 0; i < 2; i++) {
        delete staff[i];
    }

    return 0;
}