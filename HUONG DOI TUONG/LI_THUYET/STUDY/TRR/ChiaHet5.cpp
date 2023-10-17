#include<bits/stdc++.h>
using namespace std;
int main(){
    int n =100;
    int dem =0;
    for(int i = n ;i<= 999;i++){
        if(i % 5 ==0){
            dem++;
        }
    }
    cout<<dem<<endl;
}