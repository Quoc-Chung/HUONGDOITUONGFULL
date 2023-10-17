// Xây dựng lớp Dathuc(đa thức ):
// - Thuộc tính: bac(bậc của đa thức), hs(các hệ số của đa thức)
// - Phương thức:
// o Hàm tạo không tham số, hàm tạo có tham số, hàm huỷ, nhập đa thức, in đa 
// thức tính đa thức tại x0, hàm toán tử cộng 2 đa thức, hàm bạn trừ 2 đa thức
// 2. Viết hàm main() thực hiện các công việc:
// - Nhập một đa thức P,Q
// - In đa thức đó P,Q, P+Q, P-Q
// - Nhập vào d1 và d2 rồi tính biểu thức S=1/(P(d1)-Q(d2))
#include<bits/stdc++.h>
using namespace std;
class DaThuc{
    protected :
      int Bac;
      float *hs;
    public :
    // Ham khoi tao khong co tham so 
      DaThuc(){
        Bac =0;
        hs=new float[Bac];
        for(int i=0;i<Bac;i++){
            hs[i]=0;
        }
        // hs = NULL cũng được
      }
    //Ham khoi tao co tham so 
      DaThuc(int Bac) {
        this->Bac = Bac;
        this->hs = new float[Bac];
   }
    // Hàm hủy
        ~DaThuc() {
            delete[] hs; 
        }
    void NhapDaThuc(){
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
    float TinhGiaTri(float x0){
        float Value =0;
        for (int i=0;i<Bac;i++){
           Value +=hs[i] *pow(x0,i); 
        }
        return Value;
    }
};
int main(){
   DaThuc P,Q;
   cout<<"\nNhap da thuc P :";
   P.NhapDaThuc();
   cout<<"\nNhap da thuc Q :";
   Q.NhapDaThuc();

   cout<<"\nDa thuc P la:";P.XuatDaThuc();
   cout<<"\nDa thuc Q la:";Q.XuatDaThuc();
   cout<<"\nDa thuc P+Q la :\n"; (P+Q).XuatDaThuc();
   cout<<"\nDa thuc P-Q la :\n"; (P-Q).XuatDaThuc();

   float d1,d2;
   cout<<"\nNhap d1 va d2:";
   cin >>d1>>d2;
   float S = 1 / (P.TinhGiaTri(d1) - Q.TinhGiaTri(d2));
   cout<<"\nGia tri cuoi cung la :"<<S <<endl;
   return 0;
}