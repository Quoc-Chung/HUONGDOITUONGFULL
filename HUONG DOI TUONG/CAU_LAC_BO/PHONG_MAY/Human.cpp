#include<bits/stdc++.h>
using namespace std;
class Human{
 private :
    string name;
    int age;
    float height;
  public :
    void Nhap(){
      cin.ignore();
    cout << "Nhap vao ten: ";
    getline(cin ,name);
    cout << "Nhap vao tuoi: ";
    cin >> age;
    cout << "Nhap vao chieu cao: ";
    cin >> height;
  }
  void Xuat(){
    cout << name << " " << age << " " << height << endl;
  }
  void  eat(){
    cout <<"\nNguoi dang an"<<endl;
  }
  void Talk(){
    cout<<"\nNguoi Dang  noi chuyen";
  }
  void  NhapNhieuHuman(int n){
    vector<Human> human;
    for (int i=0;i<n;i++){
      Human h;
      h.Nhap();
     human.push_back(h);
    }
    for (auto x : human){
      x.Xuat();
    }
  }
};
int main(){
    Human h;
    int  n;
    cout<<"\nNhap vao n:";
    cin >>n;
    // Nhap nhieu  gia tri
    h.NhapNhieuHuman(n);
    return 0;
}