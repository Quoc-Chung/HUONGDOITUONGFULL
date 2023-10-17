#include<bits/stdc++.h>
using namespace std;

class NGUOI{
    private:
       string HoTen;
       int Tuoi;
    public :
       NGUOI() : HoTen("") , Tuoi(0) {}
       /* - Khởi tạo có đối số truyền vào - */
       NGUOI(string HoTen , int Tuoi) :HoTen(HoTen) , Tuoi(Tuoi) {}
       
       void Nhap(){
        cout<<"\nNhap ho ten :";
        cin.ignore();
        getline(cin ,HoTen);
        cout<<"\nNhap tuoi :";
        cin >> Tuoi;
       }
       void Xuat(){
        cout<<"\nHo ten la :"<<HoTen<<" - "<<" Tuoi :"<<Tuoi<<endl;
       }     
};
class QLNV :public NGUOI{
   private:
      int snct; 
      float HeSoLuong;
    public :
     QLNV() : snct(0) , HeSoLuong(0) {}
     int getSnct(){
        return snct;
     }
     void Nhap(){
        NGUOI::Nhap();
        cout<<"\nNhap so nam cong tac :";
        cin >> snct;
        cout<<"\nNhap he so luong :";
        cin >> HeSoLuong;
     }
     void Xuat(){
        NGUOI::Xuat();
        cout<<"\nSo nam cong tac :"<<snct <<endl;

     }
     float TinhTienLuong(){
           float Luong= 1.5 * HeSoLuong;
           float phucap = 0.2* snct;
           Luong+=phucap;
           return Luong;
     }
};
void SoNamCongTac(vector<QLNV> nv , int n){
    int max = 0;
    int vitri =0;
    for(int i=0;i<n;i++){
        if(max < nv[i].getSnct()){
            max = nv[i].getSnct();
            vitri = i;
        }
    }
    cout<<"\nNhan vien co so nam cong tac nhieu nhat: "<<endl;
    nv[vitri].Xuat();
}

int main (){
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    vector<QLNV> danhSachNhanVien;
    for (int i = 0; i < n; i++) {
        QLNV nv;
        cout << "Nhap thong tin nhan vien " << i + 1 << ":\n";
        nv.Nhap();
        danhSachNhanVien.push_back(nv);
    }
  cout<<"\nTHONG TIN CAC NHAN VIEN :"<<endl;
  for( auto x : danhSachNhanVien){
    int i=1;
    cout<<"\nNhan vien thu "<<i++<<" : "<<endl;
    x.Xuat();
  }
  SoNamCongTac(danhSachNhanVien,n);
  return 0;
}