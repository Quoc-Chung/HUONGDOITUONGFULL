#include<bits/stdc++.h>
using namespace std;
class DaThuc{
  private:
    int Bac;
    float *hs;
  public:
    DaThuc(){
        Bac = 0;
        hs =NULL;
    }
    DaThuc(int n){
        Bac = n;
        for(int i=0;i<=Bac;i++){
            hs[i] = 0 ;
        }
    }
    void Nhap() {
    cout << "\nNhap bac: ";
    cin >> Bac;
    hs = new float[Bac + 1]; // Cấp phát bộ nhớ cho mảng
    for (int i = 0; i <= Bac; i++) {
        cin >> hs[i];
    }
   }
    friend ostream& operator<<(ostream& os, DaThuc &dt){
       if(dt.Bac==1){
            os <<dt.hs[0]<<" + ";
            os <<dt.hs[1]<<" * x";
        }
        else{
            os<<dt.hs[0]<<" + ";
            os<<dt.hs[1]<<" * x + ";
            for(int i =2;i<dt.Bac;i++){
                os <<dt.hs[i]<<" * x^"<<i<<" + ";
            }
            os <<dt.hs[dt.Bac]<<" * x^" <<dt.Bac;
        }
        return os;
    }

      DaThuc operator+(DaThuc &b){
        DaThuc Tong;
        Tong.Bac=max(Bac,b.Bac);
        Tong.hs = new float [Tong.Bac];
        for (int i=0;i<=Tong.Bac;i++){
            float num1 = (i <= Bac) ? hs[i] : 0;
            float num2 = (i <= b.Bac) ? b.hs[i] : 0;
            Tong.hs[i] = num1 + num2;
        }
        return Tong;
      }

     ~DaThuc(){
        delete []hs;
      }
};
int main(){
   DaThuc dt1,dt2;
   cout <<"\nNhap da thuc thu nhat :"<<endl;
   dt1.Nhap();

   cout <<"\nNhap  da thuc thu hai :"<<endl;
   dt2.Nhap();
   cout<<"\nDa thuc thu nhat la :"<<endl;
   cout <<dt1<<endl;

   cout <<"\nDa thuc thu hai la :"<<endl;
   cout<<dt2<<endl;

   DaThuc tmp = dt1 + dt2;

   cout <<"\nDa thuc tong la:"<<endl;
   cout <<tmp<<endl;
   return 0;
}