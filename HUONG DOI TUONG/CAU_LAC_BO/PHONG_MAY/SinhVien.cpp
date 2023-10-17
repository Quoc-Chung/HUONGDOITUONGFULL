#include<bits/stdc++.h>
using  namespace std;
class  SinhVien {
    private :
      string  HoTen  ;
      int  MaSinhVien;
      float ;
    public : 
      float get() const { return ; }

      void NhapSinhVien(){
        cout<<"Nhap ho ten sinh vien: ";
        cin.ignore();
        getline(cin,HoTen);
        cout<<"Nhap ma sinh vien: ";
        cin>>MaSinhVien;
        cout<<"Nhap : ";
        cin>>;
      }
      void XuatSinhVien(){
        cout<<"Ho ten sinh vien: "<<HoTen<<endl;
        cout<<"Ma sinh vien: "<<MaSinhVien<<endl;
        cout<<": "<<<<endl;
      } 

};
void SinhVienSapXep(SinhVien *sv,int n){
    for (int i=0;i<n;i++){
        for  (int  j=0;j < n; j++){
            if (sv[i].get() > sv[j].get()){
                SinhVien temp = sv[i];
                sv[i] = sv[j];
                sv[j] = temp;
            }
        }
    }
}
int main (){
  int n;
  cout <<"\nNhap so sinh vien:";
  cin >>n;
  SinhVien *sv =new SinhVien[n];
  if(sv==NULL){
    cout<<"Khong co du lieu";
    return 0;
  }
  for (int i=0;i<n;i++){
    sv[i].NhapSinhVien();
  }
  cout <<"\nXem danh sach sinh vien:";
  for (int i=0;i<n;i++){
    sv[i].XuatSinhVien();
  }
  SinhVienSapXep(sv,n);
  cout <<"\nXem danh sach sinh vien sau khi sap xep:";
  for (int i=0;i<n;i++){
    sv[i].XuatSinhVien();
  }

}