#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    int priority;

    Task(std::string d, int p) : description(d), priority(p) {}
};

class Employee {
protected:
    std::string name;
    std::vector<Task> tasks;

public:
    Employee(std::string n) : name(n) {}

    void assignTask(const std::string& desc, int prio) {
        tasks.emplace_back(desc, prio);
    }

    virtual void display() const {
        std::cout << "Employee: " << name << "\nTasks:\n";
        for (const auto& t : tasks) {
            std::cout << "- " << t.description
                      << " (priority: " << t.priority << ")\n";
        }
    }
};

class Manager : public Employee {
public:
    Manager(std::string n) : Employee(n) {}

    void display() const override {
        std::cout << "Manager: " << name << "\n";
        Employee::display();
    }
};

class Developer : public Employee {
public:
    Developer(std::string n) : Employee(n) {}

    void display() const override {
        std::cout << "Developer: " << name << "\n";
        Employee::display();
    }
};

int main() {
    Manager m("Jan");
    Developer d("Anna");

    m.assignTask("Prepare report", 1);
    d.assignTask("Fix bug", 2);

    m.display();
    std::cout << "\n";
    d.display();

    return 0;
}