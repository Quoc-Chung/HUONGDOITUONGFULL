#include<bits/stdc++.h>
using namespace std;
class DaySo{
    private:
      int n;
      float *a;
    public:
       DaySo(){
        n =0;
        a=new float[n];
        for(int i=0;i<n;i++){
            a[i]=0;
        }
    }
    DaySo(int n) {
        this->n =n;
        this->a = new float[n];
   }
    // Ham huy
     ~DaySo() {
        delete[] a; 
    }   
	friend istream& operator>> (istream& is,DaySo &ds){
		do {
            cout << "\nNhap n :";
            is >> ds.n;
            if (ds.n < 0) {
                cout << "\nVui long nhap lai.\n";
            }
       }while (ds.n < 0);
        ds.a = new float [ds.n];
        if(ds.a == NULL){
            cout<<"\nKhong cap phat duoc";
            exit(0);
        }
        for(int i=0;i<ds.n;i++){
          is >>ds.a[i];
        }
        return is;
    }


    friend ostream& operator<<(ostream& os,DaySo &ds){
        for(int i=0;i<ds.n;i++){
            os<<ds.a[i]<<" ";
        }
        return os; 
    } 
    
    void NhapDaThuc(){
        do {
            cout << "\nNhap n :";
            cin >> n;
            if (n < 0) {
                cout << "\nVui long nhap lai.\n";
            }
       }while (n < 0);
        a = new float [n+1];
        if(a == NULL){
            cout<<"\nKhong cap phat duoc";
            exit(0);
        }
        for(int i=0;i<n ;i++){
          cin >>a[i];
        }
    }

    void XuatDaThuc(){
        for(int i=0;i< n;i++){
            cout<<a[i]<<" ";
        }
    } 
    // Tim gia tri max  { a[1]/1 ,..., a[n]/n } 
   void GiaTriMax(){
    float max =(float)INT_MIN;
    for(int i=0;i<n;i++){
        if(max < a[i]/(i+1)){
            max = a[i] / (i+1);
        }
    }
    cout<<"\nMax la : "<<fixed<<setprecision(2)<<max << endl;
   }
   // Tinh tong  (a1+a2) /(a1-a2) + (a2+a3)/(a2-a3)  + (an-1 + a[n]) / an-1 - an)
   void TinhTong(){
    float tong =0;
    for (int i=0;i<n-1;i++){
        tong+=(a[i]+a[i+1])/(a[i]-a[i+1]);
        }
       cout<<"\nTong can tim : "<<fixed<<setprecision(2)<<tong << endl;
    }


};
int main(){
    DaySo ds;
    cout<<"\nNHAP DAY SO :"<<endl;
    cin >> ds;
    cout<<"\nDay so vua nhap la :"<<endl;
    cout<<ds;
    ds.GiaTriMax();
    ds.TinhTong();
    return 0;

}