
#include <iostream>
#include <string>
#include <vector>

class Employee {
    std::string name;

protected:
    virtual void print(std::ostream &os) const {
        os << "Employee: " << get_name() << std::endl;
    }

public:
    Employee(const std::string &name) : name(name) {}
    const std::string &get_name() const { return name; }
    friend std::ostream &operator<<(std::ostream &os, const Employee &e) {
        e.print(os);
        return os;
    }
};


class Manager : public Employee {
    Employee assistant;

protected:
    void print(std::ostream &os) const override {
        os << "Manager: " << get_name() << std::endl;
        os << "Assistant: " << std::endl << "\t" << get_assistant() << std::endl;
    }

public:
    Manager(const std::string &name, const Employee &assistant) : Employee(name), assistant(assistant) {}
    const Employee &get_assistant() const { return assistant; }
};


void f(const std::vector<Employee> &v) {
    for (const auto &e : v) {
        std::cout << e;
    }
}

int main() {
    Employee typist("Joe Smith");
    std::vector<Employee> v{typist, Employee("Bill Jones"), Manager("Jane Doe", typist)};
    f(v);
}