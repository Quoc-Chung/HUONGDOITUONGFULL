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
    int getSoLuong(){
        return SoLuong;
    }
    int getDonGia(){
        return DonGia;
    }
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
        cin.ignore();
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
    // Trong class MayTinh
    void DanhSachCacLoaiHetHang(MayTinh *m, int n) {
        int dem = 0;
       for (int i = 0; i < n; i++) {
        if (m[i].getSoLuong() == 0) {
            dem++;
            m[i].Xuat();
        }
    }
    if (dem == 0) {
        cout << "Khong co mat hang nao het hang." << endl;
    }
  }
  void DanhSachMayTinhCoDonGiaCaoNhat(MayTinh *m, int n) {
    int maxDonGia = -1; // Giả sử không có máy tính nào có đơn giá âm
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (m[i].getDonGia() > maxDonGia) {
            maxDonGia = m[i].getDonGia();
            index = i;
        }
    }
    if (index != -1) {
        cout << "May tinh co don gia cao nhat la:" << endl;
        m[index].Xuat();
    } else {
        cout << "Khong co may tinh nao." << endl;
    }
}
};
int main(){
    int n;
    cout<<"\nNhap n:";
    cin >>n;
    MayTinh *m= new MayTinh[n];
    if(m== NULL){
      exit(0);
    }
    for(int i=0;i<n;i++){
        m[i].Nhap();
    }
    for (int i=0;i<n;i++){
        m[i].Xuat();
    }

    cout << "\nDanh sach cac loai het hang:";
    m[0].DanhSachCacLoaiHetHang(m, n); // Gọi hàm từ đối tượng m[0]
    cout << "\nDanh sach may tinh co don gia cao nhat:";
    m[0].DanhSachMayTinhCoDonGiaCaoNhat(m, n); // Gọi hàm từ đối tượng m[0]

    return 0;
}