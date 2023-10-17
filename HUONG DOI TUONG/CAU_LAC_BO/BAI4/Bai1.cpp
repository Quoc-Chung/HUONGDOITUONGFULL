#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}
class PhanSo{
     private:
       int TuSo;
       int MauSo;
    public :
    // Hàm  khởi tạo phân số không có đối số truyền vào
       PhanSo(){
        TuSo=0;
        MauSo=1;
       }
      void Nhap(){
        cout<<"\nNhap Tu So:";
        cin>>TuSo;  
        cout<<"\nNhap Mau So:";
        cin>>MauSo;
      }
     void Xuat(){
         cout<<TuSo<<" / "<<MauSo;
     }
      friend PhanSo operator*(PhanSo &p1,PhanSo &p2){
        PhanSo p3;
        p3.TuSo=p1.TuSo*p2.TuSo;
        p3.MauSo=p1.MauSo*p2.MauSo;
        // Rut gon daang toi  gian
        int uoc =gcd(p3.TuSo,p3.MauSo);
        p3.TuSo/=uoc;
        p3.MauSo/=uoc;
        return p3;
      }
};
int main(){
  PhanSo  p1,p2;
  p1.Nhap();
  p2.Nhap();
  cout<<"\nPhan so  thu nhat la:"<<endl;
  p1.Xuat();
  cout<<"\nPhan so thu hai la:"<<endl;
  p2.Xuat();
  PhanSo p3;
  p3=p1*p2;
  cout<<"\nTich hai phan so la:"<<endl;
  p3.Xuat();
  return 0;
}