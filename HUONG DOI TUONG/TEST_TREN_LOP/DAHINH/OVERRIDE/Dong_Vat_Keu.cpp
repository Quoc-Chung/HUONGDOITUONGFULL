#include <bits/stdc++.h>
using namespace std;

class Animal{
public:
    /* - Hiện tại nếu không có từ virtual thì sẽ không cho phép việc ghi đè - */
    virtual void sound() {
        cout << "Dong vat tao ra tieng keu." << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Cho sua ." << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meo keu meo meo." << endl;
    }
};

int main() {
   /* -Khai báo một con trỏ kiểu Animal trỏ đến đối tượng của lớp Dog -  */
    Animal* myAnimal = new Dog();

    myAnimal->sound(); // Output: "Dog barks."

    myAnimal = new Cat();
    myAnimal->sound(); // Output: "Cat meows."

    delete myAnimal;
    return 0;
}
/*
- Khai báo Animal* myAnimal = new Dog(); trong C++ là một cách tạo một con trỏ có kiểu Animal và
gán cho nó một địa chỉ của một đối tượng có kiểu là Dog.

- Animal*: Đây là kiểu dữ liệu của con trỏ. Điều này có nghĩa là myAnimal là một con trỏ đến một 
đối tượng thuộc kiểu Animal.

- myAnimal: Đây là tên của con trỏ. Chúng ta đặt tên cho con trỏ này để tham chiếu đến đối tượng.

- new Dog(): Đây là phần chúng ta cấp phát bộ nhớ động để tạo một đối tượng thuộc kiểu Dog.
Toán tử new được sử dụng để cấp phát bộ nhớ động , sau đó gọi constructor của lớp Dog để khởi tạo
đối tượng. Kết quả của phép cấp phát này là một con trỏ đến đối tượng vừa được tạo.

- Tóm lại, dòng này tạo một con trỏ có kiểu Animal (Animal*) và gán cho nó một con trỏ đến một
 đối tượng thuộc kiểu Dog. Điều này cho phép bạn sử dụng con trỏ myAnimal để truy cập các thành
viên và phương thức của lớp Animal, và nếu lớp Dog có các phương thức ghi đè (override) từ lớp
Animal, thì con trỏ này cũng có thể trỏ đến các phương thức của lớp Dog.
*/