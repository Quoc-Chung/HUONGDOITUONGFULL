#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
void NhapMaTran(float **&a, int n) {
    a = new float *[n]; // Cấp phát mảng con trỏ
    for (int i = 0; i < n; i++) {
        a[i] = new float[n]; // Cấp phát mảng con
        for (int j = 0; j < n; j++) {
            cout << "[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }
}

void InMaTran(float **a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout<< endl;
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
int main() {
    int n;
    cin >> n;
    float **a, **b, **c;
    cout <<"\nNhap ma tran A:"<<endl;
    NhapMaTran(a, n);
    cout <<"\nNhap ma tran B:"<<endl;
    NhapMaTran(b, n);
    cout << "Ma tran A:\n";
    InMaTran(a, n);

    cout << "Ma tran B:\n";
    InMaTran(b, n);

    c = new float *[n]; // Cấp phát mảng con trỏ cho ma trận kết quả
    for (int i = 0; i < n; i++) {
        c[i] = new float[n]; // Cấp phát mảng con cho ma trận kết quả
    }
    CongHaiMaTran(a, b, c, n);
    cout << "Ma tran tong:\n";
    InMaTran(c, n);
    NhanHaiMaTran(a, b, c, n);
    cout << "Ma tran tich:\n";
    InMaTran(c, n);
    return 0;
}
