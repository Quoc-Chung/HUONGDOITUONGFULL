#include<bits/stdc++.h>
using namespace std;
class QLH{
	private:
		 int MaHang;
		 string TenHang;
		 string XuatXu;
		 int LoaiHang;// 1 2 3
		 int SoLuong;
	public:
		 QLH(): MaHang(0),TenHang(""),XuatXu(""),LoaiHang(0),SoLuong(0) {}
		 string getTenHang(){
	    	return TenHang;
		 }
		 int getLoaiHang(){
		 	return LoaiHang;
		 }		 
		 void Nhap(){
		 	cout<<"\nNhap ma hang:";
		 	cin >> MaHang;
		 	cout<<"\nNhap ten hang:";
		 	cin.ignore();
		 	getline(cin , TenHang);
		 	cout<<"\nNhap xuat xu :";
		 	getline(cin , XuatXu);
		 	cout<<"\nNhap loai hang:";
		 	cin >> LoaiHang;
		 	cout<<"\nNhap so luong:";
		 	cin >> SoLuong;
		 }
		 void Xuat(){
		 	cout<<"\nMa hang:"<<MaHang;
		 	cout<<"\nTen hang:"<<TenHang;
		 	cout<<"\nXuat xu : "<<XuatXu;
		 	cout<<"\nLoai hang :"<<LoaiHang;
		 	cout<<"\nSo luong :"<<SoLuong;	 	
		 }		 
};
class DienTu :public QLH{
	private:
		int Tgbh;
	public:
		DienTu() : Tgbh(0){}
		void Nhap(){
			QLH::Nhap();
			cout<<"\nNhap  tgbh :";
			cin >> Tgbh;
		}
		void Xuat(){
			QLH::Xuat();
			cout<<"\nThoi gian bao hanh:"<<Tgbh;
		}
		void NhapThongTin (DienTu *dt,int n){
			for(int i=0;i<n;i++){
				cout <<"\nNhap thong tin cho hang  thu "<<i+1<<":"<<endl;
				dt[i].Nhap();
			}
		}
		void XuatThongTin (DienTu *dt,int n){
			for(int i=0;i<n;i++){
				cout <<"\nThong tin cho hang  thu "<<i+1<<":"<<endl;
				dt[i].Xuat();
			}
		}
		void ThongKe(DienTu *dt,int n){
		    int dem1 =0,dem2=0,dem3=0;
		    cout<<"\nCac mat hang co thoi gian bao hanh tren 12 thang ."<<endl;
			for(int i=0;i<n;i++){
				if(dt[i].Tgbh > 12){
				    if(	dt[i].getLoaiHang() == 1){	
				     	dem1++;
				    } 
					if(dt[i].getLoaiHang() == 2){
						dem2++;
					} 
					if(dt[i].getLoaiHang() == 3){
						dem3++;
					} 
			}
		  }
		    if(dem1 ==0 && dem2==0 && dem3 ==0){
		    	cout<<"\nKhong co mat hang nao co thoi gian bao hanh tren  12 thang .";
			}
			else{
				cout<<"\nSo luong mat hang loai hang 1 :"<<dem1;
				cout<<"\nSo luong mat hang loai hang 2 :"<<dem2;
				cout<<"\nSo luong mat hang loai hang 3 :"<<dem3;
			}
		}
		void TimMatHangTheoTen(DienTu *dt, int n , string Search){
			bool Check = false; // ban dau chua tim thay 
			for (int i=0;i<n;i++){
				if(Search == dt[i].getTenHang()){
					Check= true;
					cout<<"\nTim thay mat hang theo ten ."<<endl;
					dt[i].Xuat();
				}
			}
			if(Check == false){
				cout<<"\nKhong tim thay mat hang"<<endl;
			}
		}
};
int main(){
	int n;
	cout<<"\nNhap so luong hang:";
	cin >> n;
	DienTu *dt = new DienTu[n];
	dt[0].NhapThongTin(dt,n);
	dt[0].XuatThongTin(dt,n);
	dt[0].ThongKe(dt,n);
	string Ten;
	cout<<"\nNhap ten tim kiem :";
	cin.ignore();
	getline(cin , Ten);
	dt[0].TimMatHangTheoTen(dt,n,Ten);
	return 0;
}
