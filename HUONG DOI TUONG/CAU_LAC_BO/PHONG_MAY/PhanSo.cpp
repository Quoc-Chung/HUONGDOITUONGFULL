#include<bits/stdc++.h>
using namespace std;
class PhanSo {
public:
    int TuSo;
    int MauSo;
public:
//  Trien khai ham khoi  tao co tham so truyen vao  
    PhanSo();
    // Constructor có tham số
    PhanSo(int TuSo, int MauSo) {
        this->TuSo = TuSo;
        this->MauSo = MauSo;
    }
    void Nhap() {
        cout << "\nNhap Tu So: "; cin >> TuSo;
        cout << "Nhap Mau So: "; cin >> MauSo;
    }
    void InPhanSo() {
        cout << "(" << TuSo << "/" << MauSo << ")";
    }
    // Nap chong cong
    friend PhanSo operator*(PhanSo &p1,PhanSo &p2){
      PhanSo p3;
      p3.TuSo = p1.TuSo * p2.TuSo;
      p3.MauSo = p1.MauSo * p2.MauSo;
      return p3;
    }
};
// Hàm  khởi tạo không có đối số truyền vào 
PhanSo::PhanSo()
{
  TuSo = 0;
  MauSo = 1;
}
int main() {
   PhanSo p1,p2;
   cout <<"\nNhap phan so thu nhat:";
   p1.Nhap();
   cout <<"\nNhap phan so thu hai:";
   p2.Nhap();
   cout<<"\nNhap phan so tich :";
   PhanSo p3 = p1*p2;
   p3.InPhanSo();
    return 0;
}


