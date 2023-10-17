#include <iostream>
using namespace std;
struct MaTran {
    int m, n;
    int** a;
};
istream& operator>>(istream& is, MaTran& mt) {
    cout << "Nhap so hang m: ";
    is >> mt.m;
    cout << "Nhap so cot n: ";
    is >> mt.n;
    // Cấp phát bộ nhớ động cho ma trận
    mt.a = new int*[mt.m];
    for (int i = 0; i < mt.m; i++) {
        mt.a[i] = new int[mt.n];
    }
    //-----------------------------------
        for (int i = 0;i <mt.m; i++) {
        for (int j = 0;j< mt.n; j++) {
            cout << "Nhap gia tri a[" << i << "][" << j << "]: ";
            is >> mt.a[i][j];
        }
    }
    return is;
}
ostream& operator<<(ostream& os, MaTran& mt) {
    os<<"\nMa tran vua nhap la :\n";
    for (int i=0;i<mt.m;i++){
        for (int j=0;j<mt.n;j++){
           os<<mt.a[i][j]<<" ";
        }
        os<<endl;
    }
    return os;
}
MaTran operator+(MaTran mt1, MaTran mt2){
    MaTran result;
    result.m=mt1.m;
    result.n=mt1.n;
    result.a = new int*[mt1.m];
    for (int i = 0; i < mt1.m; i++) {
        result.a[i] = new int[mt1.n];
    }
    for (int i=0;i<mt1.m;i++){
        for (int j=0;j<mt1.n ;j++){
            result.a[i][j] =mt1.a[i][j]+mt2.a[i][j];
        }
    }
    return result;
}
int operator!(MaTran mt1){
   int tong=0;
   for (int i=0;i<mt1.m;i++){
    for (int j=0;j<mt1.n;j++){
     tong+=mt1.a[i][j];
    } 
   }
   return tong;
}
int main() {
    MaTran mt1,mt2;
    cout<<"\nNhap ma tran thu nhat:"<<endl;
    cin >> mt1;
    // Hiển thị ma trận
    cout<<mt1;
    cout<<"\nNhap ma tran thu hai :"<<endl;
    cin >>mt2;
    cout<<mt2;

    int tong1 =!mt1;
    int tong2 =!mt2;
    cout<< "\nTong thu nhat la:"<<tong1 <<"\nTong thu hai :"<<tong2<<endl;
    MaTran result =mt1+mt2;
    cout<<"\nTong hai ma tran la :"<<endl;
    cout<<result;
    // Giải phóng bộ nhớ
    for (int i = 0; i < mt1.m; i++) {
        delete[] mt1.a[i];
    }
    delete[] mt1.a;

    return 0;
}
