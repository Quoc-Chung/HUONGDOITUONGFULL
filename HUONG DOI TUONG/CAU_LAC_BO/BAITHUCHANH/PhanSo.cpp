#include<bits/stdc++.h>
using namespace std;
class PhanSo{
  private :
    int TuSo;
    int MauSo;
  public :
    void Nhap();
    void Xuat();
    PhanSo Nhan(PhanSo p);
    PhanSo Cong(PhanSo p);
};
void PhanSo ::Nhap(){
  cout << "\nNhap tu so: ";  cin >> TuSo;
  cout << "\nNhap mau so: "; cin >> MauSo;  
}
void PhanSo ::Xuat(){
    cout <<"\nPhan So la :"<<TuSo<<"/"<<MauSo<<endl;
}
PhanSo PhanSo ::Nhan(PhanSo p){
    PhanSo tmp;
    tmp.TuSo =TuSo *p.TuSo;
    tmp.MauSo =MauSo *p.MauSo;
    return tmp;
}
PhanSo PhanSo ::Cong(PhanSo p){ 
}
int main(){
 PhanSo p1,p2,p3;
 p1.Nhap();
 cout<<"\nPhan So p1 la :";
 p1.Xuat();
 p2.Nhap();
 cout<<"\nPhan So p2 la :";
 p2.Xuat();
 p3=p1.Nhan(p2);
 cout<<"\nPhan So p3 la :";
 p3.Xuat();

}