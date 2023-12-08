
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
    void TongDaySo (){
        float Tong =0;
        for (int i=0;i<n;i++){
            Tong+=a[i];
        }
        cout <<"\nTong day so la :"<<Tong<<endl;
    }
    void TongSoChan(){
        float Tong =0;
        bool check = false;
        for (int i=0;i<n;i++){
            if((int)a[i] %2 ==0){
                Tong+=a[i];
                check = true;
            }
        }
        if(check){
            cout <<"\nTong cac so chan la :"<<Tong<<endl;
        }
        else{
            cout<<"\nDay khong co  so chan"<<endl;
        }     
    }
    void InCacSoLienTiepTaoCapSoCong() {
        bool check = false;
        cout << "\nCac so lien tiep tao thanh cap so cong: " << endl;
        for (int i = 0; i < n - 2; i++) {
            if ((a[i+1] - a[i]  == a[i+2] - a[i+1]) || (a[i]- a[i+1] == a[i+2] - a[i]) ||(a[i+2] - a[i] == a[i+1] -a[i+2])){
                cout << a[i] << " , " << a[i + 1] << " , " << a[i + 2] << endl;
                check = true;
            }
        }
        if (!check) {
            cout << "\nKhong co ba so nao lien tiep trong day thoa man." << endl;
        }
   }
   void TongBangX (float x){
    float Tong = 0;
    for(int i=0;i<n;i++){
        Tong +=a[i];
    }
    if(Tong == x){
        cout<<"\nDay so co tong bang x "<<endl;
    }
    else{
        cout<<"\nDay so khoong co tong bang x"<<endl;
    }
   }
   // Tich ba so lien tiep co tong lon nhat
   void tich3lientiep(){
	float so1=0.0,so2=0.0,so3=0.0;
	int max=-pow(10,5);
	for (int i=0;i<n-2;i++){
		if(max<a[i]*a[i+1]*a[i+2]){
			max=a[i]*a[i+1]*a[i+2];
			so1=a[i];
			so2=a[i+1];
			so3=a[i+2];
		}
	}
    cout <<"\nBa so lien tiep co tich lon nhat :"<< so1 <<" "<< so2 <<" "<<so3<<endl;
}


};
int main(){
    DaySo ds;
    cout<<"\nNHAP DAY SO :"<<endl;
    cin >> ds;
    cout<<"\nDay so vua nhap la :"<<endl;
    cout<<ds;

    ds.TongDaySo();
    ds.TongSoChan();
    ds.InCacSoLienTiepTaoCapSoCong();
    
    float x;
    cout <<"\nNhap so x :";
    cin >>x;
    ds.TongBangX(x);
    ds.tich3lientiep();
    return 0;

}
/*
a[i+1] - a[i]  == a[i+2] - a[i+1]                              a[i] a[i+1] a[+2]
a[i]- a[i+1] == a[i+2] - a[i];                                 a[i+1] a[i] a[i+2]
a[i+2] - a[i] == a[i+1] -a[i+2]                                a[i]  a[i+2] a[i+1] 
*/                                                                 