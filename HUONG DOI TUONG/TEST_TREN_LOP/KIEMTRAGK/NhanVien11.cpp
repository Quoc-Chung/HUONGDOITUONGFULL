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
       void NhapNhanVien(HopDong *nv,int n){
           cout <<"\nNHAP NHAN VIEN :";
            for(int i=0;i<n;i++){
            nv[i].Nhap();
            }
       }
       void XuatNhanVien(HopDong *nv,int n){
         cout <<"\nNHAN VIEN VUA NHAP LA :"<<endl;
            for(int i=0;i<n;i++){
                nv[i].Xuat();
            }
       }
       void TimKiemNhanVien(HopDong *nv,int n,string NhanVien){
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
         }
        void NhanVienTreNhat(HopDong *nv,int n){
            int max =0;
            for (int i=0;i<n;i++){
                if(max < nv[i].getNamSinh()){
                    max = nv[i].getNamSinh();
            } 
            }
            cout <<"\nNhan vien co tuoi tre nhat la :"<<endl;
            for (int i=0;i<n;i++){
                if(nv[i].getNamSinh() ==max){
                    nv[i].Xuat();
                }
            }
        }
        void SapXepNhanVien(HopDong *nv,int n){
           cout <<"\nNHAN VIEN DUOC SAP XEP GIAM DAN THEO LUONG :"<<endl; 
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(nv[i].Tinhluong() > nv[j].Tinhluong()){
                        swap(nv[i],nv[j]);
                    }
                }
            } 

            for (int i=0;i<n;i++){
                nv[i].Xuat();
            }
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
    nv[0].NhapNhanVien(nv,n);
    cout <<"\n-----------------------------------------------"<<endl;


    nv[0].XuatNhanVien(nv,n);
    cout <<"\n------------------------------------------------"<<endl;
    string NhanVien;
    cin.ignore();
    cout <<"\nNhap ten nhan vien tim kiem:";
    getline(cin, NhanVien);
    nv[0].TimKiemNhanVien(nv,n,NhanVien);
    cout<<"\n-----------------------------------------------------------"<<endl;

    nv[0].NhanVienTreNhat(nv,n);
    cout <<"\n-------------------------------------------------------"<<endl;

//  sort(nv,nv+n,comparator);
    nv[0].SapXepNhanVien(nv,n);
    delete[] nv;
    return 0;
}  
