#include<bits/stdc++.h>
using  namespace std;
struct VectorN {
    int SoChieu;
    vector<float> GiaTri; 
};
istream& operator>>(istream& is, VectorN& vt) {
    cout << "Nhap so chieu : ";
    is >> vt.SoChieu;
    vt.GiaTri.resize(vt.SoChieu);

    for (int i = 0; i < vt.SoChieu; ++i) {
        cout << "Nhap gia tri thu " << i + 1 << ": ";
        is >> vt.GiaTri[i];
    }

    return is;
}
ostream& operator<<(ostream& os, VectorN &vt) {
    os << "(";
    for (int i = 0; i < vt.SoChieu; ++i) {
        os << vt.GiaTri[i];
        if (i < vt.SoChieu - 1) {
            os << ", ";
        }
    }
   os << ")" << endl;
    return os;
}
VectorN operator+(VectorN &vt1, VectorN &vt2) {
    VectorN vt3;
    vt3.SoChieu = max(vt1.SoChieu, vt2.SoChieu);
    vt3.GiaTri.resize(vt3.SoChieu);
    for (int i = 0; i < vt3.SoChieu; ++i) {
       int value1, value2;
           if (i < vt1.SoChieu) {
                value1 = vt1.GiaTri[i];
            } 
            else {
             value1 = 0;
            }

           if (i < vt2.SoChieu) {
               value2 = vt2.GiaTri[i];
            } else {
               value2 = 0;
           }
        vt3.GiaTri[i] = value1 + value2;
    }
  return vt3;
}
float operator*(VectorN &vt1, VectorN &vt2) {
    float x;
    VectorN vt3;
    vt3.SoChieu = max(vt1.SoChieu, vt2.SoChieu);
    vt3.GiaTri.resize(vt3.SoChieu);
    for (int i = 0; i < vt3.SoChieu; ++i) {
       int value1, value2;
           if (i < vt1.SoChieu) {
                value1 = vt1.GiaTri[i];
            } 
            else {
             value1 = 0;
            }

           if (i < vt2.SoChieu) {
               value2 = vt2.GiaTri[i];
            } else {
               value2 = 0;
           }
        vt3.GiaTri[i] = value1 * value2;
        x +=vt3.GiaTri[i];
    }
  return x;
}
VectorN TichMotSo(VectorN &vt1,int k){
    VectorN tmp;
    tmp.SoChieu = vt1.SoChieu;
    tmp.GiaTri.resize(vt1.SoChieu);
    for (int i=0;i<vt1.SoChieu;i++){
        tmp.GiaTri[i]=k*vt1.GiaTri[i];
    }
    return tmp;
}
int main() {
    VectorN vt1, vt2,vt3;
    cout << "Nhap vector u:\n";
    cin >> vt1;
    cout << "Nhap vector v:\n";
    cin >> vt2;
    cout << "Nhap vector t:\n";
    cin >> vt3;
    cout << "Vector u: " << vt1 << endl;
    cout << "Vector v: " << vt2 << endl;
    cout << "Vector v: " << vt3 << endl;
    cout<<"\n u+v la :";
    VectorN Tong= vt1+vt2;
    cout<<Tong<<endl;

    cout<<"\n u*v la :";
     float  Nhan=vt1*vt2;
    cout<<Nhan<<endl;

   int  k;
    cout<<"\nNhap gia tri k:";
    cin >>k;
    VectorN trunggian=TichMotSo(vt1,k);
    VectorN  tonghop = trunggian+vt3;
    cout<<"k*u+t ="<<tonghop<<endl;
    return 0;
    
}