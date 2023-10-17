#include<bits/stdc++.h>
using namespace std;

class Shape {
    public:
        /* - Sử dụng hàm thuần ảo chưa được định nghĩa kiểu gì - */
        virtual double area() = 0; 
};

class Circle : public Shape {
    private:
        double radius;
    public:
    /* - Khởi tạo đối số truyền vào - */
        Circle(double r) : radius(r) {}
        /* - Định nghĩa lại hàm area - */
        double area() override {
            return 3.14159 * radius * radius;
        }
};

class Rectangle : public Shape {
    private:
        double length;
        double width;
    public:
    /* - Khởi tạo có đối số truyền vào  - */
        Rectangle(double l, double w) : length(l), width(w) {}

        double area() override {
            return length * width;
        }
};

int main() {
    Shape  *myShape = new Circle(5.0);
    cout << "Area of Circle: " << myShape->area() << endl;

    myShape = new Rectangle(4.0, 6.0);
    cout << "Area of Rectangle: " << myShape->area() << endl;

    delete myShape;
    return 0;
}