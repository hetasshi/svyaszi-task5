#include <iostream>
#include <vector>
#include <string>

class Manager;

class Programmer {
private:
    std::string name;
    Manager* manager; 

public:
    Programmer(const std::string& name) : name(name), manager(nullptr) {}

    void setManager(Manager* mgr) {
        manager = mgr;
    }

    std::string getName() const {
        return name;
    }

    Manager* getManager() const {
        return manager;
    }
};

class Manager {
private:
    std::string name; 
    std::vector<Programmer*> programmers; 

public:
    Manager(const std::string& name) : name(name) {}

    void addProgrammer(Programmer* programmer) {
        programmers.push_back(programmer);
        programmer->setManager(this); 
    }

    void listProgrammers() const {
        std::cout << "Менеджер " << name << " контролит программистов:" << std::endl;
        for (const auto& programmer : programmers) {
            std::cout << "- " << programmer->getName() << std::endl;
        }
    }

    std::string getName() const {
        return name;
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Manager manager("Артёмка Манагер");

    Programmer programmer1("Курдя Шагаловна");
    Programmer programmer2("Макан Реперов");
    Programmer programmer3("Диджей сосиска");

    manager.addProgrammer(&programmer1);
    manager.addProgrammer(&programmer2);
    manager.addProgrammer(&programmer3);

    manager.listProgrammers();

    std::cout << "Менеджер программиста " << programmer1.getName() << " - "
        << programmer1.getManager()->getName() << std::endl;

    return 0;
}
