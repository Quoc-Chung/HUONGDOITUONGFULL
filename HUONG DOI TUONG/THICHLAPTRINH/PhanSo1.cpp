//Liên kết với tệp gốc 
#include "PhanSo.h"
#include <iostream>
using namespace std;

void PhanSo::Nhap() {
    cout << "\nNhap tu so: ";
    cin >> TuSo;
    cout << "\nNhap mau so: ";
    cin >> MauSo;
}
void PhanSo::Xuat() {
    cout << "\nPhan So la: " << TuSo << "/" << MauSo << endl;
}