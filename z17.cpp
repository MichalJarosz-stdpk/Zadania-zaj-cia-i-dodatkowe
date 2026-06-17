#include <iostream>
#include <stdexcept>

class EmployeeException : public std::runtime_error {
public:
    EmployeeException(const std::string& msg)
        : std::runtime_error(msg) {}
};

class InvalidSalaryException : public EmployeeException {
public:
    InvalidSalaryException(const std::string& msg)
        : EmployeeException(msg) {}
};

class Manager {
    double salary;

public:
    Manager(double s) {
        if (s < 4000) {
            throw InvalidSalaryException("Pensja ponizej minimum!");
        }
        salary = s;
    }
};

int main() {
    try {
        Manager m(3000);
    }
    catch (const InvalidSalaryException& e) {
        std::cout << "InvalidSalaryException: " << e.what() << std::endl;
    }
    catch (const EmployeeException& e) {
        std::cout << "EmployeeException: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "std::exception: " << e.what() << std::endl;
    }

    return 0;
}