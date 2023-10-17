#include<bits/stdc++.h>
using namespace std;
class PhanSo{
  private :
    int TuSo;
    int MauSo;
  public :
    PhanSo(){
        TuSo = 0;
        MauSo = 1;
    }
    void Nhap(){
        cout<<"\nNhap Tu So :";
        cin>>TuSo;
        cout<<"\nNhap Mau So :";
        cin>>MauSo;
    }
    void Xuat(){
        cout<<TuSo<<" / "<<MauSo<<endl;
    }
    friend PhanSo operator+(PhanSo &p1,PhanSo &p2){
        PhanSo p3;
        p3.TuSo = p1.TuSo * p2.MauSo + p2.TuSo * p1.MauSo;
        p3.MauSo = p1.MauSo * p2.MauSo;
        return p3;
    }
};
int main(){
  PhanSo p1,p2;
  p1.Nhap();
  p2.Nhap();
  PhanSo p3 = p1 + p2;
  p3.Xuat();
  return 0;
}