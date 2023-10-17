// TH3.7. Xây dựng lớp MH (Mặt Hàng), trong đó có các thuộc tính gồm: Mã hàng, tên hàng, 
// nhà sản xuất, số lượng, đơn giá và một số phương thức cần thiết. Xây dựng lớp MayTinh (Máy 
// Tính) dẫn xuất từ lớp MH, trong đó định nghĩa thêm các thuộc tính: Loại CPU, hệ điều hành, 
// trọng lượng và một số hàm nếu cần.
// Viết chương trình:
// - Nhập thông tin cho n đối tượng của lớp MayTinh.
// - In danh sách các máy tính có đơn giá cao nhất
#include<bits/stdc++.h>
using namespace std;
class MH {
private:
    string maHang;
    string tenHang;
    string nhaSanXuat;
    int soLuong;
    double donGia;
public:
    MH(){
        maHang =tenHang=nhaSanXuat="";
        soLuong=donGia =0;
    }
    void nhap(){
        cout<<"Nhap ma hang: ";
        cin.ignore();
        getline(cin, maHang);
        cout<<"Nhap ten hang: ";
        getline(cin, tenHang);
        cout<<"Nhap nha san xuat: ";
        getline(cin, nhaSanXuat);
        cout<<"Nhap so luong: ";
        cin>>soLuong;
        cout<<"Nhap don gia: ";
        cin>>donGia;
    }
    void xuat() {
        cout<<"Ma hang: "<<maHang<<endl;
        cout<<"Ten hang: "<<tenHang<<endl;
        cout<<"Nha san xuat: "<<nhaSanXuat<<endl;
        cout<<"So luong: "<<soLuong<<endl;
        cout<<"Don gia: "<<donGia<<endl;
    }
    double getDonGia() {
        return donGia;
    }
};
class MayTinh : public MH {
private:
    string loaiCPU;
    string heDieuHanh;
    double trongLuong;
public:
    MayTinh(){
        loaiCPU = heDieuHanh="";
        trongLuong = 0.0;
    }
    void nhap() {
        MH::nhap();
        cout << "Nhap loai CPU: ";
        cin.ignore();
        getline(cin, loaiCPU);
        cout << "Nhap he dieu hanh: ";
        getline(cin, heDieuHanh);
        cout << "Nhap trong luong (kg): ";
        cin >> trongLuong;
    }
};
int main() {
    int n;
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    vector<MayTinh> ds;
    for (int i = 0; i < n; i++) {
        cout<<"Nhap thong tin may tinh " << i + 1 << ":" << endl;
        MayTinh mayTinh;
        mayTinh.nhap();
        ds.push_back(mayTinh);
    }
    double maxDonGia = 0.0;
    int idxMaxDonGia = -1;
    for (int i = 0; i < n; i++) {
        if (ds[i].getDonGia() > maxDonGia) {
            maxDonGia = ds[i].getDonGia();
            idxMaxDonGia = i;
        }
    }
    if (idxMaxDonGia != -1) {
        cout<<"May tinh co don gia cao nhat la:" << endl;
        ds[idxMaxDonGia].xuat();
    } else {
        cout<<"Khong co may tinh nao trong danh sach." << endl;
    }
    return 0;
}
