#include<bits/stdc++.h>
using namespace std;
class Book{
   private: 
      int Ma_Sach;
      string TenSach;
      string Ten_Tac_Gia;
      int Nam_Xuat_Ban;
      string NhaXuatBan;
    public:
      /*- Hàm  khởi tạo không đối số truyền vào - */
      Book(): Ma_Sach(0),TenSach(""),Ten_Tac_Gia(""),Nam_Xuat_Ban(0),NhaXuatBan(""){}
      Book(int Ma_Sach,string TenSach,string Ten_Tac_Gia,int Nam_Xuat_Ban,string Nha_XuatBan):
      /* - HÀm khởi tạo không đối số truyền vào - */
      Ma_Sach(Ma_Sach),TenSach(TenSach),Ten_Tac_Gia(Ten_Tac_Gia),Nam_Xuat_Ban(Nam_Xuat_Ban), NhaXuatBan(Nha_XuatBan){}

      void Nhap(){
            cout<<"\nNhap ma sach :";
            cin >> Ma_Sach ;
            cout<<"\nNhap Ten Sach:";
            cin.ignore();
            getline(cin,TenSach);
            cout<<"\nNhap ten tac gia :";
            getline(cin,Ten_Tac_Gia);
            cout<<"\nNhap nam xuat ban :";
            cin >>Nam_Xuat_Ban;
            cout<<"\nNhap nha xuat ban :";
            cin >> NhaXuatBan;
        }
       void Xuat(){
            cout<<"\nMa sach:"<<Ma_Sach;
            cout<<"\nTen sach :"<<TenSach;
            cout<<"\nTen tac gia :"<<Ten_Tac_Gia;
            cout<<"\nNam xuat ban :"<<Nam_Xuat_Ban;
            cout<<"\nNha xuat ban :"<<NhaXuatBan;
       }
      void TimSachTheoTacGia(Book *b,int n,string TenTacGia){
        cout<<"\nSach cua tac gia "<<TenTacGia<<" :";
        bool check =false;
        for(int  i=0;i<n;i++){
            if(b[i].Ten_Tac_Gia== TenTacGia){
                b[i].Xuat();
                check =true;
            }
        }
        if(!check){
            cout<<"\nTac gia nay khong viet sach ."<<endl;
        }
      }
};
int main(){
    int n;
    cout<<"\nNhap so luong sach:";
    cin >> n;
    Book *k = new Book[n];
    for  (int  i =0 ;i< n;i++){
        k[i].Nhap();
    }
    cout<<"\nTHONG TIN CUA SACH LA :"<<endl;
    for(int i=0;i<n;i++){
        k[i].Xuat();
    }
    string tacgia;
    cout<<"\nNhap ten tac gia:";
    cin.ignore();
    getline(cin , tacgia);
    k[0].TimSachTheoTacGia(k,n,tacgia);
    return 0;
}