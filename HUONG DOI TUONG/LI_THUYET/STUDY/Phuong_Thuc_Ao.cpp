#include<bits/stdc++.h>
using namespace std;
class A{
  public :
  virtual void Xuat(){
    cout <<"\nAi keu toi day.Co A day";
  }
};
// Lớp B,C kế thừa từ  lớp A
class B: public A{
   void Xuat(){
     cout <<"\nAi keu toi day.Co B day";
   }
};
class C: public A{
   void Xuat(){
    cout<<"\nAi keu toi day.Co C day";
   }
};
int main(){ 

 // Nếu không có từ khóa virtual thi không làm đươc điều này 
//    A *x=new A; //Khởi tạo con trở gọi lại lớp A (New A)
//    x->Xuat();
//    A *x=new B; // Khởi tạo con trỏ gọi lại lớp B(New B)
//    x->Xuat();

      A *x=new C; // Khoi tao con tro goi lai lop C(New C)
      x->Xuat();
   return 0;
}