#include <iostream>
#include <string>


class IReportable {
public:
    virtual std::string getReport() const = 0;
    virtual ~IReportable() {}
};


class Employee : public IReportable {
protected:
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}
};


class Manager : public Employee {
    double salary;

public:
    Manager(std::string n, int i, double s)
        : Employee(n, i), salary(s) {}

    std::string getReport() const override {
        return "Manager: " + name + ", ID: " + std::to_string(id) +
               ", Salary: " + std::to_string(salary);
    }
};


class Developer : public Employee {
    std::string language;

public:
    Developer(std::string n, int i, std::string lang)
        : Employee(n, i), language(lang) {}

    std::string getReport() const override {
        return "Developer: " + name + ", ID: " + std::to_string(id) +
               ", Language: " + language;
    }
};


void printReport(const IReportable& obj) {
    std::cout << obj.getReport() << std::endl;
}

int main() {
    Manager m("Jan", 1, 8000);
    Developer d("Anna", 2, "C++");

    printReport(m);
    printReport(d);

    return 0;
}