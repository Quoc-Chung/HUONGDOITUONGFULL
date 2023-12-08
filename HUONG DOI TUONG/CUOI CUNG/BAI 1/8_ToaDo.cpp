#include<bits/stdc++.h>
using namespace std;
class Diem{
   private:
     float Hoanh;
     float Tung;
   public:
     Diem(): Hoanh(0), Tung(0) {}
     friend istream& operator>>(istream& is, Diem &d){
        cout<<"\n\tNhap hoanh do :";
        is>> d.Hoanh;
        cout<<"\n\tNhap tung do :";
        is>>d.Tung;
        return is;    
     }
     friend ostream& operator<<(ostream& os, Diem &d){
        os <<"("<<d.Hoanh<<","<<d.Tung<<" )";
        return os;
     }
     
     void Nhap(){
        cout <<"\n\tNhap hoanh do :";
        cin >>Hoanh;
        cout<<"\n\tNhap tung do:";
        cin >> Tung;
     }
     void Xuat(){
        cout <<"\n("<<Hoanh<<","<<Tung<<" )";
     }

     void NhapNhieuDiem(Diem *d ,int n){
        cout <<"\nNHAP DIEM:"<<endl;
        for (int i=0;i<n;i++){
           cout<<"\nNhap diem thu "<<i+1<<" : "<<endl;
           cin >> d[i];
        }
     }
     void XuatNhieuDiem(Diem *d ,int n){
        cout <<"\nDanh sach day diem la :"<<endl;
        for (int i=0;i<n;i++){
          cout<<"\nDiem thu "<<i+1<<" la :"<<d[i];
        }
     }
     // Đếm số đoạn thẳng thuộc góc phần tư thứ 3.
     void DemSoDoanThang (Diem *d , int n){
        int dem =0;
        for (int i=0;i<n;i++){
            if(d[i].Hoanh* d[i].Tung <0){
                dem++;
            }
        }
     if(dem==0 || dem ==1){
        cout<<"\nKhong co doan thang nao o goc phan tu thu 3.";
	 }
	 if(dem>1){
        cout<<"\nSo doan thang trong goc phan tu thu 3 la : "<<dem<<endl;
	}
  }
   // Cac diem nam ngoai duong tron 
    void KiemTraDiem(Diem *d, int n, float r){
        int dem=0;
        cout<<"\nCac diem nam ngoai duong tron :"<<endl;
        for (int i=0;i<n;i++ ){
        if((1.0*sqrt (d[i].Hoanh*d[i].Hoanh+d[i].Tung*d[i].Tung))>r){
            cout<<"\n( "<<d[i].Hoanh <<" , "<<d[i].Tung<<" )";
            dem ++;
          }	
        }
        if(dem==0){
           cout<<"\nKhong co diem nao nam ngoai duong tron.";    
        }
        else{
            cout<<"\nVay co tong "<<dem<<"diem nam ngoai duong tron.";
        }
    }
    // Doan thang dai nhat 
     float TinhChieuDai(Diem& DiemKhac) {
        return sqrt(pow(DiemKhac.Hoanh - Hoanh, 2) + pow(DiemKhac.Tung - Tung, 2));
    }
    // Tìm đoạn thẳng dài nhất trong dãy tọa độ
    void TimDoanThangDaiNhat(Diem* d, int n) {
        if (n < 2) {
            cout << "\nKhong co duoi thang de so sanh.";
            return;
        }
        int diemDau = 0, diemCuoi = 1;
        float chieuDaiMax = TinhChieuDai(d[0]);

        for (int i = 1; i < n; i++) {
            float chieuDaiHienTai = TinhChieuDai(d[i]);
            if (chieuDaiHienTai > chieuDaiMax) {
                diemDau = i;
                diemCuoi = 0;
                chieuDaiMax = chieuDaiHienTai;
            }
        }
        cout <<"\nDoan thang dai nhat la tu diem (" << d[diemDau].Hoanh << ", " << d[diemDau].Tung << ") den diem ("
             << d[diemCuoi].Hoanh << ", " << d[diemCuoi].Tung << ") voi chieu dai la " << chieuDaiMax << endl;
    }
};
int main(){
    int n;
    cout<<"\nNhap so diem :";
    cin >> n;
    Diem *d = new Diem[n];
    d[0].NhapNhieuDiem(d,n);
    d[0].XuatNhieuDiem(d,n);
    d[0].DemSoDoanThang(d,n);
    float r;
    cout<<"\nNhap so r:";
    cin>>r;
    d[0].KiemTraDiem(d,n,r);
    d[0].TimDoanThangDaiNhat(d,n);
    return 0;
}