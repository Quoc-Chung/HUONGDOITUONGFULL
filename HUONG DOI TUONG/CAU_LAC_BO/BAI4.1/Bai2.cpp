//  Xây dựng lớp Điểm có:
//  Dữ liệu (private) gồm: hoành độ, tung độ
//  Các phương thức (public): 
// o Hàm nhap(), xuat() theo dạng (hoành độ, tung độ)
// o Hàm thành phần kc() tính khoảng cách từ một điểm đến gốc tọa độ
// o Hàm thành phần kc( d) để tính khoảng cách giữa hai điểm
// o Hàm bạn kc( d1,  d2) để tính khoảng cách giữa hai điểm 
// d1 và d2
// o Xây dựng hàm main() để sử dụng lớp trên.
#include<bits/stdc++.h>
using namespace std;
class  {
    private : 
    float HoanhDo;
    float TungDo ;
    public  :
      (){
       HoanhDo = TungDo =0; 
      }
      void Nhap1 ();
      void In1();
      //float TinhKhoangCach( D1 , D2);
      float TinhKhoangCach( D2);
      float GocToaDo();
      friend void TinhKhoangCach( D1, D2){
        float khoangCach = sqrt(pow(D2.HoanhDo - D1.HoanhDo, 2) + pow(D2.TungDo - D1.TungDo, 2));
        cout<<"Khoang cach ham ban la: "<<fixed<<setprecision(2)<<khoangCach<<endl;
      }
};
void ::Nhap1() {
    cout<<"\nNhap hoanh do :";
    cin >> HoanhDo ;
    cout<<"\nNhap tung do :";
    cin >> TungDo ;  
}
void ::In1(){
    cout<<"\n la :"<<"("<<HoanhDo<<","<< TungDo <<")"<<endl;
}
float ::TinhKhoangCach( D2) {
    // Sử dụng công thức khoảng cách Euclid để tính
     D1=*this;
    float khoangCach = sqrt(pow(D2.HoanhDo - D1.HoanhDo, 2) + pow(D2.TungDo - D1.TungDo, 2));
    return khoangCach;
}
float ::GocToaDo(){
      D1=*this;
     return sqrt( pow(D1.HoanhDo,2)+pow(D1.TungDo,2));
}
int main(){
    A,B;
   A.Nhap1();
   A.In1();
   B.Nhap1();
   B.In1();

   float kc =A.TinhKhoangCach(B);//A.TinhKhoangCach(A,B);
   cout<<"Khoang cach: "<<fixed<<setprecision(2)<<kc<<endl;
   
   cout<<"\nKhoang cach tu  A den goc toa do:";
   float kc1 =A.GocToaDo();
   cout<<fixed<<setprecision(2)<<kc1<<endl;
 
   // Hàm bạn 
   TinhKhoangCach(A,B);
   return 0;
}