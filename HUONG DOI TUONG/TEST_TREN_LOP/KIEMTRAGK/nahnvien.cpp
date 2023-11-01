#include<bits/stdc++.h>
using namespace std;
class NhanVien{
  private:
     int MaNhanVien;
     string HoTen;
     int NamSinh;
  public:
     NhanVien(): MaNhanVien(0),HoTen(""), NamSinh(0) {}
     NhanVien(int MaNhanVien,string HoTen,int NamSinh): MaNhanVien(MaNhanVien),HoTen(HoTen), NamSinh(NamSinh){}
     string getHoTen(){
        return HoTen;
     }
     int getNamSinh(){
        return NamSinh; 
     }
     void Nhap(){
       cout <<"\nNhap ma  nhan vien:";
       cin >> MaNhanVien;
       cout <<"\nNhap ho va ten:";
       cin.ignore();
       getline(cin,HoTen);
       cout<<"\n Nhap nam sinh :";
       cin >>NamSinh;
     }
     void Xuat(){
        cout << "\nMa nhan vien :"<<MaNhanVien;
        cout <<"\nHo va ten :"<<HoTen;
        cout <<"\nNam sinh :"<<NamSinh;
     }


};
class HopDong :public NhanVien{
   private:
       long Tiencong;
       int NgayCong;
   public:
       HopDong():Tiencong(0),NgayCong(0){}
       void Nhap(){
        NhanVien::Nhap();
        cout <<"\nNhap tien cong:";
        cin >>Tiencong;
        cout <<"\nNhap ngay cong:";
        cin >> NgayCong;
       }
       void Xuat(){
        NhanVien::Xuat();
        cout <<"\nTien cong la :"<<Tiencong;
        cout<<"\nNgay cong:"<<NgayCong;
       }
       float Tinhluong(){
         return Tiencong*NgayCong;
       }
};
bool comparator(HopDong &nv1 , HopDong &nv2){
    return nv1.Tinhluong() > nv2.Tinhluong();
}
int  main (){
    int n;
    cout <<"\nNhap so nhan vien :";
    cin >>n;
    HopDong * nv = new HopDong[n];
    cout <<"\nNHAP NHAN VIEN :";
    for(int i=0;i<n;i++){
       nv[i].Nhap();
    }
    cout <<"\n-----------------------------------------------"<<endl;
    cout <<"\nNHAN VIEN VUA NHAP LA :"<<endl;
    for(int i=0;i<n;i++){
        nv[i].Xuat();
    }
    cout <<"\n------------------------------------------------"<<endl;
    string NhanVien;
    cin.ignore();
    cout <<"\nNhap nhan vien :";
    getline(cin,NhanVien);
    bool check = false;
    for (int i=0;i<n;i++){
        if(NhanVien == nv[i].getHoTen()){
             check = true;
             cout <<"\nTIM THAY NHAN VIEN"<<endl;
             nv[i].Xuat();
        }
    }
    if(check == false){
        cout <<"\nKhong tim thay nhan vien da kiem "<<endl;
    }
    cout<<"\n-----------------------------------------------------------"<<endl;
    int vitri=0;
    int max =0;
    for (int i=0;i<n;i++){
        if(max < nv[i].getNamSinh()){
            max = nv[i].getNamSinh();
            vitri=i;
    } 
    }
    cout <<"\nNhan vien co tuoi tre nhat la :"<<endl;
    nv[vitri].Xuat();
    cout <<"\n-------------------------------------------------------"<<endl;
   sort(nv,nv+n,comparator);
   cout <<"\nNHAN VIEN DUOC SAP XEP GIAM DAN THEO LUONG :"<<endl; 
//    for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         if(nv[i].Tinhluong() > nv[j].Tinhluong()){
//             swap(nv[i],nv[j]);
//         }
//     }
//    } 
   for (int i=0;i<n;i++){
    nv[i].Xuat();
   }
  
   delete[] nv;
   return 0;
}  