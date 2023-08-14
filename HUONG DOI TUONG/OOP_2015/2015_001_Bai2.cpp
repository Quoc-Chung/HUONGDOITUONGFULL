// Xây dựng lớp Môn học :
// Thuộc tính: mã môn, tên môn, số tín chỉ
// Phương thức:Nhập, xuất, vác phương thức khác
// Xây dựng lớp ĐKHP (Đăng kí học phần) của sinh viên gồm có thuộc tính: mã sinh viên,
// tên sinh viên, mảng check để lưu trữ thông tin các môn học sinh viên đăng ký hoặc 
// không( đăng ký thì =1, không đăng ký =0).
// Viết hàm main() thực hiện:
// Nhập vào m môn học cho trước.
// Nhập bản đăng ký học phần của n sinh viên.
// Hãy cho biết mỗi sinh viên đã đăng kí bao nhiêu tín chỉ.
// Nhập vào một môn và thống kê số sinh viên đã đăng kí môn học đó đồng thời in danh sách 
// lớp cho môn học. 
#include <iostream>
#include <string>
using namespace std;
class MonHoc {
   private:
      int MaMon;
      string TenMon;
      int SoTinChi;
   public:
    // Hàm tạo không có đối số
    MonHoc() {
        MaMon = SoTinChi = 0;
        TenMon = "";
    }
   // Viêt hàm nhập class MonHoc
    void Nhap() {
        cout << "\nNhap Ma Mon: ";
        cin >> MaMon;
        cout << "\nNhap Ten Mon: ";
        cin.ignore();
        getline(cin, TenMon);

        cout << "\nNhap So Tin Chi: ";
        cin >> SoTinChi;
    }
    void Xuat() {
        cout << "\nMa Mon: " << MaMon;
        cout << "\nTen Mon: " << TenMon;
        cout << "\nSo Tin Chi: " << SoTinChi;
    }
    int getSoTinChi() {
        return SoTinChi;
    }
};
class DKHP {
  private:
    int MaSV;
    string TenSV;
    bool* check;
    int SoMon;
  public:
     // Hàm tạo mặc định không có đối số
    DKHP() {
        MaSV = 0;
        TenSV = "";
        SoMon = 0;
        check = nullptr;
    }
    // Hàm tạo không có đối số truyền vào  
    DKHP(int SoMon) {
        MaSV = 0;
        TenSV = "";
        this->SoMon = SoMon;
        check = new bool[SoMon];
        for (int i = 0; i < SoMon; i++) {
            check[i] = false;
        }
    }
    void Nhap() {
        cout << "\nNhap Ma Sinh Vien: ";
        cin >> MaSV;

        cout << "\nNhap Ten Sinh Vien: ";
        cin.ignore();
        getline(cin, TenSV);

        cout << "\nNhap bản đăng ký học phần (1 - Đăng ký, 0 - Không đăng ký):\n";
        for (int i = 0; i < SoMon; i++) {
            cout << "Mon hoc " << i + 1 << ": ";
            cin >> check[i];
        }
    }
    void Xuat() {
        cout << "\nMa Sinh Vien: " << MaSV;
        cout << "\nTen Sinh Vien: " << TenSV;
        cout << "\nDang ky hoc phan:\n";
        for (int i = 0; i < SoMon; i++) {
            if (check[i]) {
                cout << "Mon hoc " << i + 1 << endl;
            }
        }
    }
    int TinhSoTinChi(MonHoc* danhSachMon) {
        int soTinChi = 0;
        for (int i = 0; i < SoMon; i++) {
            if (check[i]) {
                soTinChi += danhSachMon[i].getSoTinChi();
            }
        }
        return soTinChi;
    }
    bool DangKyMonHoc(int maMon) {
        if (maMon >= 1 && maMon <= SoMon) {
            return check[maMon - 1];
        }
        return false;
    }
     string getTenSV() {
        return TenSV;
    }
};
int main() {
    int m, n;

    cout << "Nhap so luong mon hoc m: ";
    cin >> m;
    MonHoc* danhSachMon = new MonHoc[m];
    for (int i = 0; i < m; i++) {
        cout << "\nNhap thong tin mon hoc " << i + 1 << ":";
        danhSachMon[i].Nhap();
    }
    cout << "\nNhap so luong sinh vien n: ";
    cin >> n;
    DKHP* danhSachSV = new DKHP[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin sinh vien " << i + 1 << ":";
        danhSachSV[i] = DKHP(m);
        danhSachSV[i].Nhap();
    }

    // Cho biết mỗi sinh viên đã đăng kí bao nhiêu tín chỉ
    cout << "\nMoi sinh vien da dang ky bao nhieu tin chi:\n";
    for (int i = 0; i < n; i++) {
        int soTinChi = danhSachSV[i].TinhSoTinChi(danhSachMon);
        cout << "Sinh vien " << i + 1 << ": " << soTinChi << " tin chi\n";
    }

    // Nhập vào một môn và thống kê số sinh viên đã đăng kí môn học đó đồng thời in danh sách lớp cho môn học
    int maMon;
    cout << "\nNhap ma mon hoc can tim kiem: ";
    cin >> maMon;

    if (maMon >= 1 && maMon <= m) {
        cout << "\nThong ke danh sach sinh vien dang ky mon hoc " << maMon << ":\n";
        for (int i = 0; i < n; i++) {
            if (danhSachSV[i].DangKyMonHoc(maMon)) {
                cout << "Sinh vien " << i + 1 << ": " << danhSachSV[i].getTenSV() << endl;
            }
        }
    } else {
        cout << "\nKhong co mon hoc co ma " << maMon << " trong danh sach!\n";
    }
    delete[] danhSachMon;
    delete[] danhSachSV;
    return 0;
}
