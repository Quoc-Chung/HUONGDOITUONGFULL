#include<bits/stdc++.h>
using namespace std;
class NgayThang{
   private:
      int ngay , thang ,nam;
   public:
      NgayThang(): ngay(0),thang(0),nam(0) {}
      void Nhap(){
        cout <<"\nNhap ngay-thang-nam:";
        cin >> ngay>>thang>>nam;
      }
      void Xuat(){
        cout<<ngay <<"/"<< thang<<"/"<<nam<<endl;
      } 
}; 
class Nguoi {
    private :
       string HoTen;
       NgayThang NgaySinh;
       string DiaChi;
    public :
     string getHoTen(){
        return HoTen;
     }
      Nguoi (): HoTen(""),DiaChi(""){}
      void Nhap(){
        cout<<"\nNhap ho ten:";
        cin.ignore();
        getline(cin,HoTen);
        NgaySinh.Nhap();
        cout<<"\nNhap dia chi:";
        cin.ignore();
        getline(cin,DiaChi);
      }
      void Xuat(){
        cout<<"\n Ho ten :"<<HoTen;
        cout<<"\nNgay sinh :";
        NgaySinh.Xuat();
        cout<<"\nDia chi :"<<DiaChi;
      }
};
class KhachHang :public Nguoi{
  private:
     int maKH;
     float chi_so_truoc;
     float chi_so_sau;
  public:
     KhachHang():maKH(0),chi_so_truoc(0),chi_so_sau(0) {}
     void Nhap (){
        cout <<"\nNhap ma khach hang";
        cin >> maKH;
        Nguoi::Nhap();
        cout <<"\nNhap chi so truoc:";
        cin >> chi_so_truoc;
        cout <<"\nNhap chi so sau :";
        cin >> chi_so_sau;
     }
     void Xuat(){
        cout<<"\nMa khach hang :"<<maKH;
        Nguoi::Xuat();
        cout<<"\nChi so truoc:"<<chi_so_truoc;
        cout <<"\nChi so sau :"<<chi_so_sau;
     }
     float TinhTienDien(){
        float tien_dien =0;
        // bac chinh la so dien 
        int bac = chi_so_sau-chi_so_truoc;
        if(bac >=0 && bac <= 50){
           tien_dien = 1.678 * bac;
        }
        else if(bac >50 && bac <=100){
            tien_dien=1.734*bac;
        }
        else if(bac >100 && bac <=200){
            tien_dien= 2.014 * bac;
        }
        else if(bac > 200 && bac <=300){
            tien_dien=2.536 *bac;

        }
        else if(bac > 300 && bac <=400){
            tien_dien = 2.834*bac;
        }
        else if(bac > 400){
            tien_dien = 2.927 * bac;
        }
        return tien_dien;
     }
     void TimKiemKhach(KhachHang *kh ,int n, string ten){
        bool check = false;
        for(int i=0;i<n;i++){
            if(kh[i].getHoTen() == ten){
                cout <<"\nTim Thay khach hang.";
                cout <<"\nMa khach hang :"<<kh[i].maKH<<endl;
                cout<<"\nSo dien tieu thu :"<<fixed<<setprecision(2)<<kh[i].chi_so_sau-kh[i].chi_so_truoc<<endl;
                float sotien = kh[i].TinhTienDien();
                cout <<"\nSo tien dien phai tra la :"<<sotien<<" nghin dong."<<endl;
                check =true;
                break;
            }
        }
        if(check ==false){
            cout <<"\nKhong tim thay khach hang "<<endl;
        }
     }
     void ThongKe(KhachHang *kh ,int n){
        // Làm tương tự thôi  
     }
};
int main(){
    int n;
    cout<<"\nNhap so khach hang :";
    cin >> n;
    KhachHang *kh = new KhachHang[n];
    for(int i=0;i<n;i++){
       kh[i].Nhap();
    }
    cout<<"\nTHONG TIN KHACH HANG :"<<endl;
    for(int i=0;i<n;i++){
        kh[i].Xuat();
    }
    string timkiem;
    cin.ignore();
    cout<<"\nNhap ten tim kiem :";
    getline(cin,timkiem);
    kh[0].TimKiemKhach(kh,n,timkiem);
   return 0;
}