#include<bits/stdc++.h>
using namespace std;
class DaThuc{
  private :
    int bac;
    vector<int> HeSo;;
  public :
    DaThuc(int bac);
    void Nhap();
    void In();
    void TinhGiaTri(int x);
};
DaThuc::DaThuc(int bac){
    this->bac = bac;
    // cấp phát bộ nhớ và khởi tạo các phần tử vector HeSo  = 0.
    HeSo.resize(bac + 1, 0);
}
void DaThuc:: Nhap(){
    cout<<"\nNhap he so cua da thuc :\n";
    for(int i=0;i<=bac;i++){
        cout<<"\nNhap he so "<<i<<":";
        cin>>HeSo[i];
    }
}
void DaThuc::In () {
    for (int i = 0; i <= bac; i++) {
        cout << HeSo[i]<< "x^" <<i;
        if(i<bac){
            cout<<" + ";
        }
    }
    cout<<endl;
}
void DaThuc ::TinhGiaTri(int x){
    int Tong =0;
   for (int i=0;i<=bac;i++){
     Tong +=HeSo[i]* pow(x,i);
}
  cout<<"\nTong la : "<<Tong;
}
int main(){
    int bac;
    cout<<"\nNhap bac da thuc:";
    cin >>bac;
    DaThuc DT(bac);
    DT.Nhap();
    int d;
    cout<<"\nNhap  gia tri d:";
    cin >>d;
    DT.In();
    DT.TinhGiaTri(d);
    return 0;
}