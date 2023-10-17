#include<bits/stdc++.h>
using namespace std;
class {
    private :
      float Hoanh;
      float Tung;
    public  :
      void Nhap(){
        cout<<"\nNhap Hoanh:";  cin>>Hoanh;
        cout<<"\nNhap Tung :";   cin>>Tung;
      }
      void In(){
        cout<< "("<<Hoanh<<" , "<<Tung<<")"<<endl;
      }
      void DoDai( d1, d2){
         float dodai =0;
         dodai =sqrt(pow(d2.Hoanh-d1.Hoanh,2) +pow(d2.Tung-d1.Tung,2));
         cout<<"\nDo dai :"<<dodai<<endl;
      }
};
int main(){
     d1,d2;
    cout<<"\nNhap  d1:";
    d1.Nhap();  
    cout<<"\nNhap  d2:";
    d2.Nhap();
    cout<<"\n thu nhat la:";
    d1.In();
    cout<<"\n thu hai la :";
    d2.In();
    d1.DoDai(d1,d2);
    return 0;
}