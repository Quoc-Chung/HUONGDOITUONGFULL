#include<bits/stdc++.h>
using namespace std;
int TinhToan(float &a,float &b,float &c){
        cout<<"\nNhap he so :";
        cin>>a>>b>>c;
        float delta=b*b -4*a*c;  
        if (delta < 0) {
            return 0; // Phương trình vô nghiệm
        } else if (delta == 0) {
            return 1; // Phương trình có 1 nghiệm
        } else {
            return 2; // Phương trình có 2 nghiệm
        }
}
int main(){
   float a,b,c;
   int x= TinhToan(a,b,c);
   if(x==0){
    cout<<"\nPhuong trinh vo nghiem";
   }
   else if(x==1){
    cout<<"\nPhuong trinh co 1 nghiem";
   }
   else {
    cout<<"\nPhuong trinh co 2 nghiem";
   }
   return 0;
}