#include<bits/stdc++.h>
using namespace std;
class SoPhuc{
    private :
  int a,b;
  static int So_Luong1,So_Luong2;
    public :
    //Nhap gia tri
      void getValue();
      void Display();
      friend SoPhuc operator+(SoPhuc &So_one,SoPhuc &So_true){
        SoPhuc So_tong;
        So_tong.a=So_one.a+So_true.a;
        So_tong.b=So_one.b+So_true.b;
        return So_tong;
      }
      friend SoPhuc operator-(SoPhuc &So_one,SoPhuc &So_true){
        SoPhuc So_tong;
        So_tong.a=So_one.a-So_true.a;
        So_tong.b=So_one.b-So_true.b;
        return So_tong;
      }
};
int SoPhuc::So_Luong1=1;
int SoPhuc::So_Luong2=1;

void  SoPhuc::getValue(){
    cout <<"\nNhap so phuc thu "<<So_Luong1<<":"<<endl;
    cout<< "\nNhap phan thuc :";
    cin>>a;
    cout<<"\nNhap phan ao :";
    cin>>b;
    So_Luong1++;
}
void SoPhuc ::Display(){
    cout <<"\nSo phuc thu "<<So_Luong2<<":"<<endl;
    cout <<"\n"<<a<<"+"<<b<<"i"<<endl;
    So_Luong2++;
}
int main(){
   SoPhuc obj1, obj2, result;
   //Nhập hai số phức 
   obj1.getValue();
   obj2.getValue();
   //In thông tin hai số phức
   obj1.Display();
   obj2.Display();
   // Tính tông hai so phuc
   result=obj1+obj2;
   result.Display();
   return 0;
}