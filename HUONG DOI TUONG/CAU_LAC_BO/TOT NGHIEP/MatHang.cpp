#include<bits/stdc++.h>
using namespace std;
class MatHang{
  private:
     int Ma_Hang;
     string TenHang;
     string Nha_San_Xuat;
     int So_Luong;
     long long Don_Gia;
  public:
     MatHang() : Ma_Hang(0) , TenHang("") , Nha_San_Xuat("") , So_Luong(0) , Don_Gia(0) {}

     MatHang(int Ma_Hang , string TenHang,string Nha_San_Xuat, int So_Luong, long long Don_Gia):
     Ma_Hang(Ma_Hang), TenHang(TenHang),Nha_San_Xuat(Nha_San_Xuat),So_Luong(So_Luong),Don_Gia(Don_Gia){}
     
     int getSo_Luong(){
        return So_Luong;
     }
     long long getDon_Gia(){
        return Don_Gia;
     }

     void Nhap(){
        cout<<"\nNhap ma hang :";
        cin >>Ma_Hang;
        cout <<"\nNhap Ten hang :";
        cin.ignore();
        getline(cin,TenHang);

        cout<<"\nNhap nha san xuat:";
        getline(cin,Nha_San_Xuat);

        cout <<"\nNhap so luong:";
        cin >> So_Luong;

        cout << "\nNhap Don Gia :";
        cin >> Don_Gia;
     }
    void Xuat() {
        cout <<"Ma hang: " << Ma_Hang << endl;
        cout <<"Ten hang: " << TenHang << endl;
        cout <<"Nha san xuat: " << Nha_San_Xuat << endl;
        cout <<"So luong: " << So_Luong << endl;
        cout <<"Don Gia: " << Don_Gia << endl;
     }
};
class MayTinh : public MatHang{
    private:
       string LoaiCPU;
       float TrongLuong;
       string HeDieuHanh;
    public:
       string getHeDieuHanh(){
        return HeDieuHanh;
       }
       MayTinh(): LoaiCPU(""), TrongLuong(0), HeDieuHanh(""){}
       void Nhap(){
            MatHang::Nhap();
            cout<<"\nNhap loai CPU:";
            cin.ignore();
            getline(cin,LoaiCPU);

            cout<<"\nNhap trong luong:";
            cin >> TrongLuong;

            cout<<"\nNhap he dieu hanh :";
            cin.ignore();
            getline(cin,HeDieuHanh);
       }
       void Xuat(){
         MatHang::Xuat();
         cout<<"\n Loai CPU :"<<LoaiCPU;  
         cout<<"\n Trong Luong :"<<TrongLuong;
         cout<<"\n HeDieuHanh :"<<HeDieuHanh;
       }
    void DanhSachHetHang(MayTinh *mt ,int n){
        int dem =0;
        for (int  i=0;i<n;i++){
            if(mt[i].getSo_Luong()==0){
                mt[i].Xuat();
                dem++;
            }
        }
        if(dem==0){
            cout <<"\nKhong co san pham nao het hang."<<endl;
        }
    }

    void TimMayTinhGiaCaoNhat(MayTinh *mt, int n) {
        long long giaCaoNhat = -1; 
        for (int i = 0; i < n; i++) {
            if (mt[i].getDon_Gia() > giaCaoNhat) {
                giaCaoNhat = mt[i].getDon_Gia();
            }
        }
        cout <<"\nDanh sach cac may tinh co he dieu hanh windown va co muc gia cao nhat:"<<endl;
        int dem = 0;
        for (int i = 0; i < n; i++) {
            if (mt[i].getHeDieuHanh() == "Windows" && mt[i].getDon_Gia() == giaCaoNhat) {
                mt[i].Xuat();
                dem++;
            }
        }
       
        if (dem == 0) {
            cout << "Khong co may tinh nao co he dieu hanh Windows va gia cao nhat." << endl;
        }
    }
};
int main() {
    int n;
    cout <<"Nhap so luong may tinh: ";
    cin >> n;
    MayTinh *dsMayTinh = new MayTinh[n];
    for (int i = 0; i < n; i++) {
        cout << "Nhap thong tin may tinh thu " << i + 1 << ":" << endl;
        dsMayTinh[i].Nhap();
    }
    dsMayTinh->DanhSachHetHang(dsMayTinh,n);
    cout <<"\nDanh sach cac may tinh co he dieu hanh Windows va gia cao nhat:" << endl;
    dsMayTinh[0].TimMayTinhGiaCaoNhat(dsMayTinh, n);
    delete[] dsMayTinh;
    return 0;
}
/*
- Anh đọc được dòng này cho em gủi lời cảm ơn chân thành đến anh vì những kiến thức mà anh đã dạy cho em 
em rất biết ơn và trân trọng điều đó . 
*/