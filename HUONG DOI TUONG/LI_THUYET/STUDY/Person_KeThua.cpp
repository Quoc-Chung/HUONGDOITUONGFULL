#include <iostream>
#include <string>

using namespace std;

// Lớp cơ sở (base class)
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) {
        this->name = name;
        this->age = age;
    }
    string getName() const {
        return name;
    }
    void display() {
        cout<<"\nStudent :"<<endl;
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Lớp dẫn xuất (derived class) kế thừa từ lớp Person
class Student : public Person {
private:
    string Nganh;

public:
    Student(const string& name, int age, const string& Nganh) : Person(name, age), Nganh(Nganh) {}

    void displayStudent() {
        cout << "Name: " << name << ", Age: " << age << ", Nganh: " << Nganh << endl;
    }
};

int main() {
    // Tạo một đối tượng của lớp cơ sở
    Person person("John", 25);

    // Tạo một đối tượng của lớp dẫn xuất
    Student student("Alice", 20, "Computer Science");

    // Gọi phương thức display của lớp cơ sở
    cout << "Person: ";
    person.display();
    student.display();

    // Gọi phương thức display của lớp dẫn xuất
    cout << "Student: ";
    student.displayStudent();

    // Các thành viên được kế thừa từ lớp cơ sở vẫn có thể truy cập từ lớp dẫn xuất
    cout << "Student's name (from base class): " << student.getName() << endl;

    return 0;
}
