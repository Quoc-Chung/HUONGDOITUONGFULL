#include<bits/stdc++.h>
using namespace std;
struct  SinhVien{
  int SoBaoDanh;
  string HoTen;
  float DiemThi;
};
void NhapSinhVien(SinhVien &sv){
    cout<<"\nNhap SBD :";
    cin >> sv.SoBaoDanh;
    cout <<"\nNhap Ho Ten :";
    cin.ignore(); // Xóa kí tự còn sót lại  từ việc nhập cin ở  bên  trên 
    getline(cin,sv.HoTen);
    cout <<"\nNhap Diem Thi:";
    cin >> sv.DiemThi;
}
void NhapDanhSachSV(SinhVien *sv ,int n){
    for (int i=0;i<n;i++){
        NhapSinhVien(sv[i]);
    }
}
void InDanhSachSV(SinhVien *sv ,int n){
    printf("\nTHONG TIN SINH VIEN LA :\n");
    for (int i=0;i<n;i++){
        cout<<"\nSoBaoDanh :"<<sv[i].SoBaoDanh;
        cout<<"\nHoTen :"<<sv[i].HoTen;
        cout<<"\nDiemThi :"<<sv[i].DiemThi;
    }
}
void Swap(SinhVien &sv1 ,SinhVien &sv2){
    SinhVien temp =sv1;
    sv1=sv2;
    sv2=temp;
}
void SapXep(SinhVien *sv,int n){
    for(int i=0;i<n-1;i++){
        for (int j =i+1;j<n;j++){
            if(sv[i].DiemThi<sv[j].DiemThi){
                Swap(sv[i],sv[j]);
            }
        }
    }
}
int main(){
  int n;
  cin>>n;
  SinhVien sv[n];
  NhapDanhSachSV(sv,n);
  InDanhSachSV(sv,n);
   SapXep(sv,n);
   cout <<"\nDanh sach sau khi  sap xep :"<<endl;
   InDanhSachSV(sv,n);
  return 0;
}