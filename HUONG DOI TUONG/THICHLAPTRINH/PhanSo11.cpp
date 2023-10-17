// Liên kết với tệp  header file
#include "PhanSo.h"
#include <iostream>
using namespace std;
int main() {
    PhanSo p1;
    p1.Nhap();
    cout << "\nPhan So la: ";
    p1.Xuat();

//    p2.Nhap();
//    cout << "\nPhan So la: ";
//    p2.Xuat();
    return 0;
}