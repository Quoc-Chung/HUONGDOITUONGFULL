#include<bits/stdc++.h>
using namespace std;
class MatHang{
	private:
		int MaHang;
		string TenHang;
		string NhaSanXuat;
		int SoLuong;
		long long DonGia;
	public:
		MatHang(): MaHang(0) , TenHang(""),NhaSanXuat(""),SoLuong(0),DonGia(0) {}
        void Nhap(){
        	cout <<"\nNhap ma hang :";
        	cin >> MaHang;
        	cout<<"\nNhap ten hang :";
        	cin.ignore();
        	getline(cin,TenHang);
        	cout<<"\nNhap nha san xuat:";
        	getline(cin,NhaSanXuat);
        	cout<<"\nNhap so luong:";
        	cin>>SoLuong;
        	cout<<"\nNhap don gia :";
        	cin >> DonGia;
		}
		void Xuat(){
			cout<<"\nMa hang:"<<MaHang;
			cout<<"\nTen hang:"<<TenHang;
			cout<<"\nNha san xuat:"<<NhaSanXuat;
			cout<<"\nSo luong:"<<SoLuong;
			cout<<"\nDon gia:"<<DonGia;
		}
		friend class MayTinh;
};
class MayTinh : public MatHang{
	private:
		string LoaiCPU;
		string HeDieuHanh;
		float TrongLuong;
	public:
		MayTinh(): LoaiCPU(""),HeDieuHanh(""),TrongLuong(0) {}
		void Nhap(){
			MatHang::Nhap();
			cout<<"\nNhap loai CPU :";
			cin.ignore();
			getline(cin,LoaiCPU);
			cout<<"\nNhap he dieu hanh:";
			getline(cin,HeDieuHanh);
			cout<<"\nNhap trong luong:";
			cin >>TrongLuong;
		}
		void Xuat(){
			MatHang::Xuat();
			cout<<"\nLoai CPU :"<<LoaiCPU;
			cout<<"\nHe dieu hanh :"<<HeDieuHanh;
			cout<<"\nTrong luong:"<<TrongLuong;
	}
	void NhapThongTin(MayTinh *mt,int n){
		cout<<"\nNhap thong tin :"<<endl;
		for(int i=0;i<n;i++){
			cout<<"\nThong tin may tinh thu "<<i+1<<" : "<<endl;
			mt[i].Nhap();
		}
	}
	void XuatThongTin(MayTinh *mt,int n){
		for(int i =0;i<n;i++){
			cout <<"\nMay tinh thu "<<i+1<<" : "<<endl;
			mt[i].Xuat();
		}
	}
	void HetHang(MayTinh * mt,int n){
		cout<<"\nCac loai may tinh het hang :"<<endl;
		bool check = false;
		for (int i=0;i<n;i++){
			if(mt[i].SoLuong == 0){
				mt[i].Xuat();
			}
		}
		if(check == false){
			cout<<"\nKhong co may tinh nao het hang "<<endl;
		}
	}
	void CacMayTinhCaiHeWin(MayTinh * mt,int n){
		float max =0;
		bool Check = false;
		for (int i=0;i<n;i++){
			if(mt[i].HeDieuHanh == "Windows" &&  max < mt[i].DonGia){
				max = mt[i].DonGia;
				Check = true;
			}
		}
		if(Check){
				cout<<"\nCac may tinh cai he win co gia cao nhat la:"<<endl;
	         	for (int i=0;i<n;i++){
	         	  	if(mt[i].HeDieuHanh == "Windows" &&  max == mt[i].DonGia){
			          mt[i].Xuat();
			}
	      }
		}
	
	}
};
int main(){
	int n;
	do{
		cout<<"\nNhap n:";
		cin >> n;
		if(n <= 0){
			cout<<"\nVui long nhap lai ."<<endl;
		}
	}while(n <= 0);
	MayTinh * mt = new MayTinh[n];
	mt[0].NhapThongTin(mt,n);
	cout<<"\n--------------------------------------------------"<<endl;
	mt[0].XuatThongTin(mt,n);
	cout<<"\n--------------------------------------------------"<<endl;
	mt[0].HetHang(mt,n);
	cout<<"\n--------------------------------------------------"<<endl;
	mt[0].CacMayTinhCaiHeWin(mt,n);
	return 0;
	}
