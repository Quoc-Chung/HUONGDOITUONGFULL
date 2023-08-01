#include<bits/stdc++.h>
using namespace std;
int n;
class PS{
    private:
     int TuSo;
     int MauSo;
    public :
      friend istream& operator >> (istream& is, PS &p) {
        is >> p.TuSo>>p.MauSo;
        return is;
    }
      friend ostream& operator << (ostream& os, PS p) {
        os << p.TuSo <<"/"<<p.MauSo;
        return os;
    }
      friend PS operator*(PS &p1,PS &p2){
        PS p3;
        p3.TuSo=p1.TuSo*p2.TuSo;
        p3.MauSo=p1.MauSo*p2.MauSo;
        return p3;
      }
      void Nhap(PS *p){
        for (int i=0;i<n;i++){
           cout <<"\nPhan So thu "<<i+1<<":"<<endl;
           cin >>p[i];// p[i] da duoc nap chong toan tu nhap
        }
      }
      void In(PS *p){
        for (int i=0;i<n;i++){
            cout <<p[i];// Goi nap chong toan tu xuat
        }
      }
};

int main(){
   PS p1,p2;
   cout <<"\nNhap p1:";
   cin >>p1;

   cout <<"\nNhap p2:";
   cin >>p2;

   cout <<p2<<"  "<<p2<<endl;
   PS p3;
   p3=p1*p2;
   cout <<"\nTich hai phan so la :"<<p3;

} 