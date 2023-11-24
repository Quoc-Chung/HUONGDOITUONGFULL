#include<bits/stdc++.h>
using namespace std;
class Nguoi{
    private:
      string HoTen;
      int MaSo;
      int NamSinh;
      string GioiTinh;
    public:
      Nguoi(): HoTen(""),MaSo(0),NamSinh(0),GioiTinh(""){}
	  void Nhap(){
	    cout <<"\nNhap ho va ten:";
	    cin.ignore();
	    getline(cin,HoTen);
	    cout<<"\nNhap Ma So:";
	    cin >> MaSo;
	    cout <<"\nNhap nam sinh :";
	    cin>>NamSinh;
	    cout <<"\nNhap gioi tinh :";
	    cin.ignore();
	    getline(cin,GioiTinh);
	  }
	  void Xuat(){
	  	cout<<"\nHo va ten:"<<HoTen;
	  	cout<<"\nMa so :"<<MaSo;
	  	cout<<"\nNam sinh :"<<NamSinh ;
	  	cout <<"\nGioi tinh :"<<GioiTinh;
	  }
	  friend class HocVien;
};
class HocVien : public Nguoi {
	private:
		int ThoiGianThamGia;
		int SoLanTuongTac;
	public:
		HocVien(): ThoiGianThamGia(0), SoLanTuongTac(0){}
		void Nhap(){
			Nguoi::Nhap();
			cout<<"\nNhap TGTG :";
			cin >> ThoiGianThamGia;
			cout <<"\nNhap so lan tuong tac:";
			cin >> SoLanTuongTac;
		}
		void Xuat(){
			Nguoi::Xuat();
			cout<<"\nThoi gian tham gia :"<<ThoiGianThamGia;
			cout<<"\nSo lan tuong tac:"<<SoLanTuongTac;
		}
		void NhapThongTin(HocVien *hv ,int n){
			cout<<"\nNHAP THONG TIN "<<endl;
			for(int i=0;i<n;i++){
				hv[i].Nhap();
			}
		}
		void XuatThongTin(HocVien *hv,int n){
			cout<<"\nXUAT THONG TIN "<<endl;
			for (int i=0;i<n;i++){
				hv[i].Xuat();
			}
		}
		
		// Tim nhung thanh vien tre nhat 
		void ThanhVienTreNhat(HocVien *hv,int n){
			int max_tuoi =0;
			for(int i=0;i<n;i++){
			   		if(max_tuoi <hv[i].NamSinh){
			   			max_tuoi = hv[i].NamSinh;
					}
			}
			cout<<"\nCAC THANH VIEN TRE NHAT LA  :"<<endl;
			for (int i=0;i<n;i++){
				if(hv[i].NamSinh==max_tuoi){
					hv[i].Xuat();
				}
			}
		}
		void SapXepTangDan(HocVien *hv,int n){
			for (int i=0;i<n;i++){
				for (int j=0;j<n;j++){
					if(hv[i].ThoiGianThamGia > hv[j].ThoiGianThamGia){
						swap(hv[i],hv[j]);
					}
				}
			}
			cout<<"\nSAP XEP TANG DAN THEO THOI GIAN THAM GIA";
			hv[0].XuatThongTin(hv,n);			
		}
		
	void NutCoNhieuLanTuongTacNhat(HocVien *hv, int n) {
		    int max_lanTuongTac = 0;
		    int index = -1;
		    // Find the female member with the highest number of interactions
		    for (int i = 0; i < n; i++) {
		        if ((hv[i].GioiTinh == "Nu" || hv[i].GioiTinh == "NU" || hv[i].GioiTinh =="nu") && hv[i].SoLanTuongTac > max_lanTuongTac) {
		            max_lanTuongTac = hv[i].SoLanTuongTac;
		            index = i;
		        }
		    }
		
		    // Display the result
		    if (index != -1) {
		        cout << "\nNU CO NHIEU LAN TUONG TAC NHAT LA:";
		        hv[index].Xuat();
		    } else {
		        cout << "\nKhong co hoc vien nu trong danh sach.";
		    }
		}
};
int main(){
   int n;
   cout <<"\nNhap so hoc vien :";
   cin >>n;
   HocVien *hv = new HocVien[n];
   hv[0].NhapThongTin(hv,n);
   hv[0].XuatThongTin(hv,n);
   hv[0].ThanhVienTreNhat(hv,n);
   hv[0].SapXepTangDan(hv,n);
   hv[0].NutCoNhieuLanTuongTacNhat(hv,n);
   return 0;
}
