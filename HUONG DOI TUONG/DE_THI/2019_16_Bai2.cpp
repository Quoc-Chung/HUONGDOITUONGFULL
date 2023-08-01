#include<bits/stdc++.h>
using namespace std;
int n;
/*
- Ham getline có hai tham số truyền vào :
   + cin để nhập từ bàn phím hoặc một ifstream để nhập từ tệp tin.
   + một tham chiếu tới biến string hoặc đối tượng string,
*/
class NGUOI {
private:
    string HoTen;
    int Tuoi;
public:
    friend istream& operator >> (istream& is, NGUOI& d) {
    cout << "Ho Ten: ";
    getline(is >> ws, d.HoTen); // Use ws (whitespace) to skip leading whitespaces before getline
    cout << "Tuoi: ";
    is >> d.Tuoi;
    return is;
}
   friend ostream& operator << (ostream& os, const NGUOI& d) {
        os << "\nHo Ten: " << d.HoTen << "---Tuoi: " << d.Tuoi << endl;
        return os;
    }
    string getHoTen() {
        return HoTen;
    }
    int getTuoi() {
        return Tuoi;
    }
};
class QLNV : public NGUOI {
private:
    int SoNam; // So nam cong tac
    double TienLuong; 
public:
/*
 os << static_cast<const NGUOI&>(d) : chuyển đổi biến d từ kiểu dữ liệu của lớp QLNV
 sang kiểu dữ liệu của lớp cơ sở NGUOI.
Việc này được gọi là "upcasting", là một trong hai loại chuyển đổi kiểu dữ liệu trong C++.
Upcasting cho phép ta chuyển đổi từ một lớp kế thừa (Lớp con ) về lớp cơ sở (base class)
tương ứng. 
 -->ta có thể truyền biến d dưới dạng const NGUOI& vào hàm operator<< của lớp NGUOI, và từ
đó có thể truy cập các thuộc tính của lớp cơ sở NGUOI để hiển thị thông tin của đối tượng d 
của lớp QLNV trong đoạn  mã os << static_cast<const NGUOI&>(d);.
*/
    friend istream& operator >> (istream& is, QLNV& d) {
        is >> static_cast<NGUOI&>(d); // Call the base class operator>> to input HoTen and Tuoi
        cout << "Tien Luong: ";
        is >> d.TienLuong;
        cout << "So Nam Cong Tac: ";
        is >> d.SoNam;
        return is;
    }
    friend ostream& operator << (ostream& os, const QLNV& d) {
        os << static_cast<const NGUOI&>(d); // Call the base class operator<< to display HoTen and Tuoi
        os << "Tien Luong: " << d.TienLuong << " ---So Nam Cong Tac: " << d.SoNam << " nam" << endl;
        return os;
    }
    void Tien_Luong_Trung_Binh(QLNV *x);
    void Cong_Tac_Nhieu_Nhat(QLNV *x);
};
void QLNV::Tien_Luong_Trung_Binh(QLNV *x) {
    double sumTienLuong = 0;
    for (int i = 0; i < n; i++) {
        sumTienLuong += x[i].TienLuong; // Cộng dồn lương của từng nhân viên
    }
    double averageTienLuong = sumTienLuong / n;
    cout << "Tien luong trung binh: "<<fixed<<setprecision(2)<<averageTienLuong<< endl;
}
void QLNV::Cong_Tac_Nhieu_Nhat(QLNV *x) {
    int maxSoNam = 0; // Initialize maxSoNam with the first employee's SoNam
    string maxHoTen = x[0].getHoTen(); // Initialize maxHoTen with the first employee's HoTen
    for (int i = 1; i < n; i++) {
        if (x[i].SoNam > maxSoNam) {
            maxSoNam = x[i].SoNam;
            maxHoTen = x[i].getHoTen();
        }
    }
    cout << "Nhan vien co so nam cong tac nhieu nhat: " << maxHoTen << " - " << maxSoNam << " nam" << endl;
}

int main() {
    cout << "\nNhap n: ";
    cin >> n;
    QLNV* x = new QLNV[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin nhan vien " << i + 1 << ":\n";
        cin >> x[i];
    }
    cout << "\nThong tin cua nhan vien:\n";
    for (int i = 0; i < n; i++) {
        cout << x[i];
    }
    x[0].Tien_Luong_Trung_Binh(x);
    x[0].Cong_Tac_Nhieu_Nhat(x);
    delete[] x;
    return 0;
}
