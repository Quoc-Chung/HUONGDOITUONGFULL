#include<bits/stdc++.h>
using namespace std;
class MT{
    private :
       int n;
       float **tp;
    public :
    // Ham khoi tao
        MT() {
        n = 0;
        tp=NULL;
    }
    // Ham khoi tao gia tri truyen vao 
      MT(int n) {
        this->n = n;
        tp = new float*[n];
        for (int i = 0; i < n ; i++) {
            tp[i] = new float[n];
        }
    }
    friend istream& operator>> (istream &is , MT &mt){
    	do {
            cout << "\nNhap n:";
            is >>  mt.n;
            if ( mt.n < 0) {
                cout << "\nVui long nhap lai.\n";
            }
        }while (mt.n < 0);
           mt.tp = new float *[mt.n];
        for (int i = 0; i < mt.n; i++) {
           mt.tp[i] = new float[mt.n];
        }
        for(int i=0;i<mt.n;i++){
            for (int j=0;j<mt.n;j++){
                cout<<"Nhap tp["<<i<<"]"<<"["<<j<<"]:" ;
                is>>mt.tp[i][j] ;
            }
        }
        return is;
	}
	friend ostream& operator<< (ostream &os ,MT &mt){
		 for (int i=0;i<mt.n;i++){
            for(int j=0;j<mt.n;j++){
                os<< mt.tp[i][j]<<" ";
            }
            cout<<endl;
        }
		return os;
	}
    void NhapMaTran(){
       do {
            cout << "\nNhap n:";
            cin >>  n;
            if ( n < 0) {
                cout << "\nVui long nhap lai.\n";
            }
        }while (n < 0);
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
    
    cout<<"\nNhap ma tran thu hai :"<<endl;
    cin >> mt2;
    cout<<"\nMA tran thu hai la :"<<endl;
    cout<<mt2;
    return 0;
}

