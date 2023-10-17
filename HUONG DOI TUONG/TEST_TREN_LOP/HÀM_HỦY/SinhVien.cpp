#include<bits/stdc++.h>
using namespace std;
class SinhVien{
  public :
    string HoTen;
    float Diem;
    int masv;
  public :
    SinhVien(){}
    SinhVien(string& ht, int& masv, float diem)
       : HoTen(ht), masv(masv), Diem(diem) {}
    friend istream& operator>>(istream& is, SinhVien &sv){
         cout<<"\nNhap ma sinh vien:";
         is >> sv.masv;
         cout<<"\nNhap ho ten:";
         is.ignore();
         getline(is,sv.HoTen);
         cout<<"\nNhap diem:";
         is >> sv.Diem;
         return is;
    }
    friend ostream& operator<<(ostream& os, SinhVien &sv){
      os <<"\nMa sinh vien:"<<sv.masv;
      os <<"\nHo ten:"<<sv.HoTen;
      os <<"\nDiem:"<<sv.Diem;
      return os;
    }
};
class MonHoc {
private:
    int n;
    SinhVien* sv; // Con trỏ để lưu trữ danh sách sinh viên
public:
   // Cap phat bo nho dong cho SinhVien
    MonHoc(int n) : n(n) {
        sv = new SinhVien[n];
        if (sv == nullptr) {
            cout << "\nKhong khoi tao duoc";
            exit(1);
        }
    }
    //Giải phóng bo nho
    ~MonHoc() {
        delete[] sv; // Giải phóng bộ nhớ khi đối tượng MonHoc bị hủy
    }
   // Nhập danh sách sinh viên 
    void NhapSinhVien() {
        for (int i = 0; i < n; i++) {
            cin >> sv[i];
        }
    }
   // Hiển thị danh sách sinh vien
    void HienThiDanhSachSinhVien() {
        for (int i = 0; i < n; i++) {
            cout << "Sinh vien thu " << i + 1 << ":" << endl;
            cout << sv[i] << endl;
        }
    }
};
int main(){
  int n;
  cout<<"\nNhap so hoc sinh:";
  cin >>n;

  MonHoc x(n);
  x.NhapSinhVien();
  x.HienThiDanhSachSinhVien();
  return 0;

}