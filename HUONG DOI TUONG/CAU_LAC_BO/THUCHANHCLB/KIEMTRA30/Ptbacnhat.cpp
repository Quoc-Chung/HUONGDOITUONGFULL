#include<bits/stdc++.h>
using namespace std;
class PhuongTrinh{
  private :
  // ax + b 
    float a,b;
  public : 
     PhuongTrinh(): a(0),b(0){}
     friend istream& operator>>(istream &is,PhuongTrinh &pt){
        cout <<"\n Nhap he so a:";
        is>> pt.a;
        cout <<"\nNhap he so b :";
        is>> pt.b;
        return  is;
     }
     friend ostream& operator<<(ostream &os,PhuongTrinh &pt){
        os << "\nPhuong trinh la :";
        os <<pt.a<<" *x + "<<pt.b<<endl;
        return os;
     }
     void NhapDanhSach(PhuongTrinh * pt ,int n ){
        cout <<"\nNHAP PHUONG TRINH :";
        for (int i=0;i < n;i++){
            cout <<"\nNhap phuong trinh thu "<<i<<":";
            cin >> pt[i];
        }
     }
     void ThongKe(PhuongTrinh* pt, int n) {
        int co1Nghiem = 0, voNghiem = 0, voSoNghiem = 0;
        cout <<"\nCac phuong trinh co 1 nghiem :"<<endl;
        for (int i = 0; i < n; i++) {
            float a = pt[i].a;
            float b = pt[i].b;
            if (a != 0) {
                cout <<pt[i];
                co1Nghiem++;
            }
        } 
        cout <<"\nCac phuong trinh vo nghiem :"<<endl;
        for (int i = 0; i < n; i++) {
            float a = pt[i].a;
            float b = pt[i].b;
            if (a == 0 && b != 0) {
                cout <<pt[i];
                voNghiem++;
            }
        } 
        cout <<"\nCac phuong trinh co vo so nghiem :"<<endl;
        for (int i = 0; i < n; i++) {
            float a = pt[i].a;
            float b = pt[i].b;
            if (a == 0 && b ==0) {
                cout <<pt[i];
                voSoNghiem++;
            }
        } 
        cout << "So phuong trinh co 1 nghiem: " << co1Nghiem << endl;
        cout << "So phuong trinh co vo nghiem: " << voNghiem << endl;
        cout << "So phuong trinh co vo so nghiem: " << voSoNghiem << endl;
    }
    void TrungBinhCong(PhuongTrinh* pt, int n) {
        float tbc =0,dem =0 ;
        for (int i = 0; i < n; i++) {
            float a = pt[i].a;
            float b = pt[i].b;
            if (a != 0) {
               tbc += pt[i].b ;
               dem++;
            } 
        }
    cout <<"\nTrung binh cong cac he so tu do co mot nghiem : "<<fixed<<setprecision(2)<<tbc /dem <<endl;
    } 
};
int main (){
    int n;
    cout <<"\nNhap so phuong trinh :";
    cin >> n;
    PhuongTrinh * pt = new PhuongTrinh[n];
        pt[0].NhapDanhSach(pt,n);
    pt[0].ThongKe(pt,n);
    pt[0].TrungBinhCong(pt,n);
    return 0;
}