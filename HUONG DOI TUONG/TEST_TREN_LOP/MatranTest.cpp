#include <bits/stdc++.h>
using namespace std;
void  NhapMaTran(float  **&a,int n){
   // Cấp phát một mảng con trỏ hai chiều chứa n con  trỏ tới dãy phần tử kiểu float 
    a= new float *[n];
    for (int  i=0;i<n;i++){
        a[i]=new float[n];
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
           cout<<"Nhap a["<<i+1<<"]["<<j+1<<"] :";
           cin >>a[i][j];// a[i*n+j]
        }
    }
}
void XuatMaTran(float **a,int n) {
    for (int i =0;i<n;i++) {
        for (int j=0;j<n; j++) {
            cout <<a[i][j] << " ";
        }
        cout << endl;
    }
}
void CongHaiMaTran(float **a, float **b, float **c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void NhanHaiMaTran(float **a, float **b, float **c, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = 0;
            for (int k = 0; k < n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
      float **a, **b,**c;
    cout <<"\nNhap ma tran A:"<<endl;
    NhapMaTran(a, n);
    cout <<"\nNhap ma tran B:"<<endl;
    NhapMaTran(b, n);
    cout << "Ma tran A:\n";
    XuatMaTran(a, n);
    cout << "Ma tran B:\n";
    XuatMaTran(b, n);
    c = new float *[n]; // Cấp phát mảng con trỏ cho ma trận kết quả
    for (int i = 0; i < n; i++) {
        c[i] = new float[n]; // Cấp phát mảng con cho ma trận kết quả
    }
    CongHaiMaTran(a, b, c, n);
    cout << "Ma tran tong:\n";
    XuatMaTran(c, n);
    NhanHaiMaTran(a, b, c, n);
    cout << "Ma tran tich:\n";
    XuatMaTran(c, n);
    return 0;
}