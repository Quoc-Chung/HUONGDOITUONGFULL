/*
- Một mảng a[n] muốn lấy giá trị : a[n]
                muốn lấy địa chỉ : &a[n]
*/
#include<bits/stdc++.h>
using  namespace std;
class Tivi{
    private:
      int Ma_Hang;
      string HangSX;
      string TenTiVi;
      long long DonGia;
      int SoLuong;
    public:
      Tivi(): Ma_Hang(0) , HangSX("") , TenTiVi(" "),DonGia(0), SoLuong(0) {}
      int getMa_Hang(){
        return Ma_Hang;
      }
      friend istream& operator>>(istream& is, Tivi& tv){
         cout <<"\nNhap ma hang :";
         is>> tv.Ma_Hang;
         cout<<"\nNhap hang san xuat:";
         is.ignore();
         getline(is, tv.HangSX);
         cout<<"\nNhap ten ti vi :";
         is>> tv.TenTiVi;

         cout<<"\nNhap don gia:";
         is >>tv.DonGia;
         cout<<"\nNhap so luong:";
         is>> tv.SoLuong;
         return is;
      } 
      friend ostream& operator<<(ostream &os,Tivi& tv ){
        os <<"\nMa hang :"<<tv.Ma_Hang;
        os <<"\nHang san xuat :"<<tv.HangSX;
        os <<"\nTen ti vi :"<<tv.TenTiVi;
        os <<"\nNhap don gia :"<<tv.DonGia;
        os <<"\nSo luong :"<<tv.SoLuong;
         return os;
      }
};
class QuanLi{
    private:
      vector<Tivi> qlTivi;
    public:
      void ThemMotTiVi(Tivi &tv){
        qlTivi.push_back(tv);
      }
      void XoaTiViTheoMa(int MaHang){
        bool check =false;
        for(auto it=qlTivi.begin(); it!=qlTivi.end();it++){
            if(it->getMa_Hang()== MaHang){
                qlTivi.erase(it);
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<"\nKhong co ma hang de xoa"<<endl;
        }
      }

    void DanhSachTiVi(){
        cout<<"\nDanh sach sinh vien la:"<<endl;
        for(auto x : qlTivi){
            cout<< x <<endl;
        }
    }
    Tivi* TimKiemNhiPhan(int MaHang){
        int left = 0;
        int right = qlTivi.size()-1;
        while(left<=right){
            int mid = (left+ right) / 2;
            if(qlTivi[mid].getMa_Hang() == MaHang) {
                return &qlTivi[mid];
            }
            else if(qlTivi[mid].getMa_Hang() > MaHang){
                left = mid  +1;
            }
            else if(qlTivi[mid].getMa_Hang() < MaHang){
                right= mid -1;
            }
        }
        return nullptr;
    }
};
int main(){
   int n;
   cout<<"\nNhap so luong :";
   cin >> n;
   QuanLi qlTiVi;
   for(int i=0; i<n; i++){
     Tivi tv;
     cin >> tv;
     qlTiVi.ThemMotTiVi(tv);
   }
   qlTiVi.DanhSachTiVi();

   int MaHang;
   cout <<"\nNhap ma hang :";
   cin >>MaHang;
   
   Tivi* tv = qlTiVi.TimKiemNhiPhan(MaHang);
   if(tv != nullptr) {
    cout <<"\nTim thay ti vi .";
    cout<<(*tv);
   }
   else{
    cout<<"\nKhong tim thay ti vi "<<endl;
   }
   return 0;
}