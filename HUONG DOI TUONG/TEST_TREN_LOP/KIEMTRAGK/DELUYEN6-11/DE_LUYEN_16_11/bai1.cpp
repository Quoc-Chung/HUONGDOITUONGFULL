#include<bits/stdc++.h>
using namespace std;
class Elip{
  private:
    float a,b;
  public:
    Elip(): a(0), b(0) {}
    void Nhap(){
        cout<<"\nNhap ban kinh :";
        cin >> a >> b; 
    }
    void Xuat(){
        cout <<"("<<a<<""<<b<<")"<<endl;
    }
    void NhapNhieuBanKinh(Elip *bk ,int n){
        for(int i=0;i<n;i++){
            bk[i].Nhap();
        }
    }
    void XuatNhieuElip(Elip *bk ,int n){
        cout <<"\nThong tin ban kinh la :";
        for(int i=0;i<n;i++){
            bk[i].Xuat();
        }
    }
    void ElipMax(Elip *bk ,int n){
        float max = 0.0 ;
         for (int i =0 ;i< n;i++){
            if(bk[i].a == bk[i].b){
                if( max < 3.14*bk[i].a * bk[i].b){
                    max = 3.14*bk[i].a * bk[i].b;
                }
            }
         }
        if( max ==0.0){
            cout <<"\n Khong co hinh tron trong elip "<<endl;
        }
        else{
            cout <<"\nElip la hinh tron co  dien tich max la : "<< max << endl;
        }
    }

    void KiemTraTangDan(Elip *bk ,int n){
        // a tang dan va b giam dan 
        bool check1 = true, check2 =true;
        for(int i = 0;i < n-1; i++){
            if(bk[i].a > bk[i+1].a) {
                 check1= false;
            }
            if(bk[i].b < bk[i+1].b){
                check2 = false;
            }
        }
        if(check1 && check2){
            cout<<"\nDay vua tang dan theo a vua giam dan theo a"<<endl;
        }
        else{
            cout <<"\nDay khong tang dan theo a va giam dan theo b"<<endl;
        }
    }
};
int main(){
    int n;
    cout <<"\nNhap so luong n:";
    cin >> n;
    Elip *bk = new Elip[n];
    if(bk == NULL){
        cout <<"\nKhong the khoi tao duoc mang doi tuong"<<endl;
        exit(1);
    }
    bk[0].NhapNhieuBanKinh(bk,n);
    bk[0].XuatNhieuElip(bk,n);
    bk[0].ElipMax(bk,n);
    bk[0].KiemTraTangDan(bk,n);
    delete []bk;
    return 0;
}