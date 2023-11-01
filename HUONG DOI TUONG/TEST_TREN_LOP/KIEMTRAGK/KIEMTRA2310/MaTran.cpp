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
        cin >> n ;
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
    float TongCacPhanTu(){
         float tong=0;
         for(int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                tong+=tp[i][j];
         }
    }
    return tong;
    }

     void GiaTriMin(){
        float Min = (float)INT_MAX;
        for (int i=0;i<n;i++){
            for (int j =0;j<n;j++){
               if(Min > tp[i][j]){
                Min = tp[i][j];
               }
            }
        }
        cout<<"Gia Tri Nho Nhat Cua Ma Tran: "<<Min<<endl;
    }
};
int main() {
    MT mt1;
    cout << "\nNhap ma tran :";
    mt1.NhapMaTran();
  
    mt1.XuatMaTran();
    cout <<"\nTong cac phan tu:"<<mt1.TongCacPhanTu()<<endl;
    mt1.GiaTriMin();
    return 0;
}
