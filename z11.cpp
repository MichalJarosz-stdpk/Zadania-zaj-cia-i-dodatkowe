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

    virtual ~Employee() {   
        std::cout << "Destruktor Employee\n";
    }
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
                  << " Name: " << name << std::endl;
    }

    double calculate_salary() const override final {
        return base_salary + bonus;
    }

    ~Manager() {
        std::cout << "Destruktor Manager\n";
    }
};

int main() {
    Employee* emp = new Manager("Jan Kowalski", 101, 5000.0, 1200.0);

    std::cout << emp->calculate_salary() << std::endl;

    delete emp;
    return 0;
}