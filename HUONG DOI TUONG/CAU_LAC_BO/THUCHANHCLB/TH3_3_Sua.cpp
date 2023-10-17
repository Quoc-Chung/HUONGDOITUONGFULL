#include<bits/stdc++.h>
using namespace std;
class NGUOI {
private:
    string hoTen;
    int tuoi;
public:
    NGUOI(){
        hoTen = "";
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
        cout<<"Ho ten: "<<hoTen<<", Tuoi: "<<tuoi<<endl;
    }
};
class QLNV : public NGUOI {
private:
    int snct; // Số năm công tác
    double hs; // Hệ số lương
public:
    QLNV(){
        snct=hs=0;
    }
    void nhap() {
        NGUOI::nhap();
        cout << "Nhap so nam cong tac: ";
        cin >> snct;
        cout << "Nhap he so luong: ";
        cin >> hs;
    }
    double tinhTienLuong() {
         double lcb = 1.5; 
         double phucap = 0.2 * snct;
         return lcb * hs + phucap;
    }
    void xuat() {
        NGUOI::xuat();
        cout<<"So nam cong tac: "<<snct<<", He so luong: "<<hs<<endl;
        cout<<"Tien luong: "<<tinhTienLuong()<<" trieu VND"<<endl;
    }
};
int main() {
    int n;
    cout<<"Nhap so luong nhan vien: ";
    cin>>n;
    vector<QLNV> ds;
    for (int i = 0; i < n; i++) {
        cout<<"Nhap thong tin nhan vien "<<i + 1<<":"<<endl;
        QLNV nv;
        nv.nhap();
        ds.push_back(nv);
    }
    // Tìm nhân viên có số năm công tác nhiều nhất
    QLNV nvMaxSNCT = ds[0];
    for (int i =1;i<n;i++) {
        if (ds[i].tinhTienLuong()>nvMaxSNCT.tinhTienLuong()) {
            nvMaxSNCT = ds[i];
        }
    }
    cout << "Nhan vien co so nam cong tac nhieu nhat la:" << endl;
    nvMaxSNCT.xuat();
    // Sắp xếp danh sách nhân viên theo thứ tự lương từ cao đến thấp
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ds[i].tinhTienLuong() > ds[j].tinhTienLuong()){
                auto tmp = ds[i];
                ds[i]=ds[j];
                ds[j]=tmp;
            }
        }
    }
    cout << "Danh sach nhan vien theo thu tu luong giam dan:" << endl;
    for (QLNV nv : ds) {
        nv.xuat();
    }
    return 0;
}


