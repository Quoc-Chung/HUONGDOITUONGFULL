// TH3.5. Xây dựng lớp Nguoi (Người) gồm các thuộc tính gồm họ tên, tuổi và các phương thức 
// cần thiết. Xây dựng lớp Quanly (Quản lý) dẫn xuất từ lớp Nguoi, bổ sung thêm thuộc tính snct 
// (số năm công tác), hsl (hệ số lương). Công thức tính lương là: tienluong = lcb*hsl + phucap, 
// trong đó: phucap = 3 triệu nếu snct >= 15 năm, phucap = 2 triệu nếu 5 =< snct < 15 năm và 
// phucap = 1 triệu nếu snct<5 năm.
// Viết hàm main( ) thực hiện:
// - Nhập vào n nhân viên. 
// - Tìm nhân viên có tiền lương cao nhất và nhân viên có tiền lương thấp nhất.
#include<bits/stdc++.h>
using namespace std;
class Nguoi {
private:
    string hoTen;
    int tuoi;
public:
    Nguoi(){
        hoTen="";
        tuoi=0;
    }
    void nhap() {
        cout<<"Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout<<"Nhap tuoi: ";
        cin>>tuoi;
    }
    void xuat() {
        cout<<"Ho ten: "<<hoTen<<", Tuoi: "<<tuoi<< endl;
    }
};
class Quanly:public Nguoi {
private:
    int snct; // Số năm công tác
    double hsl; // Hệ số lương
public:
    Quanly(){
        snct = hsl=0;
    }
    void nhap() {
        Nguoi::nhap();
        cout<<"Nhap so nam cong tac: ";
        cin>>snct;
        cout<<"Nhap he so luong: ";
        cin>>hsl;
    }
    double tinhTienLuong() {
        double lcb = 1.5;
        double phucap = 0.0;
        if (snct >= 15) {
            phucap = 3.0;
        } 
        else if (snct >= 5 && snct < 15) {
            phucap = 2.0;
        } 
        else {
            phucap = 1.0;
        }
        return lcb * hsl + phucap;
    }
};
int main() {
    int n;
    cout<<"Nhap so luong nhan vien: ";
    cin>>n;
    vector<Quanly>ds;
    for (int i = 0; i < n; i++) {
        cout<<"Nhap thong tin nhan vien "<<i + 1<<":"<<endl;
        Quanly nv;
        nv.nhap();
        ds.push_back(nv);
    }
    // Tìm nhân viên có tiền lương cao nhất và thấp nhất
    double maxLuong = ds[0].tinhTienLuong();
    double minLuong = ds[0].tinhTienLuong();
    int idxMaxLuong = 0;
    int idxMinLuong = 0;
    for (int i = 1; i < n; i++) {
        double luong = ds[i].tinhTienLuong();
        if (luong > maxLuong) {
            maxLuong = luong;
            idxMaxLuong = i;
        }
        if (luong < minLuong) {
            minLuong = luong;
            idxMinLuong = i;
        }
    }
    cout<<"Nhan vien co tien luong cao nhat la:"<<endl;
    ds[idxMaxLuong].xuat();
    cout<<"Nhan vien co tien luong thap nhat la:"<<endl;
    ds[idxMinLuong].xuat();
    return 0;
}


