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
    
   friend float operator!(MT &mt){
         float tong=0;
         for(int i=0;i<mt.n;i++){
            for (int j=0;j<mt.n;j++){
                tong+=mt.tp[i][j];
         }
    }
    return tong;
    }
    
    MT operator+(MT &mt2){
    	MT tong;
    	tong.n = n;
    	tong.tp = new float *[tong.n];
        for (int i = 0; i < tong.n; i++) {
           tong.tp[i] = new float[tong.n];
        }
    	if(n == mt2.n){
    	for (int i =0;i<n;i++){
    		for(int j = 0;j<n;j++){
    		tong.tp[i][j] = tp[i][j] + mt2.tp[i][j];
          }
        }
     }
     else{
     	cout<<"\nKhong the cong hai ma tran khac kich thuoc"<<endl;
	 }
     return tong;
    }
};
int main() {
    MT mt1, mt2;
    cout << "\nNhap ma tran thu nhat:";
    cin>> mt1;
    cout << "\nMa tran thu nhat la :\n";
    cout <<mt1;
    cout<<"\nNhap ma tran thu hai :"<<endl;
    cin >> mt2;
    cout<<"\nMA tran thu hai la :"<<endl;
    cout<<mt2;
    
    float result = !mt1;
    cout<<"\nTong cac phan tu cua ma tran la:"<<result<<endl;
    
    MT tong = mt1+mt2;
    cout<<"\nMa tran tong la :"<<endl;
    cout<<tong;
	return 0;
}