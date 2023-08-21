#include<bits/stdc++.h>
using namespace std;
struct SoPhuc {
 float thuc;
 float ao;
};
void Nhap (SoPhuc &sp){
   cout <<"\nNhap phan thuc  :";
   cin>> sp.thuc;
   cout<<"\nNhap phan ao";
   cin >> sp.ao;
}
void In(SoPhuc sp) {
        cout << sp.thuc << "+ (" << sp.ao << ")" << "i" << endl;
}
SoPhuc Cong(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    kq.thuc = a.thuc + b.thuc;
    kq.ao = a.ao + b.ao;
    return kq;
}
SoPhuc Tru(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    kq.thuc = a.thuc - b.thuc;
    kq.ao = a.ao - b.ao;
    return kq;
}
SoPhuc Nhan(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    kq.thuc = a.thuc * b.thuc - a.ao * b.ao;
    kq.ao = a.thuc * b.ao + a.ao * b.thuc;
    return kq;
}
SoPhuc Chia(SoPhuc a, SoPhuc b) {
    SoPhuc kq;
    int mau = b.thuc * b.thuc + b.ao * b.ao;
    kq.thuc = (a.thuc * b.thuc + a.ao * b.ao) / mau;
    kq.ao = (a.ao * b.thuc - a.thuc * b.ao) / mau;
    return kq;
}
int main() {
    SoPhuc c1, c2, c3;
    Nhap(c1);
    Nhap(c2);
    Nhap(c3);
    In(c1);
    In(c2);
    In(c3);
    SoPhuc KQT = Nhan(Chia(Cong(c1, c2), Tru(c1, c2)), c3);  
    In(KQT);
    return 0;
}