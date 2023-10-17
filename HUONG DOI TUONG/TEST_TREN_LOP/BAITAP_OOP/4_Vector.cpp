// Xây dựng lớp vecto:
// - Thuộc tính: n (số chiều), tp(giá trị thành phần)
// - Phương thức: tạo, huỷ, nhập, xuất, cộng-trừ hai vecto, tích vô hương hai vecto.
// Câu 6: Cũng xây dựng lớp vecto như trên nhưng tải bội các phép toán nhập, xuất, cộng, 
// trừ, tích vô hướng.
#include<bits/stdc++.h>
using namespace std;
class Vector{
  private :
    int n; //So chieu
    float *tp;
  public :
    Vector(){
       n=0;
       tp=nullptr;
    }
    Vector(int n){
        this->n =n;
        this->tp =new float[n];
    }
    ~Vector(){
        delete[] tp;
    }
    void Nhap(){
        cout<<"\nNhap so chieu :";
        cin >> n;
        tp =new float [n];
        for (int i=0;i<n;i++){
            cout<<"\nNhap chieu "<<i<<":";
           cin >>tp[i];
        }
    }
    void Xuat(){
        cout<<"\nVector vua nhap la:"<<endl;
        cout<<"(";
        for(int i=0;i<n-1;i++){
            cout<<tp[i]<<" , ";
        }
        cout<<tp[n-1]<<")"<<endl;
    }
    Vector TongHaiVector(Vector &vt2){
        Vector Tong;
        Tong.n =max(n,vt2.n);
        Tong.tp =new float[Tong.n];
        for(int i=0;i<Tong.n;i++){
            float so1 = (i < n) ? tp[i] : 0;
            float so2 = (i < vt2.n) ? vt2.tp[i] : 0;
            Tong.tp[i] = so1+ so2;
        }
        return Tong;
    }
    // Xây dựng các  hàm toán tử 
    Vector operator+(Vector &vt2){
        Vector Tong;
        Tong.n =max(n,vt2.n);
        Tong.tp =new float[Tong.n];
        for(int i=0;i<Tong.n;i++){
            float so1 = (i < n) ? tp[i] : 0;
            float so2 = (i < vt2.n) ? vt2.tp[i] : 0;
            Tong.tp[i] = so1+ so2;
        }
        return Tong;
    }
    Vector operator-(Vector &vt2){
        Vector Hieu;
        Hieu.n =max(n,vt2.n);
        Hieu.tp =new float[Hieu.n];
        for(int i=0;i<Hieu.n;i++){
            float so1 = (i < n) ? tp[i] : 0;
            float so2 = (i < vt2.n) ? vt2.tp[i] : 0;
            Hieu.tp[i] = so1- so2;
        }
        return Hieu;
    }
   float TichVoHuong(Vector &vt2){
    float tich=0;
    for (int i=0;i<max(n,vt2.n) ;i++){
         float tmp1 = (i < n) ? tp[i] : 0;
         float tmp2 = (i < vt2.n) ? vt2.tp[i] : 0;
         tich+=tmp1 *tmp2; 
    }
    return tich ;
   }
};
int main (){
    Vector vt1,vt2;
    cout<<"\nNhap vector thu nhat :";
    vt1.Nhap();
    cout<<"\nNhap vector thu hai :";
    vt2.Nhap();

    cout<<"\nVector thu nhat vua tao :";
    vt1.Xuat();
    cout<<"\nVector thu hai la :";
    vt2.Xuat();

    Vector vt3 = vt1 + vt2 ;
    Vector vt4 = vt1 - vt2 ;
    float Tich = vt1.TichVoHuong(vt2);
    cout<<"\nTich vo huong cua hai vector la :"<<Tich <<endl;
    return 0;
}