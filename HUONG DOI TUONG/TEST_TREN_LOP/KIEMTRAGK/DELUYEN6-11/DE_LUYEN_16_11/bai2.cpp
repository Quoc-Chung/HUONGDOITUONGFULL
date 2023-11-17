#include<bits/stdc++.h>
using namespace std;
class KhaoSat{
    private:
       string HoTen;
       int SoThanhVien;
       float DienTich;
    public:
       KhaoSat(): HoTen(""),SoThanhVien(0),DienTich(0) {}
       void Nhap(){
            cout <<"\nNhap chu ho :";
            cin.ignore();
            getline(cin,HoTen);
            cout<<"\nNhap so thanh vien:";
            cin >> SoThanhVien;
            cout <<"\nNhap dien tich :";
            cin >> DienTich;
       }
       void Xuat(){
            cout<<"\nChu ho :"<<HoTen;
            cout<<"\nSo thanh vien:"<<SoThanhVien;
            cout<<"\nDienTich:"<<DienTich;
       }
};
class DanXuat:public KhaoSat{
   private:
      string Tinh;
   public:
      DanXuat(): Tinh("") {}
      void Nhap(){
         KhaoSat::Nhap();
         cout <<"\nNhap tinh :";
         cin.ignore();
         getline(cin , Tinh);
      }
      void Xuat(){
        KhaoSat::Xuat();
        cout <<"\nTinh:"<<Tinh;
      }
      void NhapNhieu (DanXuat *dx ,int n){
        cout <<"\nNHAP CAC CHU HO :"<<endl;
        for(int i=0;i<n;i++){
            dx[i].Nhap();
        }
      }
      void XuatNhieu(DanXuat *dx ,int n){
        cout <<"\nXUAT CAC CHU HO :"<<endl;
        for(int i=0;i<n;i++){ 
            cout <<"\nChu ho thu" <<i+1<<":" ;
            dx[i].Xuat();
        }
      }
}; 
int main(){
    
}