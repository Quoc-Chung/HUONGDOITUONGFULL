#include<bits/stdc++.h>
using namespace std;
bool NguyenTo(int n){
    if(n <2 ){
       return false;
    }
    else {
        for(int i=2;i<=sqrt(n);i++){
            if(n %i ==0){
                return false;
            }
        }
    }
    return true;
}
class DaySo{
  private:
     int n;
     int *a;
  public:
     DaySo():n(0),a(NULL){}
     friend istream& operator>>(istream& is,DaySo &ds){
        cout<<"\nNhap n:";
        is>>ds.n;
        ds.a = new int[ds.n];
        cout<<"\nNhap day so :";
        for(int i=0;i<ds.n;i++){
            is>> ds.a[i];
        }

        return is;
     }
     friend ostream& operator<<(ostream& os,DaySo &ds){
        os<<"\nDay so la :"<<endl;
        for(int i=0;i<ds.n;i++){
            os<<ds.a[i]<<" ";
        }
        return os;
     }

     int TongDaySo (){
        int tong =0;
        for (int i=0;i<n;i++){
           tong += a[i];
        }
         return tong;
     }
     friend float TBC(DaySo &ds) {
        int dem = 0, Tong = 0;
        for (int i = 0; i < ds.n; i++) {
        if (NguyenTo(ds.a[i])) {
            Tong += ds.a[i];
            dem++;
        }
    }
    if(dem ==0){
        return 0;
    }
    else{
        return (float)Tong / dem;
    }  
}
};
int main (){
   DaySo X,Y;
   cout<<"\nNhap day so X :"<<endl;
   cin >> X ;
   cout <<"\nNhap day so Y :"<<endl;
   cin >> Y;

   cout<<"\nDay so nguyen X la :"<<endl;
   cout<<X;

   cout<<"\nDay so nguyen Y la :"<<endl;
   cout<<Y;
   float Tong = 1.0 / (X.TongDaySo() - Y.TongDaySo());
   cout<<"\nTong la :"<<Tong <<endl;


   float TBCX = TBC(X);
   float TBCY = TBC(Y);



   if( TBCX > TBCY){
    cout<<"\nĐay X co trung binh cong  lon hon "<<endl;
   }
   else if(TBCX == TBCY){
    cout<<"\nHai day co TBC bang nhau "<<endl;
   }
   else {
    cout<<"\nDay Y co trung binh cong lon hon "<<endl;
   }


}  