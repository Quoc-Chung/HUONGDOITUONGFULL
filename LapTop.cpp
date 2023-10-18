#include<bits/stdc++.h>
using namespace std;
class Laptop{
  public:
    int Ma_May;
    string HangSX;
    string TenMay;
    string CauHinh;
    long long Don_Gia;
    int So_Luong;
public: 
        friend istream& operator>>(istream& is, Laptop &lt){
        cout << "\nNhap Ma May:";
        is >> lt.Ma_May;
        is.ignore(); // Xóa dấu xuống dòng còn tồn tại trong bộ đệm.  
        cout << "\nNhap Hang San Xuat:";
        getline(is, lt.HangSX);
        cout << "\nNhap Ten May  :";
        getline(is, lt.TenMay);
        cout << "\nNhap Cau Hinh:";
        getline(is, lt.CauHinh);
        cout << "\nNhap Don Gia :";
        is >> lt.Don_Gia;
        cout << "\nNhap So Luong:";
        is >> lt.So_Luong;
        return is;
    }
    friend ostream& operator<<(ostream& os, Laptop &lt){
        os << "\nMa May: " << lt.Ma_May << endl;
        os << "Hang San Xuat: " << lt.HangSX << endl;
        os << "Ten May: " << lt.TenMay << endl;
        os << "Cau Hinh: " << lt.CauHinh << endl;
        os << "Don Gia: " << lt.Don_Gia << endl;
        os << "So luong: " << lt.So_Luong << endl;
        return os;
    }
};
class QuanLiLapTop : public Laptop{
protected: 
    vector<Laptop> vtLapTop;
public :
    void NhapMotLapTop(Laptop &ltx) {
        cin >> ltx;
    }
    void NhapDanhSach(vector<Laptop> &vt, int &n) {
        cout << "\nNhap so lap top:";
        cin >> n;
        vt.resize(n); // Đặt kích thước của vector vt thay vì vtLapTop
        for (int i = 0; i < n; i++) {
            cout << "\nNHAP LAP TOP THU:" << i + 1 << endl;
            NhapMotLapTop(vt[i]); // Sử dụng vt thay vì vtLapTop
        }
    }
    void DanhSachLap(vector<Laptop> lt){
        for (auto x : lt){
            cout << x;
        }
    }
        void TongGiaTriLaptonKho(string &HangTonKho, vector<Laptop> ltx) {
        long long Tong = 0;
        cout << "\nNhap hang ton kho :";
        cin.ignore();
        getline(cin, HangTonKho);
        for (int i = 0; i < ltx.size(); i++) { // Sử dụng ltx.size() thay vì vtLapTop.size()
            if (HangTonKho == ltx[i].HangSX) {
                Tong += ltx[i].So_Luong * ltx[i].Don_Gia;
            }
        }
        cout << "\nGia tri hang " << HangTonKho << " la :" << Tong << endl;
    }
};
int main(){
    QuanLiLapTop quanLi;
    vector<Laptop> danhSachLapTop;
    int n;

    quanLi.NhapDanhSach(danhSachLapTop, n);
    quanLi.DanhSachLap(danhSachLapTop);

    string HangTonKho;
    quanLi.TongGiaTriLaptonKho(HangTonKho,danhSachLapTop);

    return 0;
}
