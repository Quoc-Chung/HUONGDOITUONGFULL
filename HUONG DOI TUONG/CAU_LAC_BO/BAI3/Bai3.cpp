#include<bits/stdc++.h>
using namespace std;
int USCLN(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main(){
    int  N;
    cin >>N;
    int  *a =new int[N];
    if(a==NULL){
        cout << "Error" << endl;
        return 0;
    }
    for  (int i=0;i<N;i++){
       cin >> a[i];
    }
    int result=0;
    for (int i=0;i<N-1;i++){
        for (int j=i+1;j<N;j++)
       result =max(USCLN(a[i],a[j]),result);
    }
    cout<<"\n"<<result<<endl;
}
