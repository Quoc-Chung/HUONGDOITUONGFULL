#include<bits/stdc++.h>
using namespace std;
    int UCLN(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
}
class PhanSo{
  private:
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
        if(y < 0){
          x*=(-1),y*=(-1);
        }
        return *this; //Tra ve doi tuong rut gon 
     }
     void Nhap(){
      cout<<"\nNhap hoanh do :";
      cin >> x;
      cout<<"\nNhap tung do :";
      cin >> y;
     }
     friend ostream& operator<<(ostream& os, PhanSo &ps){
        ps = ps.RutGon();
        os<<"\n"<<ps.x <<" / "<<ps.y <<endl;
        return os;
     }

      PhanSo operator*(PhanSo &p2){
      PhanSo Tich;
      Tich.x = x * p2.x;
      Tich.y = y * p2.y;
      return Tich;
     }
};

int main (){
  PhanSo p1(-2,4),p2;
  p2.Nhap();
  
  PhanSo p = p1*p2;
  cout<<"\nPhan so p1: "<<p1<<endl;
  cout<<"\nPhan so p2: "<<p2<<endl;
  
  cout<<"\nPhan so p :"<<p<<endl;
  return 0;
}
