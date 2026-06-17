#include <iostream>
#include <string>

class Employee{
private:
    std:: string name;
    int id;
public:
    Employee(std::string n, int i) : name(n), id(i) {}

void display(){
    std::cout << "Employee ID: " << id  << " Name: " << name << std::endl;
 }
};
class Manager : public Employee{
private:
    float bonus_percentage;
public:
    Manager(std::string n, int i, float bonus) : Employee(n, i), bonus_percentage(bonus){}
void display(){
    Employee::display();
    std::cout << "Bonus: " << bonus_percentage  << " % " << std::endl;
 }
};
int main(){
    Manager m1("Adam",101, 14.6);
    m1.display();

    return 0 ;
}