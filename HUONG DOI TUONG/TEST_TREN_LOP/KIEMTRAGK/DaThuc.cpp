#include<bits/stdc++.h>
using namespace std;
class DaThuc{
    private :
      int bac;
      float *heso;
    public:
    /* - Hàm tạo không đối - */
      DaThuc(){
        bac=0;
        heso = new float[bac];
        for(int i=0;i<=bac;i++){
            heso[i]=0;
        }
      }
    /* - Hàm hủy - */
      ~DaThuc(){
        delete []heso;
      }
    /* Nhap da thuc*/
    void NhapDaThuc(){
        cout<<"\nNhap so bac :";
        cin >> bac;
        heso = new float [bac];
        if(heso == NULL){
            cout<<"\nKhong cap phat duoc";
            exit(0);
        }
        for(int i=0;i<=bac;i++){
          cout<<"\nNhap hs["<<i<<"]:";
          cin >>heso[i];
        }
    }
    /* - Phương thức toán tử xuất - */
    friend ostream& operator<<(ostream& os, DaThuc &dt){
        os<<"\nDa thuc do la :"<<endl;
       if(dt.bac==1){
            os <<dt.heso[0]<<" + ";
            os <<dt.heso[1]<<" * x";
        }
        else{
            cout<<dt.heso[0]<<" + ";
            cout<<dt.heso[1]<<" * x + ";
            for(int i =2;i<dt.bac;i++){
                cout <<dt.heso[i]<<" * x^"<<i<<" + ";
            }
            cout <<dt.heso[dt.bac]<<" * x^" <<dt.bac;
        }
        return os;
    }

      float TinhGiaTri(float x) {
          float GiaTri = 0;
          for (int i = 0; i <= bac; i++) {
              GiaTri += heso[i] * pow(x, i);
          }
          return GiaTri;
    }
};
int main(){
    DaThuc Pn;
    cout <<"\nNhap da thuc:";
    Pn.NhapDaThuc();
    cout << Pn<<endl;
     float d1,d2;
     cout << "\nNhap  d1 va d2:";
     cin >>  d1 >> d2;
    float giatri1= Pn.TinhGiaTri(d1);
    float giatri2 = Pn.TinhGiaTri(d2);
    float can = sqrt(giatri1 - giatri2);
    cout<<"\nGia tri cua can la :"<<fixed<<setprecision(2)<<can<<endl;
    return 0;
}