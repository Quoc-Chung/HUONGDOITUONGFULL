#include<bits/stdc++.h>
using namespace std;

class MyClass1
{
private:
    int Doi_Tuong_1;

public:
// Hàm khởi tạo 
    MyClass1(int Doi_Tuong_1)
    {
        this->Doi_Tuong_1=Doi_Tuong_1;
    }
  // Khai báo lớp bạn 
   friend class MyClass2;

};

class MyClass2
{
private:
    int Doi_Tuong_2;
public:
    MyClass2(int Doi_Tuong_2) // constructor
    {
        this->Doi_Tuong_2=Doi_Tuong_2;
    }
  //Ta đang muốn truy cập vào thành phần của đối tượng 1 
    void myMethod(MyClass1 mClass)
    {
        cout << mClass.Doi_Tuong_1; // Không hợp lệ do chưa là bạn : friend class MyClass2;
    }
};
int main()
{
    MyClass1 mClass1(2409);
    MyClass2 mClass2(2001);
    mClass2.myMethod(mClass1); // in ra màn hình 2409
    return 0;
}