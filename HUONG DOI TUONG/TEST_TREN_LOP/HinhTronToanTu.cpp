#include<bits/stdc++.h>
using namespace std;
struct HinhTron{
  float h,t,r;
};
istream& operator>>(istream& is,HinhTron&ht){
  cout<<"\nNhap hoanh do:";
  is>>ht.h;
  cout<<"\nNhap tung do:";
  is>>ht.t;
  do{
  cout<<"\nNhap ban kinh:";
  is>>ht.r;
  }while(ht.r <= 0);// Đây là điêu kiện sai
  return is;
}
ostream& operator<<(ostream& os, HinhTron &ht){
 os<<"Hoanh Do:"<<ht.h<<" "<<"Tung do :"<<ht.t<<" "<<"Ban kinh:"<<ht.r<<endl;
 return os;
}
void NhapDayHinhTron(HinhTron *&ht ,int &n){
  cout<<"\nNhap so diem :";
  cin>>n;
  ht=new HinhTron[n];
  for (int i=0;i<n;i++){
    cin >>ht[i];
  }
}
void XuatDayHinhTron(HinhTron *ht ,int &n){
  cout<<"\nDay hinh tron la :\n";
  for (int i=0;i<n;i++){
    cout<<ht[i]<<endl;
  }
}
float KhoangCach(HinhTron ht){
   return sqrt(pow(ht.h ,2) + pow(ht.t ,2));
}
bool NamTrenTrucHoanh(const HinhTron &ht) {
    return ht.t > ht.r;// bán kính luôn là số dương rồi nên 
}
void NamTrenTrucHoanh(HinhTron *ht ,int n){
  int dem=0;
  for (int i=0;i<n;i++){
    if(NamTrenTrucHoanh(ht[i])){
      dem++;
      cout<<ht[i]<<endl;
    }
  }
  cout<<"\nSo diem  nam tren  truc hoanh la :"<<dem<<endl;
}
int main(){
   HinhTron ht;
   cin>>ht;
   cout<<ht<<endl;
   int n;
    HinhTron *HT;
   NhapDayHinhTron(HT, n);
   XuatDayHinhTron(HT, n);
   NamTrenTrucHoanh(HT,n);
   return 0;
}