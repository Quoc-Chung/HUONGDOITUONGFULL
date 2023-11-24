

#include<bits/stdc++.h>
using namespace std;
int UCLN (int a,int b){
	while(b!= 0){
		int tmp = b; 
		b= a%b;
		a =tmp;
	}
	return a;
}
class PhanSo{
	private:
		int x;
		int y;
	public:
		PhanSo():x(0),y(0) {}
		void Nhap(){
			cout<<"\nNhap tu so:";
			cin >> x;
			cout<<"\nNhap mau so :";
			cin >> y;
		}
		void Xuat(){
			cout<<"\nPhan So :("<<x<<" / "<<y <<")";
		}
		PhanSo RutGon(){
			int glc = UCLN(x,y);
			x/= glc;
			y/= glc;
			return *this;
		}
		 // Ham nap chong toan tu 
		friend istream& operator>>(istream& is,PhanSo &ps){
			cout<<"\nNhap phan so:";
			is>>ps.x;
			cout<<"\nNhap mau so :";
			is>>ps.y;
			return is;
		}
		friend ostream& operator<<(ostream& os, PhanSo &ps){
			os<<"\nPhan So :("<<ps.x<<" / "<<ps.y <<")";
			return os;
		}
		PhanSo operator+(PhanSo &ps2){
			PhanSo T;
			T.x = x+ps2.x;
			T.y = x +ps2.y;
			return T;
		}
		// Cong hai phan so Tu1 * mau2 + tu2 * mau1 / mau1 * mau2
		// Chia thi la nhan nghich dao : (Tu1 * mau2) / (Tu2 * mau1)	
};
