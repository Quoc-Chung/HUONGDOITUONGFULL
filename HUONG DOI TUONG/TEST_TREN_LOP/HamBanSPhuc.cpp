#include<bits/stdc++.h>
using namespace std;
class SoPhuc{
   private :
      int a,b;
   public :
    void Nhap(){
        cout<<"\nNhap phan thuc:";
        cin>>a;
        cout<<"\nNhap phan ao:";
        cin>>b;
    }
    void Xuat(){
         if(b >=0){
        cout<<a<<" + "<<b<<"i"<<endl;
        }
         else{
         cout<<a<<"  "<<b<<"i"<<endl;
        }
    }
    friend SoPhuc operator+(SoPhuc s1,SoPhuc s2){
    SoPhuc s3;
    s3.a=s1.a+s2.a;
    s3.b=s1.b+s2.b;
    return s3;
   }
};
int main(){
    SoPhuc s1,s2;
    cout<<"\nNhap so phuc 1:";
    s1.Nhap();
    cout<<"\nNhap so phuc 2:";
    s2.Nhap();
    SoPhuc s3=s1+s2;
    cout<<"\nso phuc s3 la :\n";
    s3.Xuat();
    return 0;
}