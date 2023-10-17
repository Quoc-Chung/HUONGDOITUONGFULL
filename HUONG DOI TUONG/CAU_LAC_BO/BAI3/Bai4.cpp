#include<bits/stdc++.h>
using namespace std;
void Nhap(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<"\nNhap a["<<i+1<<"]:";
        cin>>a[i];
    }
}
void swap(int &a,int &b){
  int tmp =a;
  a=b;
  b=tmp;
}
void SapXep(int *a,int n){
 for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
          swap(a[i],a[j]);
        }
    }
 }
}
int main(){
    int *a;
    int n;
      a=new int[n];
    cout<<"Nhap n :";
    cin>>n;
    Nhap(a,n);
    SapXep(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}