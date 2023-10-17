#include<bits/stdc++.h>
using namespace std;
class MatHang {
     private:
          string MaHang;
          string MauSac;
          int SoLuong;
          long long Gia;
     public:
          MatHang() {
               MaHang = MauSac = "";
               SoLuong = Gia = 0;
          }
          string getMaHang() const {
               return MaHang;
          }
          string getMauSac() const {
               return MauSac;
          }
          int getSoLuong() const {
               return SoLuong;
          }
          long long getGia() const {
               return Gia;
          }
        void Nhap (ifstream &file){
          file >> MaHang;
          file >> MauSac;
          file >> SoLuong;
          file >> Gia;
        }
        void Xuat(){
            cout<<"\nMa Hang :"<<MaHang<<endl;
            cout<<"\nMauSac :"<<MauSac<<endl;
            cout<<"\nSoLuong :"<<SoLuong<<endl;
            cout<<"\nGia :"<<Gia<<endl;
        }
};
class MatHangKichThuoc : public MatHang {
private:
    string KichThuoc;
public:
    MatHangKichThuoc() {
        KichThuoc = "";
    }
    string getKichThuoc() const {
        return KichThuoc;
    }
    void Nhap(ifstream &file){
      MatHang::Nhap(file);
      file.ignore();
      file >> KichThuoc;
    }
    void Xuat(){
        MatHang::Xuat();
        cout<<"\nKichThuoc :"<<KichThuoc<<endl;
        cout<<"================================="<<endl;
    }
};
// Thống  kê  số lượng theo kích thước 
void ThongKeKichThuoc(MatHangKichThuoc *MH, int n) {
    map<string,int> ThongKe;
    cout << "Thong ke so luong theo kich thuoc" << endl;
    for (int i=0;i<n;i++) {
        string Kich_Thuoc=MH[i].getKichThuoc();
        int soLuong=MH[i].getSoLuong();
        if (ThongKe.find(Kich_Thuoc) != ThongKe.end()) {
            ThongKe[Kich_Thuoc]+=soLuong;
        } else {
            ThongKe[Kich_Thuoc]=soLuong;
        }
    }
    // In thông kê từ map
    for ( auto& pair:ThongKe) {
        cout << pair.first <<": "<<pair.second<<"san pham"<<endl;
    }
}
// Thống kê số lượng theo màu 
void ThongKeTheoMauSac(MatHangKichThuoc *MH, int n) {
    cout<<"Thong ke so luong theo mau sac:"<<endl;
    map<string,int> ThongKeMau;
    for (int i = 0; i < n; i++) {
        string mauSac = MH[i].getMauSac();
        if (ThongKeMau.find(mauSac) != ThongKeMau.end()) {
            ThongKeMau[mauSac] += MH[i].getSoLuong();
        } else {
            ThongKeMau[mauSac] = MH[i].getSoLuong();
        }
    }
    // Duyệt vòng for each sử dụng auto
    for (auto& pair : ThongKeMau) {
        cout<<"Mau "<<pair.first<<": "<<pair.second<<" san pham"<<endl;
    }
} 
//Tìm sản phẩm có mã, mầu và cỡ cho trước.
void TimSanPham(MatHangKichThuoc *MH, int n) {
    string TimMa, TimSize, TimMauStr;
    cin.ignore();
    cout << "Nhap ma san pham can tim: ";
    getline(cin , TimMa);
    cout << "Nhap mau san pham can tim: ";
    getline(cin , TimMauStr);
    cout << "Nhap kich thuoc san pham can tim (S, M, L, XL, XXL, XXXL): ";
    getline(cin,TimSize);
    bool timThay = false;
    for (int i = 0;i <n;i++) {
        if (MH[i].getMaHang() == TimMa && MH[i].getMauSac() == TimMauStr && MH[i].getKichThuoc() == TimSize) {
            cout << "Thong tin san pham tim thay:" << endl;
            MH[i].Xuat();
            timThay = true;
            break;
        }
    }
    if (!timThay) {
        cout << "Khong tim thay san pham phu hop." << endl;
    }
}
int main() {
    int n; 
    ifstream file("DSMH.txt");
    if (!file) {
        cout<<"Loi game roi khong mo duoc tep dau :((" << endl;
        return 1;
    }
    file >> n;
    MatHangKichThuoc *MH = new MatHangKichThuoc[n];
    for(int i=0;i<n;i++){
        MH[i].Nhap(file);
    }
    for(int i=0;i<n;i++){
        MH[i].Xuat();
    }
    ThongKeKichThuoc(MH,n);
    ThongKeTheoMauSac(MH,n);
    TimSanPham(MH,n);
    file.close();
    return 0;
}
