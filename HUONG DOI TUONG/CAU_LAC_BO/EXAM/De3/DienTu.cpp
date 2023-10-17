#include<bits/stdc++.h>
using namespace std;
class QLH{
   private :
     int MaHang;
     string TenHang;
     string XuatXu;

     int LoaiHang; //  chú thich  có 3 loai mat hang
     int SoLuong;
   public:
   // Hàm khởi tạo không có đối số truyền vào 
   int  getLoaiHang(){
    return LoaiHang;
   }
   int getSoLuong(){
    return SoLuong;
   }
    QLH(){
        MaHang=0;
        TenHang="";
        XuatXu="";
        LoaiHang=0;
        SoLuong=0;
    }

    void Nhap(){
        cout<<"Nhap ma hang: ";
        cin>>MaHang;
        cin.ignore();
        cout<<"Nhap ten hang: ";
        getline(cin,TenHang);
        cout<<"Nhap xuat xu: ";
        cin>>XuatXu;
        cout<<"Nhap loai hang: ";
        cin>>LoaiHang;
        cout<<"Nhap so luong: ";
        cin>>SoLuong;
    }
    void Xuat(){
        cout<<"Ma hang: "<<MaHang<<endl;
        cout<<"Ten hang: "<<TenHang<<endl;
        cout<<"Xuat xu: "<<XuatXu<<endl;
        cout<<"Loai hang: "<<LoaiHang<<endl;
        cout<<"So luong: "<<SoLuong<<endl;
    }
};
class DienTu :public QLH{
    private :
      int ThoiGianBaoHanh;
    public :
    // Hàm khởi tạo không có đối số truyền vào 
      DienTu(){
        ThoiGianBaoHanh=0;
      }
    void Nhap(){
      QLH::Nhap();
      cout<<"Nhap thoi gian bao hanh: ";
      cin>>ThoiGianBaoHanh;
    }
    void Xuat(){
        QLH::Xuat();
        cout<<"Thoi gian bao hanh: "<<ThoiGianBaoHanh<<endl;
    }
    void ThongKeTongSoLuongHang(DienTu *dt,int n){
        int Tong1=0,Tong2=0,Tong3=0;
        int dem1=0,dem2=0,dem3=0;
        for (int i =0;i<n;i++){
            if(dt[i].getLoaiHang() ==1){
                Tong1+=dt[i].getSoLuong();
                dem1++;
            }
             if(dt[i].getLoaiHang() ==2){
                Tong2+=dt[i].getSoLuong();
                dem2++;
            }
             if(dt[i].getLoaiHang() ==3){
                Tong3+=dt[i].getSoLuong();
                dem3++;
            }
        }
        cout<<"\nLoai hang thu nhat co tong la:"<<Tong1<<endl;
        cout<<"\nLoai hang thu hai co tong la :"<<Tong2<<endl;
        cout<<"\nLoai hang thu ba co tong la :"<<Tong3<<endl;
    }
    void ThoiGianBaoHanhLauNhat(DienTu *dt,int n){
        
    }
};
int main(){
   int n;
   cout<<"\nNhap so mat hang :";
   cin >>n;
   DienTu *dt = new DienTu[n];
   if(dt ==NULL){
    cout<<"\nKhong the cap phat"<<endl;
    exit(0);
   }
   for(int i=0;i<n;i++){
    dt[i].Nhap();
   }
   for (int i=0;i<n;i++){
    dt[i].Xuat();
   }

}