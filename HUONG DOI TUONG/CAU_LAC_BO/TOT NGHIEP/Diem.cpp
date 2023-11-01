#include<bits/stdc++.h>
using namespace std;
class Diem{
    private:
       float Hoanh;
       float Tung;
    public:
       Diem(): Hoanh(0), Tung(0) {}
       Diem(float Hoanh, float Tung): Hoanh(Hoanh), Tung(Tung) {}

       friend istream& operator>>(istream& is,Diem& d){
        cout <<"\nNhap hoanh do :";
        is >> d.Hoanh;
        cout<<"\nNhap tung do :";
        is >>d.Tung;
        return is;
       }
       friend ostream& operator<<(ostream& os,Diem& d){
        os<<"\n Diem : ("<<d.Hoanh<<" , "<<d.Tung<<")";
        return os;
       }
      Diem operator*(Diem& d2){
        Diem result;
        result.Hoanh = this->Hoanh * d2.Hoanh;
        result.Tung = this->Tung * d2.Tung;
        return result;
       }

       void Khoang_Cach(Diem d2){
        float KhoangCach = sqrt(pow(d2.Hoanh - (*this).Hoanh, 2 )  +pow ((*this).Tung - d2.Tung,2));
        cout<<"\nKhoang cach giua hai diem :"<<KhoangCach<<endl;
       }

      bool operator==( Diem& d2){
         if((*this).Hoanh == d2.Hoanh && (*this).Tung == d2.Tung){
            return true;
         }
         return false;
      }
};
int main(){
   Diem d1,d2;
   cout <<"\nNhap hai diem :"<<endl;
   cin >> d1 >>d2;

   cout <<"\nThong tin hai diem la :"<<endl;
   cout<<d1<<d2;

   d1.Khoang_Cach(d2);

   if(d1==d2){
      cout<<"\nHai diem trung nhau ."<<endl;
   }  
   else{
      cout<<"\nHai diem khong trung nhau"<<endl;
   }

   Diem d3 = d1*d2;
   cout<<"\nTich hai diem la :"<<endl;
   cout<<d3<<endl;

   system("pause");
   return 0;
}