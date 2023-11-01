#include<bits/stdc++.h>
using namespace std;
int gcdd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class PhanSo{
  private :
    int x,y;
  public :
    /* - Hàm tạo không có tham số - */
     PhanSo(): x(0),y(0) {}
    /* - Hàm tạo có tham số - */
     PhanSo(int Tu_So,int Mau_So): x(Tu_So),y(Mau_So) {}
     PhanSo RutGon(){
        int glc =gcdd(x, y);
        x /= glc;
        y /= glc;
        return *this; 
     }
     void Nhap(){
      cout<<"\nNhap tu so:";
      cin >> x;
      cout<<"\nNhap mau so :";
      cin >> y;
     }
     void In (){
      RutGon();
      cout<<"\n"<<x <<" / "<<y <<endl;
     }
      PhanSo Cong(PhanSo p2){
      PhanSo T,p1;
      p1 =*this;
      T.x =p1.x *p2.y + p2.x *p1.y;
      T.y =p1.y *p2.y;
      return T;
     }
      PhanSo Tru(PhanSo p2){
      PhanSo T,p1;
      p1 =*this;
      T.x =p1.x * p2.y - p2.x *p1.y;
      T.y =p1.y *p2.y;
      return T;
     }
    friend PhanSo operator*(PhanSo &p1 ,PhanSo &p2){
      PhanSo Tich;
      Tich.x = p1.x * p2.x;
      Tich.y = p1.y * p2.y;
      return Tich;
     }
     friend PhanSo operator/(PhanSo &p1 ,PhanSo &p2){
      PhanSo Chia;
      // Phép chia thì bằng phép nhân nghịch đảo 
       Chia.x = p1.x * p2.y; 
      Chia.y = p1.y * p2.x;
      return Chia;
     }
};
int main (){
    PhanSo p1,p2,p3,p4;
    cout<<"\nNhap phan so thu nhat:\n";
    p1.Nhap();
    cout<<"\nNhap phan so thu hai:\n";
    p2.Nhap();
    cout<<"\nNhap phan so thu ba:\n";
    p3.Nhap();
    cout<<"\nNhap phan so thu tu:\n";
    p4.Nhap();
    cout<<"\nCac Phan So vua nhap :\n";
    p1.In();p2.In();p3.In();p4.In();
   // (p1+p2)/(p3-p4)*p1
   PhanSo cong =p1.Cong(p2);
   PhanSo tru =p3.Tru(p4);
   PhanSo nhan = tru *p1;
   PhanSo tmp = cong / nhan;
   tmp.In();
    return 0; 
}