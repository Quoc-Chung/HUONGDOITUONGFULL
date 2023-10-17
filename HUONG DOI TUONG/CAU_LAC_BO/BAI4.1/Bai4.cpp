// Xây dựng lớp DT (Đa thức), trong đó:
//  Các thuộc tính:
// int n; // là bậc của đa thức
// float *a; // là con trỏ xác định vùng bộ nhớ chứa các hệ số 
//  Phương thức nhap() để nhập các hệ số của đa thức; xuat() để in các 
// hệ số của đa thức ra màn hình; gia_tri(t) để tính giá trị của đa thức 
// tại x = t.
#include<bits/stdc++.h>
using namespace std;
class DaThuc{
   private :
     int bac;
     float *a;
   public :
       DaThuc(){
        bac =0;
        a=new float[0];
       }
       // Bổ xung thêm hàm giải phóng bô nhớ 
     ~DaThuc() {
     if (a != nullptr) {
        delete[] a;
        a = nullptr; 
     }
}
       void Nhap(){
         cout<<"\nNhap so bac:";
         cin>>bac;
         a= new float[bac];
         cout<<"\nNhap he so da thuc :";
         for(int i=0;i<=bac;i++){
           cin>>a[i];
         }
       }
      void XuatDaThuc(){
          cout <<a[0] << " + ";
          cout <<a[1] << " * x + ";
          for(int i = 2;i<bac; i++) {
            cout <<a[i] << " * x^" << i << " + ";
            }
            cout <<a[bac]<< " * x^" <<bac;
        }
     void TinhGiaTri(float &x){
        cout<<"\nNhap gia tri x:";
        cin>>x;
        float result =a[0];
        for(int i=0;i<=bac;i++){
            result+=a[i] *pow(x,i);
        }
        cout<<"\nGia tri cua da thuc:"<<result<<endl;
     }
};
int main(){
    DaThuc A;
    A.Nhap();
    A.XuatDaThuc();
    float t;
    A.TinhGiaTri(t);
    return 0;   
}