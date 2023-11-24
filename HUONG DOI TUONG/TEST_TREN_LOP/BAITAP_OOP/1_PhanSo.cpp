// 1. Xây dựng lớp phân số:
// - Thuộc tính: x(tử số), y(mẫu số)
// - Phương thức:
// o Hàm tạo không tham số
// o Hàm tạo có phân số
// o Hàm rút gọn phân số
// o Hàm nhập phân số
// o Hàm in một phân số
// o Hàm cộng hai phân số
// o Hàm trừ hai phân số
// 2. Viết hàm main() thực hiện các công việc:
// - Nhập vào các phân số p1,p2,p3,p4
// - Tính biểu thức (p1+p2)/(p3-p4)*p1
#include<bits/stdc++.h>
using namespace std;
// Hàm tìm ước chung lớn nhất bằng thuật toán Euclid
    int UCLN(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
}
class PhanSo{
  private :
    int x ,y ;
  public :
     PhanSo(){
       x =y = 0;
     }
     PhanSo(int Tu_So,int Mau_So){
        this->x = Tu_So;
        this->y = Mau_So;
     }
     PhanSo RutGon(){
        int glc = UCLN(x, y);
        x /= glc;
        y /= glc;
        return *this; // Trả về đối tượng gốc sau khi rút gọn
     }

     void Nhap(){
      cout<<"\nNhap hoanh do :";
      cin >> x;
      cout<<"\nNhap tung do :";
      cin >> y;
     }
     friend istream& operator>>(istream & is, PhanSo &ps){
       cout<<"\nNhap hoanh do :";
       is >> ps.x;
       cout<<"\nNhap tung do :";
       is>>ps.y;
       return is;
     }

     friend ostream& operator>>(ostream & os, PhanSo &ps){
        os<<"\n"<<ps.x <<" / "<<ps.y <<endl;
        return os;
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
      PhanSo Cong(PhanSo p1,PhanSo p2){
        PhanSo T;
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
