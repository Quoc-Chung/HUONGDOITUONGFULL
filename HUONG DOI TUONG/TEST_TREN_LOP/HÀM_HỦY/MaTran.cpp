#include<bits/stdc++.h>
using namespace std;
class MT{
    private :
       int m,n;
       // Khai báo một con trỏ cấp 2
       float **tp;
    public :
       // Hàm khởi tạo 
        MT() {
        m = n = 0;
        tp=nullptr;
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
   void TrungBinhCongAm(){
    float tong =0;
    int dem=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;i++){
            tong+=tp[i][j];
            dem++;
        }
    }
    float tbc = tong /dem;
    cout<<"\nTrung binh cong am la:"<<tbc<<endl;
   }
   void TongCacPhanTuTungHang(){
    cout<<"\ntong tung hang la:"<<endl;
      for (int i=0;i<m ;i++){
        int  tong=0;
        for (int j=0;j<n;j++){
            tong+=tp[i][j];
        }
        cout<<"\n"<<tong<<endl;
      }
   }
};
int main() {
    MT mt1, mt2;
    cout << "\nNhap ma tran thu nhat:";
    mt1.NhapMaTran();
    cout << "\nMa tran thu nhat la :\n";
    mt1.XuatMaTran();
    return 0;
}