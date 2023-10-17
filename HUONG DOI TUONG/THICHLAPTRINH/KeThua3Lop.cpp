#include<bits/stdc++.h>
using namespace std;
class SinhVien{
    protected : 
       int MaSV;
       string HoTen;
       int Ngay,Thang,Nam;
       string GioiTinh;
    public:
        SinhVien(){
            MaSV =Ngay = Thang = Nam = 0;
            HoTen = GioiTinh = "";
        }
       void Nhap(){
        cout<<"\nNhap Ma Sinh Vien :";
        cin >> MaSV;
        cout<<"\nNhap Ho Ten :";
        cin.ignore();
        getline(cin , HoTen);
        cout<<"\nNhap Ngay Sinh :";
        cin >> Ngay >>Thang>> Nam;
        cout<<"\nNhap Gioi Tinh :";
        cin.ignore();
        getline(cin ,GioiTinh);
       }
       void Hien (){
        cout << "\nMa sinh vien: " << MaSV;
        cout << "\nHo ten: " << HoTen;
        cout << "\nNgay sinh: " << Ngay << "/" << Thang << "/" << Nam;
        cout << "\nGioi tinh: " << GioiTinh;  
       }
};
class HocPhan{
    protected:
       string TenHocPhan;
       float DChuyenCan , DThuongXuyen , DBaiTapLon , DThi;
    public :
       HocPhan(){
        TenHocPhan = "";
        DChuyenCan = DThuongXuyen = DBaiTapLon = DThi =0;
       }
       void Nhap (){
         cout<<"\nNhap ten hoc phan :";
         cin.ignore();
         getline(cin ,TenHocPhan);
         cout<<"\nNHAP DIEM :";
         cout<<"\n + Chuyen Can :";cin >> DChuyenCan;
         cout<<"\n + Thuong Xuyen :"; cin >> DThuongXuyen;
         cout<<"\n + Bai Tap Lon :"; cin >> DBaiTapLon;
         cout<<"\n + Thi :"; cin >> DThi;
       }
       void Hien(){
         cout<<"\nTen hoc phan: " << TenHocPhan;
         cout<<"\nDiem Chuyen Can: " << DChuyenCan;
         cout<<"\nDiem Thuong Xuyen: " << DThuongXuyen;
         cout<<"\nDiem Bai Tap Lon: " << DBaiTapLon;
         cout<<"\nDiem Thi: " << DThi << endl;
      }  
};
class KetQua : public SinhVien, public HocPhan{
      private :
        float DiemTrungBinh;
     public :
        KetQua(){
            DiemTrungBinh = 0;
        }
        float Nhap(){
            DiemTrungBinh=(DChuyenCan + DThuongXuyen * 2 + 2 * DBaiTapLon + 5 * DThi) / 10;
            return DiemTrungBinh;
        }
        void Hien(){
          SinhVien::Hien();
          cout<<"\nDiem Trung Binh La :"<<DiemTrungBinh<<endl;
        }
};
void NhapDanhSach(vector<KetQua>& dsSinhVien ,int &n){
       cout<<"\nNhap so sinh vien:";
       cin >>n;
     for (int i=0;i<n;i++){
     cout<<"\nNHAP SINH VIEN THU "<<i+1<<":";
        KetQua sv; // Tạo một đối tượng KetQua mới
        sv.SinhVien::Nhap(); // Gọi hàm Nhap() của lớp SinhVien để nhập thông tin SinhVien
        sv.HocPhan::Nhap(); // Gọi hàm Nhap() của lớp HocPhan để nhập thông tin HocPhan
        sv.Nhap(); // Gọi hàm Nhap() của lớp KetQua để tính điểm trung bình và nhập nó
        dsSinhVien.push_back(sv); // Thêm đối tượng KetQua vào danh sách dsSinhVien
   }
}
void InDanhSachSinhVien(vector<KetQua> dsSinhVien ,int n){
   cout<<"\nDANH SACH SINH VIEN LA :\n";
   for(auto it=dsSinhVien.begin();it!=dsSinhVien.end();it++){
        (*it).Hien();
   }
}
void DiemTBTrenTam(vector<KetQua> dsSinhVien,int n){
   cout<<"\nDANH SACH SINH VIEN DIEM TREN TAM :"<<endl;
    for(auto it=dsSinhVien.begin();it!=dsSinhVien.end();it++){
      float Diemtmp = (*it).Nhap();
        if(Diemtmp > 8.0){
           (*it).Hien();
        }
   }
}
void DiemTBMax(vector<KetQua> dsSinhVien,int n){
   cout<<"\nDANH SACH SINH VIEN CO DIEM MAX LA :"<<endl;
   float max =0;
   for(auto it=dsSinhVien.begin();it!=dsSinhVien.end();it++){
   float Diemtmp = (*it).Nhap();
        if( max < Diemtmp){
          max=Diemtmp;
        }
   }
   for(auto it=dsSinhVien.begin();it!=dsSinhVien.end();it++){
      float Diemtmp = (*it).Nhap();
        if(Diemtmp == max){
           (*it).Hien();
        }
   }
}
int main(){
    int n;
    vector<KetQua> dsSinhVien;
    NhapDanhSach(dsSinhVien,n);
    InDanhSachSinhVien(dsSinhVien,n);   
    DiemTBTrenTam(dsSinhVien,n);
    DiemTBMax(dsSinhVien,n);
    return 0;

}