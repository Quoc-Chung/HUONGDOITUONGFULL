//Bai  1 :
#include<bits/stdc++.h>
using namespace std;
int n;
class Diem{
  private :
    int hoanh;
    int tung;
  public :
   // Nạp  chồng toán tử nhập ístream
    friend istream& operator >> (istream& is, Diem& d) //nạp chồng toán tử nhập
    {
        cout << "Hoanh - Tung :";
        is >> d.hoanh>>d.tung;
        return is;
      }
   //Nạp  chồng toán tử xuất ostream
    friend ostream& operator << (ostream& os, Diem& d) // nạp chồng toán tử xuất
    {
        os << "("<<d.hoanh<<","<<d.tung<<")"<<endl;
        return os;
      }
    void Gap_Khuc(Diem *d,int n);
};
//Tinh do dai duong gap khuc lan luot di qua diem thu 2 ,...n ,1
void Diem ::Gap_Khuc(Diem *d,int n){
  float gap_khuc=0;
  for (int i=2;i<=n-1;i++){
    gap_khuc+= sqrt(pow(d[i+1].hoanh-d[i].hoanh ,2) +pow(d[i+1].tung -d[i].tung,2));
  }
  gap_khuc+=sqrt(pow(d[1].hoanh -d[n].hoanh ,2)+pow(d[1].tung-d[n].tung,2));
 cout <<"\nDo dai duong gap khuc  la:"<<gap_khuc<<endl;
}
int main(){
   cout <<"\nNhap n :";
   cin>>n;
   Diem *d=new Diem[n]; //Khoi tao  doi tuong
   for (int i=1;i<=n;i++){
     cin>>d[i];
   }
   cout <<"\nThong tin cua diem la :\n";
   for (int i=1;i<=n;i++){
    cout <<d[i]<<endl;
   }
   
   Diem *x;
   x->Gap_Khuc(d,n);
   return 0;
}