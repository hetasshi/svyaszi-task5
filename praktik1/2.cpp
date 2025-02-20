#include <iostream>
#include <vector>
#include <string>


class Student {
private:
    std::string name;

public:
    Student(const std::string& name) : name(name) {}

    std::string getName() const {
        return name;
    }
};

class University {
private:
    std::vector<Student*> students;

public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void listStudents() const {
        std::cout << "Список студентов в университете:" << std::endl;
        for (const auto& student : students) {
            std::cout << "- " << student->getName() << std::endl;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    Student student1("Боба Тоба");
    Student student2("Герасим В штаны накакил");
    Student student3("Мистер бист");

    University university;

    university.addStudent(&student1);
    university.addStudent(&student2);
    university.addStudent(&student3);

    university.listStudents();

    return 0;
}
