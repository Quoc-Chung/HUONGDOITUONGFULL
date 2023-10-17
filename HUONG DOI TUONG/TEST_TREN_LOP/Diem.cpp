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
      float getHoanh(){
        return HoanhDo;
      }
      float getTung(){
        return TungDo;
      }
      void Nhap1 ();
      void In1();
      //float TinhKhoangCach( D1 , D2);
      float TinhKhoangCach( D2);
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
int main(){
    A,B;
   A.Nhap1();
   A.In1();
   B.Nhap1();
   B.In1();
   float kc =A.TinhKhoangCach(B);//A.TinhKhoangCach(A,B);
   cout<<"Khoang cach: "<<fixed<<setprecision(2)<<kc<<endl;

   int n; 
   cout<<"\nNhap n:";
   cin >>n;
    *a = new [n];
   for (int i=0;i<n;i++){
     a[i].Nhap1();
   }
   for (int i=0;i<n;i++){
    a[i].In1();
   }
   float Tong=0;
   int dem=0;
   for (int i=0;i<n-1;i++){
     Tong+=a[i].TinhKhoangCach(a[i+1]);//a->TinhKhoangCach(a[i] ,a[i+1]);
     if(a->getHoanh() < 0 && a->getTung() < 0){
        dem++;
     }
   }
   cout<<"Khoang cach duong gap khuc la :"<<Tong<<endl;
   cout<<"\nSo  trong goc phan tu thu ba:"<<dem <<endl;
   return 0;

}