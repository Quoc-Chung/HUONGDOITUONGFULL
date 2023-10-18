#include<bits/stdc++.h>
using namespace std;
class Laptop{
  private :
    int Ma_May;
    string Hang;
    string TenMay;
    string CauHinh;
    long long DonGia;
    int SoLuong;
  public:
    int getMa_May(){
        return Ma_May;
    }
    string getHang(){
        return Hang;
    }
    long long getDonGia(){
        return DonGia;
    }
    int getSoLuong(){
        return SoLuong;
    }
    Laptop(): Ma_May(0) , Hang(""),TenMay(""),CauHinh(""),DonGia(0) , SoLuong(0) {}
    friend istream& operator>>(istream& is , Laptop& lt){
        cout<<"\nNhap ma may :";
        is>>lt.Ma_May;
        cout<<"\nNhap hang :";
        is.ignore();
        getline(is, lt.Hang);
        cout<<"\nNhap Ten may :";
        getline(is, lt.TenMay);
        cout<<"\nNhap cau hinh :";
        getline(is,lt.CauHinh);
        cout<<"\nNhap Don Gia:";
        is >> lt.DonGia;
        cout<<"\nNhap So Luong :";
        is >> lt.SoLuong;
        return is;
    }
    friend ostream& operator<< (ostream& os , Laptop& lt){
        os << "\nMa May: " << lt.Ma_May << endl;
        os << "Hang San Xuat: " << lt.Hang << endl;
        os << "Ten May: " << lt.TenMay << endl;
        os << "Cau Hinh: " << lt.CauHinh << endl;
        os << "Don Gia: " << lt.DonGia << endl;
        os << "So luong: " << lt.SoLuong << endl;
        return os;
    } 
};

class QuanLi{
    private:
      vector<Laptop> qlLapTop; 
    public:
      void ThemMotLapTop(Laptop &lt){
        qlLapTop.push_back(lt);
     }
      long long TongGiaTriLapTop(string hang){
        long long TongGiaTri = 0;
        for(int i=0;i<qlLapTop.size();i++){
            if(qlLapTop[i].getHang() == hang){
                TongGiaTri += qlLapTop[i].getSoLuong() * qlLapTop[i].getDonGia();
            }
        }
       return TongGiaTri;
      }

      void InLapTop(){
        for (auto it=qlLapTop.begin();it!=qlLapTop.end();it++){
            cout<<(*it)<<endl;
        }
      }
    Laptop* TimLaptopTheoMa(int maMay) {
    int left = 0;
    int right = qlLapTop.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (qlLapTop[middle].getMa_May() == maMay) {
            return &qlLapTop[middle];
        } else if (qlLapTop[middle].getMa_May() < maMay) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }
    return nullptr;
 }
};

int main() {
    QuanLi quanLiLapTop;
    int n; 
    cout << "Nhap so luong laptop: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        Laptop laptop;
        cout << "Nhap thong tin cho laptop thu " << i + 1 << ":\n";
        cin >> laptop;
        quanLiLapTop.ThemMotLapTop(laptop);
    }

    /* - Hiển thị thông tin của tất cả các Lap top - */
    cout << "Danh sach laptop:\n";
    quanLiLapTop.InLapTop();

   /* - Tính tổng qía trị lap top của một hãng cụ thể - */
    string hangCanTinh;
    cout << "Nhap hang can tinh tong gia tri: ";
    cin.ignore();
    getline(cin, hangCanTinh);
    long long tongGiaTri = quanLiLapTop.TongGiaTriLapTop(hangCanTinh);
    cout << "Tong gia tri cua laptop cua hang " << hangCanTinh << " la: " << tongGiaTri << endl;

    /* - Tìm kiếm lap top - */
    int maTimKiem;
    cout << "Nhap ma may de tim kiem: ";
    cin >> maTimKiem;
    /* - Khai báo con trỏ kiểu laptop - */
    Laptop* laptopTimThay = quanLiLapTop.TimLaptopTheoMa(maTimKiem);

    if (laptopTimThay != nullptr) {
        cout << "Laptop tim thay: " << *laptopTimThay << endl;
    } else {
        cout << "Khong tim thay laptop co ma may " << maTimKiem << endl;
    }
    return 0;
}
