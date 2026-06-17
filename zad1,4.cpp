#include <iostream>
#include <string>

class Employee{
private:
    const int id;
    std::string name;

    static int active_instances;

public:
    Employee(int i, std::string n) : id(i), name(n){
        active_instances++;
        std::cout << "Employee created -> ";
        print();
    }

    ~Employee(){
        std::cout << "Employee removed -> ";
        print();
        active_instances--;
    }

    void print() const{
        std::cout << "ID: " << id << " NAME: " << name << std::endl;
    }

    static int get_active_instances(){
        return active_instances;
    }
};

int Employee::active_instances = 0;

int main(){

    std::cout << "Active employees: "
              << Employee::get_active_instances() << std::endl;

    Employee e1(1,"Bob");
    Employee e2(2,"Alice");

    std::cout << "Active employees: "
              << Employee::get_active_instances() << std::endl;

    {
        Employee e3(3,"John");

        std::cout << "Active employees inside block: "
                  << Employee::get_active_instances() << std::endl;
    }

    std::cout << "Active employees after block: "
              << Employee::get_active_instances() << std::endl;

    return 0;
}