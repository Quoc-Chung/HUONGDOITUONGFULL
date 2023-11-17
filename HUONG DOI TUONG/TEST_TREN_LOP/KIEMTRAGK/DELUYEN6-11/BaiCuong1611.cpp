#include<bits/stdc++.h>
using namespace std;
class KhaoSat{
	private:
		string TenChuHo;
		int SoThanhVien;
		float DienTich;
	public:
		KhaoSat(): TenChuHo(""),SoThanhVien(0),DienTich(0) {}
		
		int getSoThanhVien(){
		return SoThanhVien;
		}
		
		float getDienTich(){
		return DienTich;
		}
		void Nhap(){
			cout<<"\nNhap ten chu ho :";
			cin.ignore();
			getline(cin,TenChuHo);
			cout<<"\nNhap so thanh vien:";
			cin >> SoThanhVien;
			cout<<"\nNhap dien tich:";
			cin >> DienTich;
		}
		void Xuat(){
		   cout<<"\nTen chu ho :"<<TenChuHo;
		   cout<<"\nSo thanh vien :"<<SoThanhVien;
		   cout<<"\nDien tich :"<<DienTich;
		}

};
class DanXuat:public KhaoSat{
	private:
		string Tinh;
	public:
		DanXuat():Tinh(""){}

		void Nhap(){
		KhaoSat::Nhap();
		cout<<"\nNhap tinh:";
		cin.ignore();
		getline(cin , Tinh);
		}

		void Xuat(){
		KhaoSat::Xuat();
		cout<<"\nTinh :"<<Tinh;
		}
		
	void NhapNhieu(DanXuat *dx, int n) {
    cout << "\nTIEN HANH NHAP GIA DINH :" << endl;
    for (int i = 0; i < n; i++) {
        dx[i].Nhap();
      }
   }
	void XuatNhieu(DanXuat *dx,int n){
	   cout<<"\nDANH SACH CAC HO GIA DINH :"<<endl;
	   for (int i=0;i<n;i++){
	   	dx[i].Xuat();
	   }
	}

	void SoSanh(DanXuat *dx, int n){
	    int dem1=0,dem2=0;
	    for(int i=0;i<n;i++){
	     if(dx[i].getSoThanhVien() %2==0){
	     	dem1++;
			 }
		 else{
		 	dem2++;
		 }
		}
		if(dem1==0 || dem2==0){
	      cout<<"\nKHong du du lieu so sanh ."<<endl;
		}
		else{
			if(dem1 > dem2){
		      cout<<"\nHo co so thanh vien chan nhieu hon ho co so thanh vien le  "<<endl;
			}
			else if(dem1 <dem2){
				cout<<"\nHo co so thanh vien le nhieu hon ho co so thanh vien chan"<<endl;
			}
			else{
				cout<<"\nCac ho co so thanh vien chan bang cac ho co so thanh vien le "<<endl;
			}
		}
	}
	
	void MatDoDanSo(DanXuat *dx,int n){
		float Max =0;
	    for(int i=0;i<n;i++){
	      if(Max < dx[i].getDienTich() / dx[i].getSoThanhVien()){
	       Max =   dx[i].getDienTich() / dx[i].getSoThanhVien();
			}
		}
		cout<<"\nCac ho co mat do dan so cao nhat la :"<<endl;
		for(int i=0;i<n;i++){
		  if((int)Max ==  (int) ( dx[i].getDienTich() / dx[i].getSoThanhVien())){
		  	   dx[i].Xuat();
			  }
		}
	}
	
	void ThongTin(DanXuat *dx,int n){
		int dem=0;
       for(int i=0 ; i< n;i++){
       	 if(dx[i].Tinh =="HN" && dx[i].getDienTich() / dx[i].getSoThanhVien() < 4){
       	 	dx[i].Xuat();
       	 	dem++;
		}
	  }
	  if(dem==0){
	     cout<<"\nKhong co  gia dinh nao thoa man "<<endl;
	   }
	}
};

int main() {
    int n;
    cout << "\nNhap so gia dinh :";
    cin >> n;
    DanXuat *d = new DanXuat[n];
    if (d == NULL) {
        cout << "\nKhong the cap phat " << endl;
        exit(1);
    }
   
    d[0].NhapNhieu(d, n);
    d[0].XuatNhieu(d, n);
    d[0].SoSanh(d, n);
  d[0].MatDoDanSo(d, n);
    d[0].ThongTin(d, n);
    delete[] d;
    return 0;
}
	
