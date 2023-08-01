#include<bits/stdc++.h>
using namespace std;
// Xây dựng lớp quản lí hàng
class QLH{
    private:
      int MaHang;
      string TenHang;
      string XuatXu;
      int LoaiHang;// Có ba loại hàng là 1 2 3
      int SoLuong;
    public :
    // Xây dựng hàm nhập
      void Nhap(){
        cout<<"\nNhap Ma Hang :";
        cin>>MaHang;
        cout<<"\nNhap Ten Hang :";
        cin.ignore();
        getline(cin,TenHang);
        cout<<"\nNhap Xuat Xu :";
        getline(cin,XuatXu);
        cout<<"\nNhap Loai Hang:";
        cin >> LoaiHang;
        cout<<"\nNhap So Luong:";
        cin >> SoLuong;
      }
      // Xây dựng hàm xuất
      void In(){
         cout <<"\nMa Hang :"<<MaHang;
         cout <<"\nTen Hang:"<<TenHang;
         cout <<"\nXuat Xu :"<<XuatXu;
         cout <<"\nLoai Hang:"<<LoaiHang;
         cout <<"\nSo Luong :"<<SoLuong;
      }
      //Xây dựng hàm đọc ra loại hàng
      int getLoaiHang(){
        return LoaiHang;
      }
      int getSoLuong(){
        return SoLuong;
      }
      string getTenHang(){
        return TenHang;
      }
};
class DIENTU :public QLH{
    private :
       int TGBH;// thơi gian bao hanh  tinh bang thang
    public :
       int getTGBH(){
          return TGBH;
       }
       void Nhap(){
         QLH::Nhap();// Gọi hàng nhâp chung trươc
         cout <<"\nNhap TGBH:";
         cin>>TGBH;
       }
       void In(){
         QLH::In();//Goi ham In chung trươc rồi đến hàm in riêng 
         cout <<"\nThoi GianBao Hanh:"<<TGBH;
       }
       void ThongKe(DIENTU *dt,int n){
         int dem1=0,dem2=0,dem3=0;
         int tong1=0,tong2=0,tong3=0;
         for (int i=0;i<n;i++){
            if(dt[i].getLoaiHang()==1 && dt[i].getTGBH()> 12){
                dem1++;
                tong1+=dt[i].getSoLuong();
            }
            if(dt[i].getLoaiHang()==2 && dt[i].getTGBH()> 12){
                dem2++;
                tong2+=dt[i].getSoLuong();
            }
            if(dt[i].getLoaiHang()==3 && dt[i].getTGBH()> 12){
                dem3++;
                tong3+=dt[i].getSoLuong();
            }
         }
         cout<<"\nLoai hang 1 co "<<dem1<<" mat hang va So Luong la "<<tong1<<endl;
         cout<<"\nLoai hang 2 co "<<dem2<<" mat hang va So Luong la "<<tong2<<endl; 
         cout<<"\nLoai hang 3 co "<<dem3<<" mat hang va So Luong la "<<tong3<<endl;
       }
       void ThoiGianBaoHanhMax(DIENTU *dt,int n){
         int max=0;
         string MatHangThoa;
         for (int i=0;i<n;i++){
            if(max < dt[i].getTGBH()){
                max =dt[i].getTGBH();
                MatHangThoa=dt[i].getTenHang();
            }
         }
         cout <<"\nTen hang co thoi gian bao hanh max la :"<<MatHangThoa<<endl;
       }
};
int main(){
  int n;
  cout <<"\nNhap n:";
  cin >>n;
  DIENTU *dt= new DIENTU[n];
  for(int i=0;i<n;i++){
    cout <<"\nNhap ma hang thu "<<i+1<<":"<<endl;
    dt[i].Nhap();
  }
  for (int i=0;i<n;i++){
    dt[i].In();
  }
  dt[0].ThongKe(dt,n);
  dt[0].ThoiGianBaoHanhMax(dt,n);
  return 0;
}