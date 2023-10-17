#include<bits/stdc++.h>
using namespace std;

class Nguoi{
    private :
      string HoTen;
      int Tuoi;
    public :
    // Hàm khởi tạo khong có đối  số truyền  vào 
      Nguoi(){
        HoTen="";
        Tuoi=0;
      }
    void Nhap(){
        cin.ignore();
        cout<<"\nNhap  Ho Ten :";
        getline(cin,HoTen);
        cout<<"\nNhap tuoi :";
        cin >>Tuoi;
    }
    void In(){
        cout<<"\nHoTen : "<<HoTen<<"\nTuoi : "<<Tuoi;
    }
};
class QLNV : public Nguoi {
    private :
      int SoNamCT;
      long long TienLuong;
    public :
      QLNV(){
        SoNamCT=0;
        TienLuong=0;
      }
      void Nhap(){
        Nguoi::Nhap();
        cout<<"\nNhap So Nam CT :";
        cin >>SoNamCT;
        cout<<"\nNhap Tien Luong :";
        cin >>TienLuong;
      }
      void In(){
        Nguoi::In();
        cout<<"\nSo Nam CT : "<<SoNamCT<<"\nTien Luong : "<<TienLuong;
      }
      void TienLuongTrungBinh (QLNV *nv ,int n){
        long long  TongLuong =0;
        for (int i=0;i<n;i++){
             TongLuong= nv[i].TienLuong;
        }
        cout<<"\nTien Luong Trung Binh la :"<<fixed <<setprecision(2)<<TongLuong/n<<endl;
      }
      void SNCTMax (QLNV *nv ,int n){
        int SoNamMax =0;
        for (int i=0;i<n;i++){
            SoNamMax =max(SoNamMax,nv[i].SoNamCT);
        }
        for (int i=0;i<n;i++){
            if(nv[i].SoNamCT == SoNamMax){
                nv[i].In();
        }
      }
      }
};
int main (){
    int n;
    cout<<"\nNhap So Nhan Vien  :";
    cin >>n;
    QLNV  *nv =new QLNV[n];
    if(nv ==NULL){
        printf("\nKhong the cap phat.");
        exit(0);
    }
    for (int i=0;i<n;i++){
        cout<<"\nNHAP NHAN VIEN "<<i+1<<" :"<<endl;
        nv[i].Nhap();
    }
    cout<<"\nTHONG TIN NHAN VIEN"<<endl;
    for (int i=0;i<n;i++){
        nv[i].In();
    }
    nv[0].TienLuongTrungBinh(nv,n);
    nv[0].SNCTMax(nv,n);
    return 0;
}