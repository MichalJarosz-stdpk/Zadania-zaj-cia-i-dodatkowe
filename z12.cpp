#include <iostream>
#include <vector>
#include <string>

class Employee {
public:
    virtual void display() const = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    void display() const override {
        std::cout << "Manager\n";
    }

    void scheduleMeeting() const {
        std::cout << "Manager schedules a meeting\n";
    }
};

class Developer : public Employee {
public:
    void display() const override {
        std::cout << "Developer\n";
    }
};

int main() {
    std::vector<Employee*> staff;

    staff.push_back(new Manager());
    staff.push_back(new Developer());

    for (auto e : staff) {
        e->display();

        Manager* m = dynamic_cast<Manager*>(e);

        if (m != nullptr) {
            m->scheduleMeeting();
        } else {
            std::cout << "To nie jest Manager\n";
        }
    }

    for (auto e : staff) delete e;
    return 0;
}