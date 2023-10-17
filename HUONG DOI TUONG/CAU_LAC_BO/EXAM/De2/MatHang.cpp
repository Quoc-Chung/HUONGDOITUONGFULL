#include<bits/stdc++.h>
using namespace std;
class MatHang {
    private :
      int MaHang;
      string TenHang;
      string NhaSanXuat;
      int SoLuong;
      float DonGia;
    public :
    // Hàm tạo không có đối số truyền vào 
      MatHang(){
        MaHang = 0;
        TenHang = "";
        NhaSanXuat = "";
        SoLuong = 0;
        DonGia = 0;
      }
      int getMaHang(){
        return MaHang; 
      }
      string getTenHang(){
        return TenHang;
      }
      float getDonGia(){
        return DonGia;
      }
      void Nhap(){
        cout << "Nhap ma hang: ";
        cin >> MaHang;
        cin.ignore();
        cout << "Nhap ten hang: ";
        getline(cin ,TenHang);
        cout << "Nhap nha san xuat: ";
        getline(cin,NhaSanXuat);
        cout << "Nhap so luong: ";
        cin >> SoLuong;
        cout << "Nhap don gia: ";
        cin >> DonGia;
      }
      void Xuat(){
        cout << "Ma hang: " << MaHang << endl;
        cout << "Ten hang: " << TenHang << endl;
        cout << "Nha san xuat: " << NhaSanXuat << endl;
        cout << "So luong: " << SoLuong << endl;
        cout << "Don gia: " << DonGia << endl;
      }
};
class MayTinh : public MatHang{
   private: 
      string Loai;
      string HeDieuHanh;
      float TrongLuong;  
   public:
     MayTinh(){
        Loai = "";
        HeDieuHanh = "";
        TrongLuong = 0;
     }
     void Nhap(){
        MatHang::Nhap();
        cin.ignore();
        cout << "Nhap loai: ";
        getline(cin,Loai);
        cout << "Nhap he dieu hanh: ";
        getline(cin,HeDieuHanh);
        cout << "Nhap trong luong: ";
        cin >> TrongLuong;
     }
     void Xuat(){
        MatHang::Xuat();
        cout << "Loai: " << Loai << endl;
        cout << "He dieu hanh: " << HeDieuHanh << endl;
        cout << "Trong luong: " << TrongLuong << endl;
     }
     void TimKiem(MayTinh *mt,int n){
        int MaTimKiem ;
        string TenTimKiem;
        cout<<"\nNhap ma tim kiem :"; cin >> MaTimKiem; 
        cin.ignore();
        cout<<"\nNhap ten tim kiem:";
        getline(cin,TenTimKiem);
        int dem=0;
        for(int i=0;i<n;i++){
           if(mt[i].getMaHang() == MaTimKiem  || mt[i].getTenHang() ==TenTimKiem){ 
            printf("\nThong tin Tim kiem la :\n"); 
            mt[i].Xuat();
            dem++;
        }
     }
     if(dem==0){
        cout<<"\nKhong tim thay";
     }
    }
    void DonGianCaoNhat(MayTinh *mt,int n){
        float Max =0;
        int Index =0;
        for (int i=0;i<n;i++){
            if(Max <= mt[i].getDonGia()){
                Max = mt[i].getDonGia();
                Index=i;
            }
        }
        if(Index !=0){
            mt[Index].Xuat();
        }
        else{
            cout<<"\nKhong tim thay";
        }
    }
};
int main(){
   int n;
   cout<<"\nNhap so may tinh :";
   cin >>n;
   MayTinh *mt =new MayTinh[n];
   if(mt ==NULL){
    cout<<"\nKhong cap phat duoc.";
    return 0;
   }
   for (int i=0;i<n;i++){
    mt[i].Nhap();
   }
   for (int i=0;i<n;i++){
    mt[i].Xuat();
   }
   mt[0].TimKiem(mt,n);
   mt[0].DonGianCaoNhat(mt,n); //
}