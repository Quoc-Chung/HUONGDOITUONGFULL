#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class PS{
  private :
    int TuSo;
    int MauSo;
  public :
    //Hàm tạo không đối số
     PS() : TuSo(0), MauSo(1) {}
    //Ham tao co hai doi so
    PS(int TuSo,int MauSo){
        this->TuSo=TuSo;
        this->MauSo=MauSo;
    }
    //Ham nhap mot phan so
    void Nhap(){
        cout <<"\nNhap Tu So :";
        cin>>TuSo;
        cout<<"\nNhap Mau So :";
        cin>>MauSo;
    }
    // Ham nhan hai phan so 
   friend PS operator*(PS& p1, PS& p2) {
    PS p3;
    p3.TuSo = p1.TuSo * p2.TuSo;
    p3.MauSo = p1.MauSo * p2.MauSo;
    int gcdVal = gcd(p3.TuSo, p3.MauSo); // Tính ước chung lớn nhất
    p3.TuSo /= gcdVal; // Chia tử số cho ước chung lớn nhất
    p3.MauSo /= gcdVal; // Chia mẫu số cho ước chung lớn nhất
    return p3;
    }
    friend ostream& operator <<(ostream &os , PS p){
        os<<p.TuSo<<"/"<<p.MauSo;
        return os;	
   }
};
int main(){
    PS p1(4,8),p2(1,2);
    PS p3=p1 * p2;
    cout<<p1<<" * "<<p2<<" = " <<p3;
    return 0;
}