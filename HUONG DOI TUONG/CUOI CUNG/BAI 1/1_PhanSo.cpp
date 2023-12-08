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
     
     void Xuat(){
      RutGon();
      cout<<"\n"<<x <<" / "<<y <<endl;
     }
     
     friend istream& operator>>(istream & is, PhanSo &ps){
       cout<<"\nNhap hoanh do :";
       is >> ps.x;
       cout<<"\nNhap tung do :";
       is>>ps.y;
       return is;
     }

     friend ostream& operator<<(ostream& os, PhanSo &ps){
        os<<"\n"<<ps.x <<" / "<<ps.y <<endl;
        return os;
     }

      PhanSo Cong(PhanSo p1,PhanSo p2){
        PhanSo T;
        T.x =p1.x *p2.y + p2.x *p1.y;
        T.y =p1.y *p2.y;
        return T;
     }
     PhanSo Tru(PhanSo p1, PhanSo p2) {
	    PhanSo T;
	    T.x = p1.x * p2.y - p2.x * p1.y;
	    T.y = p1.y * p2.y;
	    return T;
}
	PhanSo Nhan(PhanSo p1, PhanSo p2) {
	    PhanSo T;
	    T.x = p1.x * p2.x;
	    T.y = p1.y * p2.y;
	    return T;
	}
	PhanSo Chia(PhanSo p1, PhanSo p2) {
	    PhanSo T;
	    T.x = p1.x * p2.y;
	    T.y = p1.y * p2.x;
	    return T;
	}
	friend PhanSo operator+(PhanSo &p1,PhanSo &p2){
		PhanSo T;
		T.x =p1.x *p2.y + p2.x *p1.y;
        T.y =p1.y *p2.y;
        return T;
	}

   
    friend PhanSo operator-(PhanSo &p1,PhanSo &p2){
     	PhanSo Hieu;
        Hieu.x = p1.x * p2.y - p2.x * p1.y;
	    Hieu.y = p1.y * p2.y;
	    return  Hieu;
    }
      friend PhanSo operator*(PhanSo &p1 ,PhanSo &p2){
      PhanSo Tich;
      Tich.x = p1.x * p2.x;
      Tich.y = p1.y * p2.y;
      return Tich;
     }
      friend PhanSo operator/(const PhanSo &p1 ,const PhanSo &p2){
       PhanSo Chia;
       Chia.x = p1.x * p2.y; 
       Chia.y = p1.y * p2.x;
       return Chia;
     }
};
// Viet cac ham thuc hien cac cong viec 
// - Nhap cac phan so p1,p2,p3,p4
// - Tinh bieu thuc (p1+p2)/(p3-p4)*p1
int main (){
    PhanSo p1,p2,p3,p4;
    cout<<"\nNhap phan so p1:";
    p1.Nhap();
    cout<<"\nNhap phan so p2:";
    p2.Nhap();
	cout<<"\nNhap phan so p3:";
	cin >> p3;
	cout <<"\nNhap phan so p4:";
	cin >> p4;
	
	 cout<<"\nCac Phan so lan luot la :"<<endl;
  	p1.Xuat();
  	p2.Xuat();
    cout<<p3;
    cout<<p4;
    
    PhanSo Tong = (p1+p2)/((p3-p4));
    cout<<"\nPhan so tong cuoi : "<< Tong<<endl;
    
    return 0; 
}

