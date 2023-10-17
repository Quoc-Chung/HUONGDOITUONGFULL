// 6. Xây dựng lớp Xe, trong đó có các thuộc tính gồm: Biển số xe và trọng lượng của xe
// (tính theo tấn). Xây dựng lớp XeCon dẫn xuất từ lớp Xe, trong đó định nghĩa thêm thuộc tính: 
// Số chỗ ngồi. Trong lớp trên có thể định nghĩa thêm một số hàm thành phần nếu cần thiết.
// Viết chương trình:
// - Nhập thông tin cho n xe con và m xe tải (n và m được nhập từ bàn phím).
// - In danh sách các xe con có trọng lượng dưới 1 tấn và có không quá 5 chỗ ngồi
#include<bits/stdc++.h>
using namespace std;
class Xe {
private:
    string bienSoXe;
    double trongLuong;
public:
    Xe(){
        bienSoXe = "";
        trongLuong = 0.0;
    }
    double gettrongLuong(){
        return trongLuong;
    }
    void nhap() {
        cout << "Nhap bien so xe: ";
        cin.ignore();
        getline(cin, bienSoXe);
        cout<<"Nhap trong luong (tấn): ";
        cin>>trongLuong;
    }
    void xuat() {
        cout<<"Bien so xe: "<<bienSoXe<<", Trong luong (tan): "<<trongLuong<<endl;
    }
};
class XeCon : public Xe {
private:
    int soChoNgoi;
public:
    XeCon(){
        soChoNgoi = 0;
    }
    void nhap() {
        Xe::nhap();
        cout << "Nhap so cho ngoi: ";
        cin >> soChoNgoi;
    }
    int getSoChoNgoi() {
        return soChoNgoi;
    }
};
int main() {
    int n, m;
    cout<<"Nhap so luong xe con:";
    cin>>n;
    cout<<"Nhap so luong xe tai:";
    cin>>m;
    vector<XeCon> danhSachXeCon;
    vector<Xe> danhSachXeTai;
    for (int i=0;i<n;i++) {
        cout<<"Nhap thong tin xe con "<<i+1<<":"<<endl;
        XeCon xeCon;
        xeCon.nhap();
        danhSachXeCon.push_back(xeCon);
    }
    for (int i=0;i<m;i++) {
        cout<<"Nhap thong tin xe tai "<<i+1<<":"<<endl;
        Xe xeTai;
        xeTai.nhap();
        danhSachXeTai.push_back(xeTai);
    }
    cout << "Danh sach cac xe con co trong luong duoi 1 tan va co khong qua 5 cho ngoi:" << endl;
    int flag =0;
    for (XeCon xe : danhSachXeCon) {
        if (xe.getSoChoNgoi() <= 5 && xe.gettrongLuong() < 1.0) {
            xe.xuat();
            flag++;
        }
    }
    if(flag==0){
        cout<<"\nKhong co xe nao thoa."<<endl;
    }
    return 0;
}
