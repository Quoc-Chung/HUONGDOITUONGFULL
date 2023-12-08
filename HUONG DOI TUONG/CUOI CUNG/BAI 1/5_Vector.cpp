// Xay dung lop vector : 
// Thuoc tinh : n ( chieu ) , tp ( gia tri thanh phan ) 
// Phuong thuc  :tao , huy , nhap , xuat , cong tru hai vector  , tich vo huong 
#include<bits/stdc++.h>
using namespace std;
class Vector{
  private :
    int n; //So chieu
    float *tp;
  public :
    Vector(){
       n=0;
       tp=NULL;
    }
    Vector(int n){
        this->n =n;
        this->tp =new float[n];
    }
    ~Vector(){
        delete[] tp;
    }
    
    friend istream& operator>> (istream &is, Vector &vt){   
    do {
        cout << "\nNhap so chieu :";
        is >> vt.n;
        if (vt.n < 0) {
            cout << "\nVui long nhap lai.\n";
        }
    } while (vt.n < 0);
        vt.tp =new float [vt.n];
        for (int i=0;i<vt.n;i++){
            cout<<"\nNhap chieu "<<i<<":";
           is >>vt.tp[i];
        }
    	return is;
    }
    
    friend ostream& operator<< (ostream &os, Vector &vt){
        os<<"(";
        for(int i=0;i<vt.n-1;i++){
            os<<vt.tp[i]<<" , ";
        }
        os<<vt.tp[vt.n-1]<<")"<<endl;
    	return os;
    }
    
    void Nhap(){
        do {
        cout << "\nNhap so chieu :";
        cin >> n;
        if (n < 0) {
            cout << "\nVui long nhap lai.\n";
        }
    } while (n < 0);
        tp =new float [n];
        for (int i=0;i<n;i++){
            cout<<"\nNhap chieu "<<i<<":";
           cin >>tp[i];
        }
    }
    void Xuat(){
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
    // Xay dung ham toan tu 
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
    cin >> vt2;
    
    cout<<"\nVector thu nhat la :";
    vt1.Xuat();
    cout<<"\nVector thu hai la :";
    cout<< vt2;

    Vector vt3 = vt1 + vt2 ;
    Vector vt4 = vt1 - vt2 ;
    float Tich = vt1.TichVoHuong(vt2);
    cout<<"\nTich vo huong cua hai vector la :"<<Tich <<endl;
    return 0;
}
