#include<bits/stdc++.h>
#include<list>
using namespace std;
class NhanVien{
  private :
    int Ma;
    string HoTen;
    int NamSinh;
    long long Luong ;
  public :
  // Xây dựng phương thức lấy mã :
    int getMa(){
      return Ma;
    }
  friend  istream& operator>>(istream& is,NhanVien& nv){
      cout<<"\nNhap ma nhan vien:"; 
      is>>nv.Ma;
      cout<<"\nNhap Ho va Ten:";
      is.ignore();
      getline(is,nv.HoTen);
      cout<<"\nNhap Nam Sinh:";
      cin>>nv.NamSinh;
      cout<<"\nNhap Luong:";
      cin >> nv.Luong;
      return is;
    }
  friend ostream& operator<<(ostream& os,NhanVien& nv){
     os<<"\nMa nhan vien:"<<nv.Ma<<endl;
     os<<"\nHo va ten :"<<nv.HoTen<<endl;
     os<<"\nNam Sinh:"<<nv.NamSinh<<endl;
     os<<"\nLuong:"<<nv.Luong<<endl;
     return os;
  }
};
class DanhSachNhanVien: public NhanVien{
  protected:
      list<NhanVien> dsNhanVien;
  public :
      DanhSachNhanVien (){
      }
      void ThemMotNhanVien(){
        NhanVien tmp;
        cout<<"\nNhap mot nhan vien :";
        cin >> tmp;
        dsNhanVien.push_back(tmp);
      }
      void XoaMotNhanVien(int maXoa){
         for (auto it =dsNhanVien.begin() ; it !=dsNhanVien.end() ;it++){
          if(maXoa == (*it).getMa()){
            dsNhanVien.erase(it);
          }
         }
      }
      void InDanhSachNhanVien(){
        int cnt =1;
            for (auto it =dsNhanVien.begin() ; it !=dsNhanVien.end() ;it++){
              cout<<"\nDanh Sach Nhan vien thu "<<cnt++<<": "<<endl;
              cout<< *(it);
            }
      }
};
int main(){
      DanhSachNhanVien danhSachNV;
      // Gọi hàm ThemMotNhanVien để thêm một nhân viên vào danh sách
      int n ;
      cout<<"\nNhap so nhan vien :";
      cin >>n;
      for (int i=1;i<n;i++){
           danhSachNV.ThemMotNhanVien();
      }
       danhSachNV.InDanhSachNhanVien();

      // Gọi hàm XoaMotNhanVien để xóa một nhân viên theo mã
      int maXoa;
      cout << "Nhap ma nhan vien can xoa: ";
      cin >> maXoa;
      danhSachNV.XoaMotNhanVien(maXoa);
      danhSachNV.InDanhSachNhanVien();
      return 0;
}
