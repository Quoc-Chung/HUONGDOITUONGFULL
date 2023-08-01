#include<bits/stdc++.h>
using namespace std;
class MatHang{
  private :
    int MaHang;
    string TenHang;
    string NhaSanXuat;
    int SoLuong;
    int DonGia;
  public :
    // Hàm khởi tạo không có đối số truyền vào 
       MatHang() {
          MaHang = SoLuong = DonGia =0;
          TenHang = NhaSanXuat="";
    }
    // Hàm khởi tạo  có  đối số truyền  vào
       MatHang(int MaHang, string TenHang, string NhaSanXuat,int SoLuong, int DonGia){
          this->MaHang=MaHang;
          this->TenHang=TenHang;
          this->NhaSanXuat=NhaSanXuat;
          this->SoLuong=SoLuong;
          this->DonGia=DonGia;
       }
       void Nhap(){
        cout<<"\nNhap Ma Hang :";
        cin>>MaHang;
        cout<<"\nNhap Ten Hang :";
        cin.ignore();
        getline(cin,TenHang);
        cout<<"\nNhap Nha San Xuat :";
        getline(cin,NhaSanXuat);
        cout<<"\nNhap So Luong :";
        cin >>SoLuong;
        cout<<"\nNhap Don Gia :";
        cin >>DonGia;
       }
       void Xuat(){
        cout<<"\nMa Hang :"<<MaHang;
        cout<<"\nTen Hang :"<<TenHang;
        cout<<"\nNha San Xuat :"<<NhaSanXuat;
        cout<<"\nSo Luong :"<<SoLuong;
        cout<<"\nDon Gia :"<<DonGia;
       }
};
class MayTinh : public MatHang{
   private :
     string LoaiCPU;
     string HeDieuHanh;
     int TrongLuong;
   public :
     void Nhap(){
        MatHang::Nhap();
        cout <<"\nNhap Loai CPU :";
        getline(cin,LoaiCPU);
        cout<<"\nNhap He Dieu Hanh :";
        getline(cin,HeDieuHanh);
        cout<<"\nNhap Trong Luong :";
        cin >>TrongLuong;
     } 
     void Xuat(){
        MatHang::Xuat();
        cout<<"\nLoai CPU :"<<LoaiCPU;
        cout<<"\nHe Dieu Hanh :"<<HeDieuHanh;
        cout<<"\nNhap Trong Luong :"<<TrongLuong;
     }
     void TimThongTin(MayTinh *m,int n){

     }
     void DanhSachMayTinhCoDonGiaCaoNhat(MayTinh *m,int n){
        
     }
};
int main(){
    int n;
    cout<<"\nNhap n:";
    cin >>n;
    MayTinh *m= new MayTinh[n];
    if(m== NULL){
        return;
    }
    for(int i=0;i<n;i++){
        m[i].Nhap();
    }
    for (int i=0;i<n;i++){
        m[i].Xuat();
    }

}