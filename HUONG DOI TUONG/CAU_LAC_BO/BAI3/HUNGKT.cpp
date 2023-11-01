#include<bits/stdc++.h>
using namespace std;
class Triangle {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    friend istream& operator>>(istream& is, Triangle &t){
        cout << "Nhập độ dài 3 cạnh tam giác: ";
        is >> t.side1 >> t.side2 >> t.side3;
        return is;
    }
    
    double calculateArea() {   
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() {
        return side1 + side2 + side3;
    }
    double getSide1(){
        return side1;
    }
    double getSide2(){
        return side2;
    }
    double getSide3(){
        return side3;
    }

    bool isTriangleValid() {
        return (side1 + side2 > side3) && (side1 + side3 > side2) && (side2 + side3 > side1);
    }
};

bool compareTriangles( Triangle& t1,  Triangle& t2) {
    return t1.calculateArea() > t2.calculateArea();
}

int main() {
    vector<Triangle> triangles;

    // Nhập danh sách các tam giác
    int n;
    cout << "Nhập số lượng tam giác: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Triangle triangle(0, 0, 0);
        cin >> triangle;
        if (triangle.isTriangleValid()) {
            triangles.push_back(triangle);
        } else {
            cout << "Tam giác không hợp lệ. Vui lòng nhập lại." << endl;
            i--; // Decrement to allow re-entry for an invalid triangle
        }
    }

    // Sắp xếp các tam giác theo diện tích giảm dần
    sort(triangles.begin(), triangles.end(), compareTriangles);

    // Tính trung bình cộng chu vi của các tam giác có diện tích dưới 1000
    double totalPerimeter = 0;
    int count = 0;

    for ( Triangle& triangle : triangles) {
        double area = triangle.calculateArea();
        if (area < 1000) {
            totalPerimeter += triangle.calculatePerimeter();
            count++;
        } else {
            break; // Vì tam giác đã được sắp xếp theo diện tích giảm dần
        }
    }

    double averagePerimeter = totalPerimeter / count;

    // In các tam giác theo diện tích giảm dần
    cout << "Danh sách tam giác theo diện tích giảm dần:" << endl;
    for ( Triangle& triangle : triangles) {
        cout << "Tam giác có độ dài cạnh: " << triangle.getSide1() << ", " << triangle.getSide2() << ", " << triangle.getSide3() << ", Diện tích: " << triangle.calculateArea() << endl;
    }

    // In trung bình cộng chu vi các tam giác có diện tích dưới 1000
    cout << "Trung bình cộng chu vi các tam giác có diện tích dưới 1000: " << averagePerimeter << endl;

    return 0;
}
