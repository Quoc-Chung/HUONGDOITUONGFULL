#include<bits/stdc++.h>
using namespace std;
class Vecto{
   private:
      int n;
      float *tp;
   public:
     Vecto(): n(0),tp(NULL){}
     friend istream& operator>> (istream& is,Vecto &vt){
        cout<<"\nNhap so chieu :";
        is>>vt.n;
        vt.tp = new float[vt.n];
        cout<<"\nNhap thanh phan:"<<endl;
        for(int i=0;i<vt.n;i++){
          is>>vt.tp[i];
        }
        return is;
     }
     void InVector(){
        cout<<"\nVector :( ";
        for(int i=0;i<n-1;i++){
            cout<<tp[i]<<" , ";
        }
        cout<<tp[n-1]<<" ) "<<endl;
     }
    float TichVoHuong(Vecto &vt2){
    float tich=0;
    for (int i=0;i<max(n,vt2.n) ;i++){
         float tmp1 = (i < n) ? tp[i] : 0;
         float tmp2 = (i < vt2.n) ? vt2.tp[i] : 0;
         tich+=tmp1 *tmp2; 
    }
    return tich ;
   }

     Vecto operator*(float sonhan){
         Vecto vt =*this;
         for(int i=0;i<vt.n;i++){
             vt.tp[i] *= sonhan;
         }
         return vt;
     }
};
int main(){
   Vecto vt1,vt2;
   cout<<"\nNhap vector thu nhat:";
   cin >> vt1;
   cout<<"\nNhap vector thu hai:";
   cin >> vt2;
   float x = vt1.TichVoHuong(vt2);
   cout<<"\nTich vo huong cua hai vector la :"<<x<<endl;
   return 0;
}

