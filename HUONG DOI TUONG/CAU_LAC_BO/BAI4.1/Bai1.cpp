// Xây dựng lớp Số phức (SP) có: 
//  Các thành phần dữ liệu (private): phần thực và phần ảo
//  Các phương thức (public): nhap(), xuat() và cong()
//  Xây dựng hàm main() trong đó sử dụng lớp SP
#include<bits/stdc++.h>
using namespace std;
class SoPhuc{
  private :
     float thuc,ao;
  public:
     SoPhuc (){
        thuc=ao=0;
     }   
     void Nhap(){
        cout<<"\nNhap phan thuc:";
        cin>>thuc;
        cout<<"\nNhap phan ao:";
        cin>>ao;
     }
     void Xuat(){
        cout<<"\nSo phuc la :";
        if(ao >= 0){
            cout<<thuc<<" + "<<ao<<"i"<<endl;
        }
        else{
            cout<<thuc<<" "<<ao<<"i"<<endl;
        }
     }
     SoPhuc CongHaiSoPhuc(SoPhuc A , SoPhuc B){
        SoPhuc result;
        result.thuc=A.thuc+B.thuc;
        result.ao=A.ao+B.ao;
        return result;
     }
};
int main(){
   SoPhuc A,B;
   A.Nhap();
   B.Nhap();
   cout<<"\nCAC SO PHUC VUA NHAP:";
   A.Xuat();
   B.Xuat();
   cout<<"\nTong hai so phuc:";
   SoPhuc C = A.CongHaiSoPhuc(A,B);
   C.Xuat();
   return 0;
}