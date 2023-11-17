#include<bits/stdc++.h>
using namespace std;
class MT{
    private :
       int m,n;
       float **tp;
    public :
       // Hàm khởi tạo 
        MT() {
        m = n = 0;
        tp=NULL;
    }
    // Hàm khởi tạo có đối số truyền vào
      MT(int m, int n) {
        this->m = m;
        this->n = n;
        tp = new float*[m];
        for (int i = 0; i < m; i++) {
            tp[i] = new float[n];
        }
    }
       void NhapMaTran(){
        cout<<"\nNhap m va n:";
        cin >>m>>n  ;
           tp = new float *[m];
        for (int i = 0; i < m; i++) {
           tp[i] = new float[n];
        }
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                cout<<"Nhap tp["<<i<<"]"<<"["<<j<<"]:" ;
                cin >>tp[i][j] ;
            }
        }
    }
    void XuatMaTran(){
        for (int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<< tp[i][j]<<" ";
            }
            cout<<endl;
        }
    }
   friend float TongCacPhanTu(MT &mt){
         float tong=0;
         for(int i=0;i<mt.m;i++){
            for (int j=0;j<mt.n;j++){
                tong+=mt.tp[i][j];
         }
    }
    return tong;
    }
    friend void GiaTriMin(MT &mt){
        float Min = (float)INT_MAX;
        for (int i=0;i<mt.m;i++){
            for (int j =0;j<mt.n;j++){
               if(Min > mt.tp[i][j]){
                Min = mt.tp[i][j];
               }
            }
        }
        cout<<"Gia Tri Nho Nhat Cua Ma Tran: "<<Min<<endl;
    }
};
int main() {
    MT mt1, mt2;
    cout << "\nNhap ma tran thu nhat:";
    mt1.NhapMaTran();
    cout << "\nMa tran thu nhat la :\n";
    mt1.XuatMaTran();
    float result = TongCacPhanTu(mt1);
    cout<<"\nTong cac phan tu cua ma tran la:"<<result<<endl;
    GiaTriMin(mt1); 
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