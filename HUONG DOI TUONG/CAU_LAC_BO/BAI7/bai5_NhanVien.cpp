// Xây dựng lớp Nguoi:
//  Thuộc tính (private): họ tên, tuổi
//  Phương thức (public): Nhập, xuất và các phương thức khác
// Xây dựng lớp Nhanvien(Nhân viên) dẫn xuất từ lớp Nguoi
//  Thuộc tính (private): bổ sung thêm snct (số năm công tác), hsl (hệ 
// số lương)
//  Phương thức (public): tính tiền lương, biết: tienluong = 
// lcb*hsl+phucap, trong đó: lcb là 1.5 triệu, phucap = 0.2 triệu*snct.
// Viết hàm main() thực hiện:
//  Nhập vào n nhân viên. 
//  Tìm nhân viên có số năm công tác nhiều nhất.
//  In danh sách nhân viên theo thứ tự lương từ cao đến thấp.
#include<bits/stdc++.h>
using namespace std;
class Nguoi {
    private:
        string HoTen;
        int Tuoi;
    public:
        Nguoi() {
            HoTen = "";
            Tuoi = 0;
        }
        void Nhap() {
            cout<<"Nhap ho ten: ";
            cin.ignore();
            getline(cin, HoTen);
            cout<<"Nhap Tuoi: ";
            cin>>Tuoi;
        }
        void Xuat() {
            cout<<"Ho ten: "<< HoTen<< endl;
            cout<<"Tuoi: "<<Tuoi<< endl;
        }   
};
class Nhanvien : public Nguoi {
    private:
        int So_Nam_Cong_Tac; 
        double He_So_Luong;
    public:
        Nhanvien() {
            So_Nam_Cong_Tac = 0;
            He_So_Luong = 0;
        }
        void Nhap() {
            Nguoi::Nhap();
            cout<<"Nhap so nam cong tac: ";
            cin>>So_Nam_Cong_Tac;
            cout<<"Nhap he so luong: ";
            cin>>He_So_Luong;
        }
        double TinhLuong() {
            double Luong_Co_Ban = 1.5;
            double PhuCap = 0.2 * So_Nam_Cong_Tac;
            double TienLuong = Luong_Co_Ban * He_So_Luong + PhuCap;
            return TienLuong;
        }
};
int main() {
    int n;
    cout<<"Nhap so luong nhan vien: ";
    cin>>n;
    Nhanvien ds[n];
    for (int i=0;i<n;i++) {
        cout<<"Nhap thong tin nhan vien thu "<<i + 1<<":"<<endl;
        ds[i].Nhap();
    }
    int max = 0;
    int Chi_So= -1;
    for (int i=0;i<n;i++) {
        if (ds[i].TinhLuong()>max) {
            max=ds[i].TinhLuong();
            Chi_So= i;
        }
    }
    if (Chi_So!= -1) {
        cout<<"Nhan vien co so nam cong tac nhieu nhat:"<<endl;
        ds[Chi_So].Xuat();
    } else {
        cout<<"Khong co nhan vien nao trong danh sach."<<endl;
    }
    for (int i=0;i<n-1;i++) {
        for (int j=0;j<n-i-1;j++) {
            if (ds[j].TinhLuong()<ds[j+1].TinhLuong()) {
                swap(ds[j],ds[j+1]);
            }
        }
    }
    cout<<"Danh sach nhan vien theo thu tu luong tu cao den thap:" << endl;
    for (int i=0;i<n;i++) {
        ds[i].Xuat();
        cout<<"Luong:"<<ds[i].TinhLuong()<<"trieu dong."<<endl;
    }
    return 0;
}


