#include<bits/stdc++.h>
using namespace std;
class DIEMTHI{
  private :
    int MaMon;
    string TenMon;
    int SoTinChi;
    float DiemThi;
    float DiemQuaTrinh;
  public:
    DIEMTHI(): MaMon(0), SoTinChi(0), DiemThi(0), DiemQuaTrinh(0),TenMon(""){}
    friend istream& operator >> (istream&is, DIEMTHI &dt){
        cout <<"\nNhap ma mon:";
        is>> dt.MaMon;
        cout <<"\nNhap ten mon :";
        is.ignore();
        getline(is, dt.TenMon);
        cout <<"\nNhap so tin chi :";
        is>>dt.SoTinChi;
        cout <<"\nNhap diem thi:";
        is>> dt.DiemThi;
        cout <<"\nDiem qua trinh :";
        is>>dt.DiemQuaTrinh;
        return is;
    }
    friend ostream& operator<<(ostream& os, DIEMTHI &dt){
        os<<"\nMa mon :"<<dt.MaMon;
        os<<"\nTen mon :"<<dt.TenMon;
        os<<"\nSo tin chi :"<<dt.SoTinChi;
        os<<"\nDiem thi :"<<dt.DiemThi;
        os<<"\nDiem qua trinh :"<<dt.DiemQuaTrinh;
        return os;
    }
    float DiemBinhQuan(){
        return DiemThi*0.6 +DiemQuaTrinh*0.4;
    }
    void SapXep(DIEMTHI *dt,int n){
        for (int i=0;i<n;i++){
           for (int  j =0; j <n ;j++){
            if(dt[i].DiemBinhQuan() < dt[j].DiemBinhQuan()){
                swap(dt[i],dt[j]);
            }
           }
        }
    }
    void Diembinhquannhohon4(DIEMTHI *dt,int n){
        int dem = 0;
         for (int i=0;i<n;i++){
            if(dt[i].DiemBinhQuan() < 4){
                dem++;

            }
         }
         if(dem >0){
              cout <<"\nSo sinh vien co diem binh quan <4 la :"<<dem;
         }
         else {
            cout <<"\nKhong co sinh vien co diem binh quan < 4."<<endl;
         }
    }
    void TongDiem(DIEMTHI *dt,int n){
        float Tu =0, mau = 0;
        float Tong =0;
        for (int i=0;i<n;i++){
          Tu += ( dt[i].DiemThi*dt[i].SoTinChi);
          mau +=dt[i].SoTinChi;
        }
        Tong = Tu / mau;
        cout <<"\nDiem tong ket la :"<<fixed<<setprecision(2)<<Tong<<endl;
    }
};

int main() {
    int n;
    cout << "Nhap so luong mon hoc: ";
    cin >> n;

    DIEMTHI* dsDiem = new DIEMTHI[n];
    for (int i = 0; i < n; ++i) {
        cout << "\nNhap thong tin cho mon hoc thu " << i + 1 << ":";
        cin >> dsDiem[i];
    }
    // Hiển thị thông tin của các môn học
    cout << "\nDanh sach mon hoc vua nhap: ";
    for (int i = 0; i < n; ++i) {
        cout << dsDiem[i];
    }

    // Sắp xếp theo điểm trung bình từ thấp đến cao
    dsDiem[0].SapXep(dsDiem, n);
    cout << "\nDanh sach mon hoc sau khi sap xep theo diem trung binh:";
    for (int i = 0; i < n; ++i) {
        cout << dsDiem[i];
    }

    // In ra số lượng sinh viên có điểm trung bình dưới 4
    dsDiem[0].Diembinhquannhohon4(dsDiem,n);
    dsDiem[0].TongDiem(dsDiem,n);
    return 0;
}