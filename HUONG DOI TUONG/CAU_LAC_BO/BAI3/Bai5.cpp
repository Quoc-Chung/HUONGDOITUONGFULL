#include<bits/stdc++.h>
using namespace std;
// Dùng đệ quy 
int Fibo(int n) {
    if (n<=1) {
        return n;
    }
    return Fibo(n-1)+Fibo(n-2);
}
// Tính số  fibonaci thứ k
void FibonacciLoop(int n) {
    int a = 0, b = 1;
    cout << "Cac so Fibonacci dau tien: ";
    for (int i = 0; i < n; i++) {
        cout << a << " ";
        int next = a + b;
        a = b;
        b = next;
    }
}
bool HoanHao(int x) {
    int s = sqrt(x);
    return s * s == x;
}

bool IsFibonacci(int x) {
    return HoanHao(5 * x * x + 4) || HoanHao(5 * x *x- 4);
}
int main() {
    int n = 50;
    // cout << "Cac so Fibonacci dau tien: ";
    // for (int i = 0; i < n; i++) {
    //     cout<<Fibo(i)<<" ";
    // }
    int soKT;
    cout<<"\nNhap so kiem tra:";
    cin>>soKT;
     if(IsFibonacci(soKT)){
        cout<<"\nLa so fibonaci"<<endl;
     }
     else{
        cout<<"\nKHong la so fibonaci"<<endl;
     }
    return 0;
}