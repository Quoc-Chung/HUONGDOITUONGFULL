#include<bits/stdc++.h>
using namespace std;
class Shape{
    private:
       int width;
       int height;
    public :
       /* - Khởi tạo không đối số - */
       Shape() : width(0) ,height(0) {}
       /* - Khởi tạo có đối số - */
       Shape(int width, int height) : width(width) ,height(height) {}

       int getWidth(){
           return width;
       }
       int getHeight(){
           return height;
       }
       /* - Tí chúng ta sẽ định nghĩa lại -*/
       virtual int Area(){
          return 0;
       }
};

class Triangle : public Shape{
    public :
     /* - Khởi tạo có đối số truyền vào hàm khởi tạo lớp Shape - */
      Triangle(int width_Tr,int height_Tr) : Shape(width_Tr, height_Tr) {}
      int Area() override{
          return getWidth() * getHeight();
      } 
};

class Rectangle : public Shape{
    public :
     /* - Khởi tạo có đối số truyền vào hàm khởi tạo lớp Shape - */
       Rectangle(int width_Rec,int height_Rec) : Shape(width_Rec, height_Rec) {}
       int Area() override { 
           return 0.5* getWidth() * getHeight();
       }
};

int main(){
    Triangle hcn(2,7);
    int area_hcn = hcn.Area();
    cout<<"Dien tich hinh chu nhat la :"<< area_hcn <<endl;
    Rectangle tam_giac(3,4);
    int area_tg = tam_giac.Area();
    cout<<"Dien tich tam giac la :"<< area_tg <<endl;

    return 0;
}