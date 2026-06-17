#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}

    virtual void display() const = 0;
    virtual double calculate_salary() const = 0;

    virtual ~Employee() = default;
};

class Manager : public Employee {
private:
    double base_salary;
    double bonus;

public:
    Manager(std::string n, int i, double salary, double b)
        : Employee(n, i), base_salary(salary), bonus(b) {}

    void display() const override {
        std::cout << "Manager ID: " << id
                  << " Name: " << name
                  << std::endl;
    }

    double calculate_salary() const override {
        return base_salary + bonus;
    }
};

int main() {

    Manager m("Adam", 101, 5000, 1200);

    m.display();
    std::cout << "Salary: " << m.calculate_salary() << std::endl;

    return 0;
}