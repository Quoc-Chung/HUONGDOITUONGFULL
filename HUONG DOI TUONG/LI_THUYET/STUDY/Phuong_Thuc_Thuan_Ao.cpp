#include<bits/stdc++.h>
using namespace std;
// Lớp cha
class A{
  public :
  //Đây là phương thức ảo 
  virtual void Xuat(){
    cout <<"\nAi keu toi day.Co A day";
  }
  //Đây là phương thức thuần ảo
  virtual void TinhToan()=0;
};
// Lớp B,C kế thừa từ  lớp A
class B: public A{
   void Xuat(){
     cout <<"\nAi keu toi day.Co B day";
   }
   void TinhToan(){
    cout <<"\nDa tinh xong";
   }
};
class C: public A{
   void Xuat(){
    cout<<"\nAi keu toi day.Co C day";
   }
   void TinhToan(){
    cout <<"\n C Da tinh xong";
   }
class D: public A{
   void Xuat(){
    cout<<"\nAi keu toi day.Co C day";
   }
   void TinhToan(){
    cout <<"\n D Da tinh xong";
  }
};
};
int main(){ 

 // Nếu không có từ khóa virtual thi không làm đươc điều này 
//    A *x=new A; //Khởi tạo con trở gọi lại lớp A (New A)
//    x->Xuat();
//    A *x=new B; // Khởi tạo con trỏ gọi lại lớp B(New B)
//    x->Xuat();

      A *x=new C; // Khoi tao con tro goi lai lop C(New C)
      x->Xuat();
      x->TinhToan();
   return 0;
}