#include<bits/stdc++.h>
using namespace std;
class KhachHang{
   protected: 
        int MaKhach;
        string HoTen;
        string DiaChi;
        int SoThangTruoc;
        int SoThangSau;
  public:
       string getHoTen(){
        return HoTen;
       }
  /* - Khởi tạo k đối số - */
        KhachHang() : MaKhach(0), HoTen(""),DiaChi(""),SoThangTruoc(0),SoThangSau(0) {}
  /* - Khởi tạo có đối - */
        KhachHang(int MaKhach, string HoTen,string DiaChi,int SoThangTruoc,int SoThangSau):
        MaKhach(MaKhach), HoTen(HoTen),DiaChi(DiaChi),SoThangTruoc(SoThangTruoc),SoThangSau(SoThangSau){}       
        void Nhap(){
            cout<<"\nNhap ma khach:";
            cin >> MaKhach;
            cout<<"\nNhap Ho Ten:";
            cin.ignore();
            getline(cin,HoTen);
            cout<<"\nNhap dia chi :";
            getline(cin,DiaChi);
            cout<<"\nSo thang truoc :";
            cin >> SoThangTruoc;
            cout<<"\nSo thang sau :";
            cin >> SoThangSau;
        }
        void Xuat(){
            cout << "Ma Khach: " << MaKhach << endl;
            cout << "Ho Ten: " << HoTen << endl;
            cout << "Dia Chi: " << DiaChi << endl;
            cout << "So Thang Truoc: " << SoThangTruoc << endl;
            cout << "So Thang Sau: " << SoThangSau << endl;
        }
};
class GiamGia : public KhachHang{
    private:
      int UuTien;
    public :
      GiamGia():UuTien(0){}
      GiamGia(int UuTien): UuTien(UuTien){}
     void Nhap(){
      KhachHang::Nhap();
      cout<<"\nNhap uu tien :";
      cin >> UuTien;
     }
    double TinhTien() {
        if (UuTien == 1) {
            return (SoThangSau - SoThangTruoc) * 3000;
        } else if (UuTien == 2) {
            return (SoThangSau - SoThangTruoc) * (3000 * 0.05);
        } else {
            return (SoThangSau - SoThangTruoc) * (3000 * 0.1);
        }
    }
     void Xuat(){
      KhachHang::Xuat();
      cout<<"\nMuc do uu tien :"<<UuTien<<endl;
      double  x = TinhTien();
      cout<<" Tien nuoc la :"<<x<<endl;
     }
}; 
void DanhSachGiamDan (GiamGia *kh,int n){
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(kh[i].TinhTien() < kh[j].TinhTien()){
                auto Tmp = kh[i];
                kh[i]= kh[j];
                kh[j] = Tmp;
            }
        }
    }
    cout<<"\nDanh sach khach hang theo thu tu giam dan :\n";
    for (int i=0;i<n;i++){
        kh[i].Xuat();
    }
}
void TimKiemTheoTen(GiamGia *kh,int n,string& tenCanTim) {
    bool found = false;
    cout << "Nhap ten khach hang can tim: ";
    cin.ignore();
    getline(cin, tenCanTim);
    for (int i = 0; i < n; i++) {
        if (kh[i].getHoTen() == tenCanTim) {
            found = true;// TÌM THẤY
            cout << "Khach Hang co ten '" << tenCanTim << "':" << endl;
            kh[i].Xuat();
        }
    }
    if (!found) {
        cout << "Khong tim thay khach hang co ten '" << tenCanTim << "'." << endl;
    }
}
int main(){
    int n;
    cout<<"\nNhap so luong khach hang:";
    cin >> n;
   GiamGia *kh = new GiamGia[n];
   for(int i=0;i<n;i++){
    kh[i].Nhap();
   }
   cout<<"\n--------DANH SACH KHACH HANG -------";
   for(int i=0;i<n;i++){
    kh[i].Xuat();
   }
   DanhSachGiamDan(kh,n);
   string search;
   TimKiemTheoTen(kh,n,search);
   return 0;

}