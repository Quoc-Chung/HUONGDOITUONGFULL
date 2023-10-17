#include<bits/stdc++.h>
using namespace std;
struct SoPhuc{
    int thuc,ao;
};
istream& operator>>(istream& is,SoPhuc &s){
   cout<<"\nNhap phan thuc:";
   cin>>s.thuc;
   cout<<"\nNhap phan ao:";
   cin>>s.ao;
   return is;
}
ostream& operator<<(ostream& os,SoPhuc &s){
    if(s.ao >=0){
        cout<<s.thuc<<" + "<<s.ao<<"i"<<endl;
    }
    else{
         cout<<s.thuc<<"  "<<s.ao<<"i"<<endl;
    }
    return os;
}
SoPhuc operator+(SoPhuc s1,SoPhuc s2){
    SoPhuc s3;
    s3.thuc=s1.thuc+s2.thuc;
    s3.ao=s1.ao+s2.ao;
    return s3;
}
SoPhuc operator-(SoPhuc s1,SoPhuc s2){
    SoPhuc s33;
    s33.thuc=s1.thuc-s2.thuc;
    s33.ao=s1.ao-s2.ao;
    return s33;
}
/*
a + bi)(c + di) = (ac - bd) + (ad + bc)i
*/
SoPhuc operator*(SoPhuc s1,SoPhuc s2){
    SoPhuc s333;
    s333.thuc = s1.thuc*s2.thuc -s1.ao *s2.ao;
    s333.ao= s1.thuc*s2.ao + s1.ao*s2.thuc;
    return s333;
}
SoPhuc operator/(SoPhuc s1,SoPhuc s2){
    SoPhuc s3333;
    float mau = pow(s2.thuc,2)+pow(s2.ao,2);
    s3333.thuc=(s1.thuc*s2.thuc +s1.ao *s2.ao)/mau;
    s3333.ao=(s1.ao*s2.thuc - s1.thuc*s2.ao)/mau;
    return s3333;
}
int main(){
    SoPhuc s1,s2,s3,s4;
    cout<<"\nNhap so phuc 1:";
    cin>>s1;
    cout<<"\nNhap so phuc 2:";
    cin>>s2;
    cout<<"\nNhap so phuc 3:";
    cin>>s3;
    cout<<"\nNhap so phuc 4:";
    cin>>s4;
    cout<<"\nSo phuc 1 la :"<<s1<<endl;
    cout<<"\nSo phuc 2 la :"<<s2<<endl;
    cout<<"\nSo phuc 3 la :"<<s3<<endl;
    cout<<"\nSo phuc 4 la :"<<s4<<endl;
    SoPhuc result= (s1+s2) / (s3-s2) *s4;
    cout<<"\nTong so phuc la :"<<result<<endl;
    return 0;
}