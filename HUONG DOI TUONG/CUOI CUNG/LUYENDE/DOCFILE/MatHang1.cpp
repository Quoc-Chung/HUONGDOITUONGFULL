#include<bits/stdc++.h>
using namespace std;
class QLH {
private:
    int MaHang;
    string TenHang;
    string XuatXu;
    int LoaiHang; // Có ba loại hàng là 1 2 3
    int SoLuong;
public:
    void Nhap(ifstream &file) {
        file >> MaHang;
        file.ignore(); // Loại bỏ ký tự xuống dòng
        getline(file, TenHang);
        getline(file, XuatXu);
        file >> LoaiHang >> SoLuong;
    }
    void In() {
        cout << "\nMa Hang: " << MaHang;
        cout << "\nTen Hang: " << TenHang;
        cout << "\nXuat Xu: " << XuatXu;
        cout << "\nLoai Hang: " << LoaiHang;
        cout << "\nSo Luong: " << SoLuong;
    }
    int getLoaiHang() {
        return LoaiHang;
    }
    int getSoLuong() {
        return SoLuong;
    }
    string getTenHang() {
        return TenHang;
    }
};
class DIENTU : public QLH {
private:
    int TGBH; // Thời gian bảo hành  tính bằng tháng

public:
    int getTGBH() {
        return TGBH;
    }
    void Nhap(ifstream &file) {
        QLH::Nhap(file);
        file >> TGBH;
    }
    void In() {
        QLH::In();
        cout << "\nThoi Gian Bao Hanh: " << TGBH;
    }
    void ThongKe(DIENTU *dt, int n) {
        int dem1 = 0, dem2 = 0, dem3 = 0;
        int tong1 = 0, tong2 = 0, tong3 = 0;
        for (int i = 0; i < n; i++) {
            if (dt[i].getLoaiHang() == 1 && dt[i].getTGBH() > 12) {
                dem1++;
                tong1 += dt[i].getSoLuong();
            }
            if (dt[i].getLoaiHang() == 2 && dt[i].getTGBH() > 12) {
                dem2++;
                tong2 += dt[i].getSoLuong();
            }
            if (dt[i].getLoaiHang() == 3 && dt[i].getTGBH() > 12) {
                dem3++;
                tong3 += dt[i].getSoLuong();
            }
        }
        cout << "\nLoai hang 1 co " << dem1 << " mat hang va So Luong la " << tong1 << endl;
        cout << "\nLoai hang 2 co " << dem2 << " mat hang va So Luong la " << tong2 << endl;
        cout << "\nLoai hang 3 co " << dem3 << " mat hang va So Luong la " << tong3 << endl;
    }
    void ThoiGianBaoHanhMax(DIENTU *dt, int n) {
        int max = 0;
        string MatHangThoa;
        for (int i = 0; i < n; i++) {
            if (max < dt[i].getTGBH()) {
                max = dt[i].getTGBH();
                MatHangThoa = dt[i].getTenHang();
            }
        }
        cout << "\nTen hang co thoi gian bao hanh max la: " << MatHangThoa << endl;
    }
};
int main() {
    int n;
    ifstream file("Ma_hang.txt");
    if (!file){
        cout << "Khong the mo tep danh_sach_hang.txt" << endl;
        return 1;
    }
    file >> n;
    DIENTU *dt = new DIENTU[n];   
    for (int i = 0; i < n; i++) {
        dt[i].Nhap(file);
    }
    for (int i = 0; i < n; i++) {
        dt[i].In();
    } 
    dt[0].ThongKe(dt, n); // Gọi hàm với đối số đúng

    dt[0].ThoiGianBaoHanhMax(dt, n);
    file.close();
    return 0;
}
