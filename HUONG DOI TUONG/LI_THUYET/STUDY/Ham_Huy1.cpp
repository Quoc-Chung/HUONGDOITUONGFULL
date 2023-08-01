#include <iostream>
#include <string>
using namespace std;
class Person {
public:
    string name;
    int age;

    // Constructor
    Person(string n, int a) : name(n), age(a) {
        cout << "Constructor for " << name << endl;
    }

    // Destructor
    ~Person() {
        cout << "Destructor for " << name << endl;
    }
};

int main() {
    Person person1("Alice", 30);
    Person person2("Bob", 25);
    // Hàm hủy được gọi khi  đối  tương thoát ra khỏi phạm vi hàm 
    return 0;
}
