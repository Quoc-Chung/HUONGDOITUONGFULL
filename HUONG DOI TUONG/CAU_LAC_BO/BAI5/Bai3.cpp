// Xây dựng lớp DT (Đa thức), trong đó:
//  Các thuộc tính
// int n; // là bậc của đa thức
// float *a; // là con trỏ xác định vùng bộ nhớ chứa các hệ số 
//  Phương thức nhap() để nhập các hệ số của đa thức
//  Phương thức xuat() để in các hệ số của đa thức ra màn hình
//  Phương thức gia_tri(t) để tính giá trị của đa thức tại x = t.
#include<bits/stdc++.h>
using namespace std;
class DT{
    protected :
      int Bac;
      float *hs;
    public :
      DT(){
        Bac =0;
        hs=new float[Bac];
        for(int i=0;i<Bac;i++){
            hs[i]=0;
        }
      } 
      DT(int Bac) {
        this->Bac = Bac;
        this->hs = new float[Bac];
   }
        ~DT() {
            delete[] hs; 
        }
    void nhap(){
        cout<<"\nNhap so bac :";
        cin >> Bac;
        hs = new float [Bac];
        if(hs == NULL){
            cout<<"\nKhong cap phat duoc";
            exit(0);
        }
        for(int i=0;i<=Bac;i++){
          cout<<"\nNhap hs["<<i<<"]:";
          cin >>hs[i];
        }
    }
    void xuat(){
        if(Bac==1){
            cout <<hs[0]<<" + ";
            cout <<hs[1]<<" * x";
        }
        else{
            cout<<hs[0]<<" + ";
            cout<<hs[1]<<" * x + ";
            for(int i =2;i<Bac;i++){
                cout <<hs[i]<<" * x^"<<i<<" + ";
            }
            cout <<hs[Bac]<<" * x^" <<Bac;
        }
    } 
    float giatri(float t){
        float Value =0;
        for (int i=0;i<Bac;i++){
           Value +=hs[i] *pow(t,i); 
        }
        return Value;
    }
};
int main(){
   DT P,Q;
   cout<<"\nNhap da thuc P :";
   P.nhap();
   cout<<"\nNhap da thuc Q :";
   Q.nhap();
   cout<<"\nDa thuc P la:";P.xuat();
   cout<<"\nDa thuc Q la:";Q.xuat();
   float t;
   cout<<"\nNhap gia tri t :";
   cin >> t;
   cout<<"\nGia tri cuoi cung la :"<<P.giatri(t)<<endl;
   return 0;
}