// TH3.2.Hãy định nghĩa một lớp Shape (Hình) trong đó dữ liệu là 2 cạnh (width, và height).
// Dẫn xuất từ lớp Hình hai lớp con là lớp Triangle (Hình tam giác) và lớp Rectangle (Hình chữ 
// nhật), trong mỗi lớp có phương thức tính diện tích area(). 
// Trong hàm main() khai báo hai biến đối tượng của lớp Triangle và lớp Rectangle, sau đó gọi 
// hàm area() để tính diện tích mỗi hình. 
// Yêu cầu: Viết hai phiên bản cho hai trường hợp: 
// 1 Dữ liệu của Shape là protected, dùng hàm thành phần để nhập dữ liệu.
// 2 Dữ liệu của Shape là private, dùng hàm tạo có đối để khởi tạo dữ liệu.
#include<bits/stdc++.h>
using namespace std;
class Shape{
    protected:
       int width;
       int height;
    public :
       /* - Khởi tạo không đối số - */
       Shape() : width(0) ,height(0) {}

       void Nhap(){
        cout<<"\nNhap chieu rong:";
        cin >> width;
        cout<<"\nNhap chieu cao:";
        cin >> height;
       }
       /* - Tí chúng ta sẽ định nghĩa lại -*/
       virtual int Area(){
          return 0;
       }
};

class Triangle : public Shape{
    public :
      int Area() override{
          return  width * height;
      } 
};

class Rectangle : public Shape{
    public :
       int Area() override{
           return 0.5 * width *height;
       }
};

int main(){
    Triangle hcn;
    hcn.Nhap();
    int area_hcn = hcn.Area();
    cout<<"Dien tich hinh chu nhat la :"<< area_hcn <<endl;

    Rectangle tam_giac;
    tam_giac.Nhap();
    int area_tg = tam_giac.Area();
    cout<<"Dien tich tam giac la :"<< area_tg <<endl;

    return 0;
}