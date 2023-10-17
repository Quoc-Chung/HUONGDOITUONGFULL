// TH3.2. Hãy định nghĩa một lớp Shape (Hình) trong đó dữ liệu là 2 cạnh (width, và height). 
// Dẫn xuất từ lớp Hình hai lớp con là lớp Triangle (Hình tam giác) và lớp Rectangle (Hình chữ 
// nhật), trong mỗi lớp có phương thức tính diện tích area(). Trong hàm main() khai báo hai biến 
// đối tượng của lớp Triangle và lớp Rectangle, sau đó gọi hàm area() để tính diện tích mỗi hình. 
// Yêu cầu: Viết hai phiên bản cho hai trường hợp: 
// 1) Dữ liệu của Shape là protected, dùng hàm thành phần để nhập dữ liệu.
// 2) Dữ liệu của Shape là private, dùng hàm tạo có đối để khởi tạo dữ liệu
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class Shape{
private:
    float width;
    float height;
public:
    Shape(float w, float h) : width(w), height(h) {}
    float area() {
        return 0.0; 
    }
    float getWidth() {
        return width;
    }
    float getHeight() {
        return height;
    }
};


class Triangle : public Shape {
public:
    Triangle(float w, float h) : Shape(w,h) {}
    float area() {
        return 0.5 * getWidth() * getHeight();
    }
};
class Rectangle : public Shape {
public:
    Rectangle(float w, float h) : Shape(w, h) {}
    float area() {
        return getWidth() * getHeight();
    }
};
int main() {
    Triangle triangle(5.0, 4.0);
    Rectangle rectangle(6.0, 3.0);
    cout << "Dien tich tam giac : " << triangle.area() << endl;
    cout << "Dien tich hinh chu nhat: " << rectangle.area() <<endl;
    return 0;
}


