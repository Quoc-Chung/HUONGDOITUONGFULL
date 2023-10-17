// Xây dựng lớp DT (Đa thức), trong đó:
//  Các thuộc tính
// int n; // là bậc của đa thức
// float *a; // là con trỏ xác định vùng bộ nhớ chứa các hệ số
//  Phương thức nhap() để nhập các hệ số của đa thức
//  Phương thức xuat() để in các hệ số của đa thức ra màn hình
//  Phương thức gia_tri(t) để tính giá trị của đa thức tại x = t.
#include<bits/stdc++.h>
using namespace std;
class DaThuc{
   private :
     int n;
     float *a;
   public:
     DaThuc(){
        n=0;
        a=NULL;
     }
     void Nhap(){
        cout<<"\nNhap n:";
        cin >>n;
        a=new float[n+1];
        for(int i=0;i<=n;i++){
            cout<<"\nNhap a["<<i<<"]:";
            cin >>a[i];
        }
     }
     void XuatDaThuc(){
        cout<<"\bDa thuc vua nhap la :"<<endl;
          for (int i=0;i<=n;i++){
           cout<<a[i]<<"*x^"<<i;
          if(i<n){
            cout<<" + ";
          }
          }
     }
};
int main(){
    DaThuc dt;
    dt.Nhap();
    dt.XuatDaThuc();
    return 0;
}