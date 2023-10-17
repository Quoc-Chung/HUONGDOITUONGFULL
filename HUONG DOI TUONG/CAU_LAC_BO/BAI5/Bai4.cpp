// Xây dựng lớp DT (Đa thức)
//  Dữ liệu: n, *a
//  Các phương thức toán tử: >>, <<, =
//  Phương thức gia_tri(t) để tính giá trị đa thức tại x = t
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
   friend istream& operator>> (istream& is , DT& dt){
        cout<<"\nNhap so bac :";
        is >>dt.Bac;
        dt.hs = new float [dt.Bac];
        if(dt.hs == NULL){
            cout<<"\nKhong cap phat duoc";
            exit(0);
        }
        for(int i=0;i<=dt.Bac;i++){
          cout<<"\nNhap hs["<<i<<"]:";
          is >>dt.hs[i];
        }
        return is;
    }
    friend ostream& operator<< (ostream& os , DT & dt){
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
      DT& operator=(const DT& dt) {
        if (this == &dt) {
            return *this; // Xử lý tự gán
        }
        // Giải phóng bộ nhớ cũ
        delete[] hs;
        // Sao chép dữ liệu từ đối tượng dt
        Bac= dt.Bac;
        hs = new float[Bac + 1];
        for (int i = 0; i<=Bac;i++) {
            hs[i] = dt.hs[i];
        }
        return *this;
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
   cin>>P;
   cout<<"\nNhap da thuc Q :";
   cin>>Q;
   cout<<"\nDa thuc P la:"<<P;
   cout<<"\nDa thuc Q la:"<<Q;
   // Gán 
   P =  Q;  
   cout<<"\nBieu thuc P sau khi gan voi Q :"<<P;
   float t;
   cout<<"\nNhap gia tri t :";
   cin >> t;
   cout<<"\nGia tri cuoi cung la :"<<P.giatri(t)<<endl;
   return 0;
}