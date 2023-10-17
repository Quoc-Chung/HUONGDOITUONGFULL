#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
protected:
    int MaSV;
    string HoTen;
    int Ngay, Thang, Nam;
    string GioiTinh;

public:
    SinhVien() {}
    void Nhap() {
        cout << "\nNhap ma:";
        cin >> MaSV;
        cout << "\nNhap ho ten:";
        cin.ignore();
        getline(cin, HoTen);
        cout << "\nNhap ngay sinh:";
        cin >> Ngay >> Thang >> Nam;
        cout << "\nNhap gioi tinh:";
        cin.ignore();
        getline(cin, GioiTinh);
    }
    void Xuat() {
        cout << "\nMa sinh vien: " << MaSV;
        cout << "\nHo ten: " << HoTen;
        cout << "\nNgay sinh: " << Ngay << "/" << Thang << "/" << Nam;
        cout << "\nGioi tinh: " << GioiTinh;
    }
};
class HocPhan : public SinhVien {
protected:
    string TenHocPhan;
    float DiemCC, DiemKT, DiemBTL, DiemThi;
public:
    HocPhan() {}
    void Nhap() {
        SinhVien::Nhap();
        cout << "\nNhap Ten Hoc Phan :";
        cin.ignore();
        getline(cin, TenHocPhan);
        cout << "\nNhap cac diem :";
        cin >> DiemCC >> DiemKT >> DiemBTL >> DiemThi;
    }
    void Xuat() {
        cout << "\nTen Hoc Phan: " << TenHocPhan;
        cout << "\nDiem CC: " << DiemCC;
        cout << "\nDiem KT: " << DiemKT;
        cout << "\nDiem BTL: " << DiemBTL;
        cout << "\nDiem Thi: " << DiemThi;
    }
};
class KetQua : public HocPhan {
private:
    float DiemTrungBinh;
public:
    KetQua() {}

    float TinhDiemTB() {
        DiemTrungBinh = (DiemCC + DiemKT * 2 + 2 * DiemBTL + 5 * DiemThi) / 10;
        return DiemTrungBinh;
    }
    float LayDiemTrungBinh() const {
        return DiemTrungBinh;
    }
    void Xuat() {
        SinhVien::Xuat();
        cout << "\nDiem Trung Binh la: " << DiemTrungBinh << endl;
    }
};
int main() {
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    vector<KetQua> danhSachSinhVien;

    for (int i = 0; i < n; i++) {
        KetQua sv;
        cout << "\nNhap thong tin sinh vien thu " << i + 1 << ":\n";
        sv.HocPhan::Nhap();
        sv.TinhDiemTB(); // Calculate the average score
        danhSachSinhVien.push_back(sv);
    }
    cout << "\nDanh sach sinh vien:\n";
    for (int i = 0; i < n; i++) {
        cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
        danhSachSinhVien[i].Xuat();
    }

cout << "\nDANH SACH CO DIEM TRUNG BINH > 8:" << endl;
for (int i = 0; i < n; i++) {
    if (danhSachSinhVien[i].LayDiemTrungBinh() > 8) {
        cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
        danhSachSinhVien[i].Xuat();
    }
}
float max = 0;
for (int i = 0; i < n; i++) {
    if (max < danhSachSinhVien[i].LayDiemTrungBinh()) {
        max = danhSachSinhVien[i].LayDiemTrungBinh();
    }
}
cout << "\nDANH SACH CO DIEM TB MAX LA :" << endl;
for (int i = 0; i < n; i++) {
    if (max == danhSachSinhVien[i].LayDiemTrungBinh()) {
        cout << "\nThong tin sinh vien thu " << i + 1 << ":\n";
        danhSachSinhVien[i].Xuat();
        break;
    }
}
}