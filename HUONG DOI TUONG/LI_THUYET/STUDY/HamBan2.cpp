#include<bits/stdc++.h>
using namespace std;
// dùng  để tăng  số  thứ tự rất  hợp lí
class SinhVien1{
 private :
 // 4 Thuộc tính 
    string id,ten,ns;
    double gpa;
 public :
 // 2 Phuong thức 
    SinhVien1()= default;// contructor 
    SinhVien1 (string,string,string ,double);
    void Nhap();
    void In();

    friend void Truy_Cap_Private(SinhVien1);
   
};
void Truy_Cap_Private(SinhVien1 x){
    cout <<x.id<<" "<<x.ten<<" "<<x.ns<<" "<<fixed<<setprecision(2)<<x.gpa<<endl;
}
/*
- Chúng ta thấy ở đây có một hàm đang cố gắng truy cập vào  các thành phần private 
của lớp SinhVien1 .
- Điều nay sẽ dẫn đến sai.
- Khi khai báo hàm bạn thì chúng ta  hay khai báo tham chiếu là  lớp  mà chúng ta muốn
truy cập thành phần private 
- Một ví  dụ khác cũng sẽ cho  ta thấy  rõ điều đó :

class MyClass
{
private:
    int _privateProp;

public:
    MyClass(int n) // constructor
    {
        this->_privateProp = n;
    }
};

void myFunc(MyClass mClass)
{
    cout << mClass._privateProp; // Không hợp lệ
}
-- Đây là cách dùng hàm  bạn để truy  cập  vào thành phần  private 
#include <iostream>
using namespace std;

class MyClass
{
private:
    int _privateProp;

public:
    MyClass(int n)
    {
        this->_privateProp = n;
    }

    friend void myFunc(MyClass);
};
void myFunc(MyClass mClass)
{
    cout << mClass._privateProp;
}
int main()
{
    MyClass mClass(2409);
    myFunc(mClass); // in ra màn hình 2409
    return 0;
}
==Sử dụng hàm bạn để có  thể truy cập 
void  InThongTin(SinhVien1 x){
    cout <<x.id <<" "<<x.ten<<" "<<x.ns <<" "<<x.gpa;
}
*/

// Hàm khởi tạo 
SinhVien1::SinhVien1(string ma,string name,string birth,double gpa){
    id=ma;
    ten=name;
    ns=birth;
    this->gpa=gpa;
}
void SinhVien1 :: Nhap(){
    cout <<"\nNhap id:";
    cin>>this->id;
    cin.ignore();
    cout <<"\nNhap Ten :"; 
    getline(cin,this->ten);
    cout <<"\nNhap Ngay Sinh :"; cin >>this->ns;
    cout <<"\nNhap diem :"; cin >> gpa;
}
void  SinhVien1::In(){
   cout <<id<<" "<<ten<<" "<<ns<<" "<<fixed<<setprecision(2)<<gpa<<endl;
}
int main(){
   SinhVien1 x;
   x.Nhap();
   Truy_Cap_Private(x);
   return 0;
}