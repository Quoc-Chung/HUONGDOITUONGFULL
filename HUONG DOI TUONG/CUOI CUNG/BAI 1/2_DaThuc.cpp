
#include<bits/stdc++.h>
using namespace std;
class DaThuc{
    private:
      int Bac;
      float *hs;
    public :
    // Ham khoi tao khong co tham so 
      DaThuc(){
        Bac =0;
        hs=new float[Bac];
        for(int i=0;i<=Bac;i++){
            hs[i]=0;
        }
        // hs = NULL cung du?c
      }
    //Ham khoi tao co tham so 
      DaThuc(int Bac) {
        this->Bac = Bac;
        this->hs = new float[Bac+1];
   }
    // H�m huy
        ~DaThuc() {
            delete[] hs; 
        }   
	friend istream& operator>> (istream& is,DaThuc &dt){
		do {
            cout << "\nNhap so bac :";
            is >> dt.Bac;
            if (dt.Bac < 0) {
                cout << "\nVui long nhap lai.\n";
            }
       }while (dt.Bac < 0);
        dt.hs = new float [dt.Bac+1];
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
	
	friend ostream& operator<<(ostream& os,DaThuc &dt){
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
	
	
    void NhapDaThuc(){
        do {
            cout << "\nNhap so bac :";
            cin >> Bac;
            if (Bac < 0) {
                cout << "\nVui long nhap lai.\n";
            }
       }while (Bac < 0);
        hs = new float [Bac+1];
        if(hs == NULL){
            cout<<"\nKhong cap phat duoc";
            exit(0);
        }
        for(int i=0;i<=Bac;i++){
          cout<<"\nNhap hs["<<i<<"]:";
          cin >>hs[i];
        }
    }

    void XuatDaThuc(){
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

    DaThuc operator-(DaThuc &b){
        DaThuc Hieu;
        Hieu.Bac=max(Bac,b.Bac);
        Hieu.hs = new float [Hieu.Bac];
        for (int i=0;i<=Hieu.Bac;i++){
            float num1 = (i <= Bac) ? hs[i] : 0;
            float num2 = (i <= b.Bac) ? b.hs[i] : 0;
            Hieu.hs[i] = num1 - num2;
        }
        return Hieu;
    }

     DaThuc operator*(DaThuc &b){
        DaThuc Tich;
        Tich.Bac=max(Bac,b.Bac);
        Tich.hs = new float [Tich.Bac];
        for (int i=0;i<=Tich.Bac;i++){
            float num1 = (i <= Bac) ? hs[i] : 0;
            float num2 = (i <= b.Bac) ? b.hs[i] : 0;
            Tich.hs[i] = num1 * num2;
        }
        return Tich;
    }

     DaThuc operator/(DaThuc &b){
        DaThuc Chia;
        Chia.Bac=max(Bac,b.Bac);
        Chia.hs = new float [Chia.Bac];
        for (int i=0;i<=Chia.Bac;i++){
            float num1 = (i <= Bac) ? hs[i] : 0;
            float num2 = (i <= b.Bac) ? b.hs[i] : 0;
            Chia.hs[i] = num1 * num2;
        }
        return Chia;
    }

    float TinhGiaTri(float x0){
        float Value =0.0;
        for (int i=0;i<=Bac;i++){
           Value +=hs[i] *pow(x0,i); 
        }
        return Value;
    }
};


int main(){
   DaThuc P,Q;
   cout<<"\nNhap da thuc P :";
   cin>> P;
   cout<<"\nNhap da thuc Q :";
   cin>> Q;

   cout<<"\nDa thuc P la:";P.XuatDaThuc();
   cout<<"\nDa thuc Q la:";cout<<Q;
   cout<<"\nDa thuc P+Q la :\n"; (P+Q).XuatDaThuc();
   cout<<"\nDa thuc P-Q la :\n"; (P-Q).XuatDaThuc();

   float d1,d2;
   cout<<"\nNhap d1 va d2:";
   cin >>d1>>d2;
   float S = 1 / (P.TinhGiaTri(d1) - Q.TinhGiaTri(d2));
   cout<<"\nGia tri cuoi cung la :"<<S <<endl;
   return 0;
}
