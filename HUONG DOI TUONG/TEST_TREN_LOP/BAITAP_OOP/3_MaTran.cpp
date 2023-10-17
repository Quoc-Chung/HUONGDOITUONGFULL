// 1. Xây dựng lớp MT(ma trận vuông):
// - Thuộc tính: n(cấp của ma trận), tp(các phần tử của ma trận)
// - Phương thức:
//  Hàm nhập ma trận, in ma trận.
// Viết hàm bè bạn cho phép tính :
// - Tổng các phần tử của ma trận 
// - Tìm giá trị nhỏ nhất của ma trận
// - Nhập một ma trận
// Bài tập môn lập trình hướng đối tượng và C++
// - In ra ma trận
// - Tính tổng các phần tử của ma trận
// - Một giá trị nhỏ nhất của ma trận
#include<bits/stdc++.h>
using namespace std;
class MT{
    private :
       int n;
       float **tp;
    public :
       // Hàm khởi tạo 
        MT() {
        n = 0;
        tp=nullptr;
    }
    // Hàm khởi tạo có đối số truyền vào
       MT(int n){
        this-> n = n;
        tp =new float *[n];
        for (int i=0; i<n; i++){
            tp[i] =new float[n];
        }
    }
       void NhapMaTran(){
        cout<<"\nNhap n:";
        cin >>n ;
           tp = new float *[n];
        for (int i = 0; i < n; i++) {
           tp[i] = new float[n];
        }
        for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cout<<"Nhap tp["<<i<<"]"<<"["<<j<<"]:" ;
                cin >>tp[i][j] ;
            }
        }
    }
    void XuatMaTran(){
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<< tp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
   friend float TongCacPhanTu(MT &mt){
         float tong=0;
         for(int i=0;i<mt.n;i++){
            for (int j=0;j<mt.n;j++){
                tong+=mt.tp[i][j];
         }
    }
    return tong;
    }
    friend void GiaTriMin(MT &mt){
        float Min = (float)INT_MAX;
        for (int i=0;i<mt.n;i++){
            for (int j =0;j<mt.n;j++){
               if(Min > mt.tp[i][j]){
                Min = mt.tp[i][j];
               }
            }
        }
        cout<<"Gia Tri Nho Nhat Cua Ma Tran: "<<Min<<endl;
    }
    MT operator+(MT &mt2) {
        MT Tong;
        Tong.n = n; // Gán cấp của ma trận tổng bằng cấp của ma trận 1 hoặc 2 đều được.
        Tong.tp = new float *[n];
        for (int i = 0; i < n; i++) {
            Tong.tp[i] = new float[n];
            }
            for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Tong.tp[i][j] = tp[i][j] + mt2.tp[i][j];
            }
        }
        return Tong;
    }
};
int main() {
    MT mt1, mt2;
    cout << "\nNhap ma tran thu nhat:";
    mt1.NhapMaTran();
    cout << "\nNhap ma tran thu hai:";
    mt2.NhapMaTran();
    cout << "\nMa tran thu nhat la :\n";
    mt1.XuatMaTran();
    cout << "\nMa tran thu hai la :\n";
    mt2.XuatMaTran();

    MT result = mt1 + mt2;
    cout << "\nMa tran tong la :\n";
    result.XuatMaTran();
    return 0;
}
/*
  MT() {
        n = 0;
        tp = new float *[n];
        for (int i = 0; i < n; i++) {
            tp[i] = new float[n];
            for (int j = 0; j < n; j++) {
                tp[i][j] = 0; // Gán giá trị mặc định cho các phần tử của ma trận
            }
        }
    }
*/