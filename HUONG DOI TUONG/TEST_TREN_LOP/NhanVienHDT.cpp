#include<bits/stdc++.h>
#include <iomanip> 
using namespace std;
struct NhanVien {
    int MaMV;
    string Name;
     int ThuNhap;
};
struct ThiSinh{
    string Ten;
    float Diem;
};

void NhapDay(int *&a, int n) {
    a = new int[n]; // Tạo mảng mới cho a
    for (int i = 0; i < n; i++) {
        cout << "\nNhap a[" << i + 1 << "]: ";
        cin >> a[i];
    }
}
void In(int *a, int n) {
    cout << "\nDay so nguyen la:\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
float TBC(int *a, int n) {
    int Tong = 0;
    for (int i = 0; i < n; i++) {
        Tong += a[i];
    }
    float tb = (float)(Tong) / n;
    return tb;
}
void NhapDay(NhanVien *&nv, int m, int *&luong) {
    nv = new NhanVien[m]; // Tạo mảng mới cho nv
    luong = new int[m];
    cout << "\nNhap danh sach nhan vien:\n";
    for (int i = 0; i < m; i++) {
        cout << "\nNhap ma nhan vien: ";
        cin >> nv[i].MaMV;
        cin.ignore();
        cout << "\nNhap ten nhan vien: ";
        getline(cin, nv[i].Name);
        cout << "\nNhap thu nhap: ";
        cin >> nv[i].ThuNhap;
        luong[i] = nv[i].ThuNhap;
    }
}
void InNhapDay(NhanVien *nv, int m) {
    cout << "\nDanh sach nhan vien:\n";
    for (int i = 0; i < m; i++) {
        cout << "\nMa nhan vien: " << nv[i].MaMV;
        cout << "\nTen nhan vien: " << nv[i].Name;
        cout << "\nThu nhap: " << nv[i].ThuNhap << endl;
    }
}
istream& operator>>(istream &cin,ThiSinh &ts){
    return cin;
}
void NhapDay(ThiSinh *&ts,int k){
    ts =new ThiSinh[k];
    cout <<"\nNhap Danh Sach Thi Sinh:";
    for (int i=0;i<k;i++){
      cout<<"\nNhap Ten :";
      cin.ignore();
      getline(cin,ts[i].Ten);
      cout<<"\nNhap Diem :";
      cin >>ts[i].Diem;
    }
}
void InThiSinh(ThiSinh *ts,int k){
    cout<<"\nDanh sach thi  sinh la :\n";
    for(int i=0;i<k;i++){
        cout<<"\nTen thi sinh :"<<ts[i].Ten;
        cout<<"\nDiem Thi Sinh:"<<ts[i].Diem;
    }
}
ostream& operator<<(ostream &os,ThiSinh ts ){
    return os;;
}
void TbcThiSinh(ThiSinh *ts,int k){
    cout<<"\nTrung binh cong thi sinh:";
    float tong=0;
    for (int i=0;i<k;i++){
     tong+=ts[i].Diem;
    }
    cout<<"\nTrung binh diem  thi sinh:"<<tong/k<<endl;
}
template <class T> void Nhap(const string& thongbao , int  &n, T *&a){
    
}
int main() {
    int n;
    cout << "Nhap so phan tu mang a: ";
    cin >> n;
    int *a;
    NhapDay(a, n);
    In(a, n);
    float tb = TBC(a, n);
    cout << "\nTrung Binh: " << tb << endl;
    int m;
    cout << "\nNhap So Nhan Vien: ";
    cin >> m;
    cin.ignore(); 
    NhanVien *nv;
    int *luong;
    NhapDay(nv, m, luong);
    InNhapDay(nv, m);
    float tbLuong = TBC(luong, m);
      cout << "\nLuong Trung Binh: " << fixed << setprecision(2) << tbLuong << endl;
    // Giải phóng bộ nhớ đã cấp phát

    int k;
    cout<<"\nNhap So thi sinh :";
    cin >>k;
    ThiSinh *ts;
    NhapDay(ts,k);
    InThiSinh(ts,k);
    TbcThiSinh(ts,k);
     
    delete[] ts;
    delete[] a;
    delete[] nv;
    delete[] luong;

    return 0;
}


