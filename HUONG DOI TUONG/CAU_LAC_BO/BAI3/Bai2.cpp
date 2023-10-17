#include<bits/stdc++.h>
using namespace std;
bool NguyenTo(int n){
    if(n<2){
       return false;
    }
    else{
        for (int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int N;
    cout<<"\nNhap n:";
    cin >>N;
    cout<<"\nTat ca cac so nguyen  to la :\n";
    for (int i=0;i<N;i++){
        if(NguyenTo(i)){
            cout<<i<<" ";
        }
    }
}