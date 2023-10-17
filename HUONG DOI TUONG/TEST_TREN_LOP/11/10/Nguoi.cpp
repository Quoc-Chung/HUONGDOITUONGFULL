#include<bits/stdc++.h>
using namespace std;

class NgayThang{
   private:
     int Ngay,Thang,Nam;
  public:

     NgayThang() : Ngay(0),Thang(0),Nam(0) {}
     NgayThang(int Ngay,int Thang,int Nam) : Ngay(Ngay) ,Thang(Thang) ,Nam(Nam) {}

     friend istream& operator>>(istream& is, NgayThang& nt){
        cout<<"\nNhap ngay :";
        is >> nt.Ngay;
        cout<<"\nNhap thang:";
        is >> nt.Thang;
        cout<<"\nNhap nam:";
        is >> nt.Nam;
        return is;
     }
     friend ostream& operator<<(ostream& os, NgayThang& nt){
        os<<nt.Ngay<<" / "<<nt.Thang<<" / "<<nt.Nam<<endl;
        return os;
     }
};
class Nguoi{
   protected:
     string HoTen;
     NgayThang NgaySinh;
     string DiaChi;
  public:
  string getHoTen(){
    return HoTen;
  }
     Nguoi() : HoTen("") , NgaySinh(0,0,0) , DiaChi(""){ }

     Nguoi(string HoTen, int Ngay, int Thang, int Nam, string DiaChi)
    : HoTen(HoTen), NgaySinh(Ngay, Thang, Nam), DiaChi(DiaChi) {}
     void Nhap(){
        cin.ignore();
        cout<<"\nNhap HoTen :";
        getline(cin, HoTen);
        cout<<"\nNhap ngay sinh :";
        cin >>NgaySinh;
        cout<<"\nNhap dia chi :";
        cin.ignore();
        getline(cin,DiaChi);
     }
     void Xuat(){
        cout << "Ho Ten: " << HoTen << endl;
        cout << "Ngay Sinh: " << NgaySinh;
        cout << "Dia Chi: " << DiaChi << endl;
     }
};
class KhachHang : public  Nguoi{
     private:
        string MaKH;
        int ChiSoTruoc;
        int ChiSoSau;
    public :
         int getChiSoTruoc(){
            return ChiSoTruoc;
         }
         int getChiSoSau(){
            return ChiSoSau;
         }
         KhachHang(){

         }
       KhachHang(string MaKH, int ChiSoTruoc, int ChiSoSau,  string HoTen, int Ngay, int Thang, int Nam, string DiaChi)
        : Nguoi(HoTen, Ngay, Thang, Nam, DiaChi), MaKH(MaKH), ChiSoTruoc(ChiSoTruoc), ChiSoSau(ChiSoSau) {}

         double Tinhtien(){
            int SoDien= ChiSoSau-ChiSoTruoc;
            double Tien = 0;
            if(SoDien <=50){
                Tien = SoDien * 1678;
            }
            else if(SoDien > 50 && SoDien <=100){
                Tien= 50*1678 + (SoDien-50)*1738;
            }
            else if(SoDien > 100 && SoDien <= 200){
                Tien = 50 * 1678 + (SoDien-50)*1738 + (SoDien-100) * 2014;
            }
            else if(SoDien > 200 && SoDien <= 300){
                Tien=  50 * 1678 + (SoDien-50)*1738 + (SoDien-100) * 2014 + (SoDien -200)* 2536;
            }
            else{
                Tien = 50 * 1678 + (SoDien-50)*1738 + (SoDien-100) * 2014 + (SoDien -200)* 2536 + 
                (SoDien -300)* 2834;
            }
        return Tien;
    }

    int BacTieuThu(){
           int SoDien= ChiSoSau-ChiSoTruoc;
           double Tien = 0;
            if(SoDien <=50){
               return 1;
            }
            else if( SoDien > 50 && SoDien <=100){
                return 2;
            }
            else if(SoDien >= 100 && SoDien <= 200){
                return 3;
            }
            else if(SoDien > 200 && SoDien <=300){
               return 4;
            }
            else {
                return 5;
            }
    }

    void Nhap(){
        Nguoi::Nhap();
        cout<<"\nNhap Ma Khach Hang  :";
        getline ( cin , MaKH);
        cout<<"\nNhap chi so truoc :";
        cin >>ChiSoTruoc;
        cout <<"\nNhap chi so  sau :";
        cin >> ChiSoSau ;
    }
    void Xuat(){
        Nguoi::Xuat();
        cout <<"\nMa khach hang:"<<MaKH<<endl;
        cout<<"\nChi so truoc :"<<ChiSoTruoc;
        cout<<"\nChi so sau :"<<ChiSoSau;
    }
};

void TimKiemTheoTen(KhachHang khachHangs[], int n,string& tenCanTim) {
    bool found = false;
    cout << "Nhap ten khach hang can tim: ";
    cin.ignore();
    getline(cin, tenCanTim);
    for (int i = 0; i < n; i++) {
        if (khachHangs[i].getHoTen() == tenCanTim) {
            found = true;// TÌM THẤY
            cout << "Khach Hang co ten '" << tenCanTim << "':" << endl;
            khachHangs[i].Xuat();

             cout<<"\nSo dien tieu thu :"<<khachHangs[i].getChiSoSau()- khachHangs[i].getChiSoTruoc();
             double x = khachHangs[i].Tinhtien();
             cout<<"\nSo tien phai tra :"<<fixed<< setprecision(2)<<x<<endl;
             cout << endl;
        }
    }
    if (!found) {
        cout << "Khong tim thay khach hang co ten '" << tenCanTim << "'." << endl;
    }
}
/* - Hàm  này dùng map sẽ nhanh hơn
void ThongKeTheoBacTieuThu(KhachHang *kh,int n){
    int dem1=0,dem2=0,dem3=0,dem4=0,dem5 =0;

    for (int i=0;i<n;i++){
        if(kh[i].BacTieuThu()==1){
            dem1++;
        }
        else if(kh[i].BacTieuThu()==2){
            dem2++;
        }
        else if(kh[i].BacTieuThu()==3){
            dem3++;
        }
        else if(kh[i].BacTieuThu()==4){
            dem4++;
        }
        else {
            dem5++;
        }
    }
    cout<<...
}
*/
void ThongKeTheoBacTieuThu(KhachHang *kh, int n) {
    map<int,int> bacCounts;
    for (int i = 0; i < n; i++) {
        int bacTieuThu = kh[i].BacTieuThu();
        bacCounts[bacTieuThu]++;
    }
    for (auto x : bacCounts) {
        int bac = x.first;
        int count = x.second;
        cout << "Bac Tieu Thu: " << bac << " - So Ho Dan: " << count << endl;
    }
}
int main() {
    int n;
    cout << "Nhap so luong khach hang: ";
    cin >> n;
    KhachHang *khachHangs = new KhachHang[n];
    for (int i = 0; i < n; i++) {
        khachHangs[i].Nhap();
    }
    cout << "Danh sach khach hang:" << endl;
    for (int i = 0; i < n; i++) {
        khachHangs[i].Xuat();
        cout << endl;
    }
    string tenCanTim;
    TimKiemTheoTen(khachHangs, n, tenCanTim);
    ThongKeTheoBacTieuThu(khachHangs, n);
    delete[] khachHangs;
    return 0;
}
