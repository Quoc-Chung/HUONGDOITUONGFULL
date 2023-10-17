/*
-Nhập các phép toán >> , << ,1  vector với số chiều  tự do , làm các  thao tác  cộng  ,nhân ,
các vector u,v,t
- In ra các vector vừa nhập và tính u+v, u*v (vô hướng) , u*k +t
*/
#include<bits/stdc++.h>
using namespace std;
struct vectorx{
  int SoChieu;
  float *tp; //Thành phần trong vector
};
// Hàm nhập vector
istream& operator>>(istream& is ,vectorx &vt){
    cout<<"\nNhap so chieu:";
    is >>vt.SoChieu;
    //Cấp phát cho tọa độ của vector
    vt.tp = new float[vt.SoChieu];
    for (int i=0;i<vt.SoChieu;i++){
        cout<<"\nNhap tp thu "<<i+1 <<":";
        is>>vt.tp[i];
    }
    return is;
}
// Hàm in vector
ostream& operator<<(ostream& os,vectorx &vt){
    os << "(";
    for (int i = 0; i < vt.SoChieu; ++i) {
        os << vt.tp[i];
        if (i < vt.SoChieu - 1) {
            os <<" , ";
        }
    }
   os << ")" << endl;
    return os;
}
vectorx operator+(vectorx &vt1, vectorx &vt2) {
    vectorx vt3;
    vt3.SoChieu = max(vt1.SoChieu, vt2.SoChieu);
    vt3.tp = new float[vt3.SoChieu];
    for (int i = 0; i < vt3.SoChieu; ++i) {
       int value1, value2;
           if (i < vt1.SoChieu) {
                value1 = vt1.tp[i];
            } 
            else {
             value1 = 0;
            }
           if (i < vt2.SoChieu) {
               value2 = vt2.tp[i];
            } else {
               value2 = 0;
           }
        vt3.tp[i] = value1 + value2;
    }
  return vt3;
}
float operator*(vectorx &vt1,vectorx &vt2){
    float z =0;
    int minChieu =min(vt1.SoChieu,vt2.SoChieu);
    for (int i=0;i<minChieu;i++){
      z += vt1.tp[i] * vt2.tp[i];
    }
    return z;
}
vectorx operator*(vectorx &vt1, int k) {
    vectorx tmp;
    tmp.SoChieu = vt1.SoChieu;
    tmp.tp = new float[tmp.SoChieu];
    for (int i = 0; i < vt1.SoChieu; i++) {
        tmp.tp[i] = vt1.tp[i] * k;
    }
    return tmp;
}
int main() {
    vectorx vt1, vt2,vt3;
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
    vectorx Tong= vt1+vt2;
    cout<<Tong<<endl;

    cout<<"\n u*v la :";
     float  Nhan=vt1*vt2;
    cout<<Nhan<<endl;

   int  k;
    cout<<"\nNhap gia tri k:";
    cin >>k;
    vectorx trunggian=vt1*k;
    vectorx  tonghop = trunggian+vt3;
    cout<<"k*u+t ="<<tonghop<<endl;
    return 0; 
}
