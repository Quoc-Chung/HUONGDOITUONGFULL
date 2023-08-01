#include<bits/stdc++.h>
using namespace std;
// dùng  để tăng  số  thứ tự rất  hợp lí
class SinhVien1{
 private :
 // 4 Thuộc tính 
    string id,ten,ns;
    double gpa;
    static int dem1;
 public :
 // 2 Phuong thức 
    SinhVien1()= default;// contructor 
    SinhVien1 (string,string,string ,double);
    void Nhap();
    void In();
    int getDem1();
    void TangDem1();
};

int SinhVien1 ::dem1 =0;
// Hàm khởi tạo 
SinhVien1::SinhVien1(string ma,string name,string birth,double gpa){
    id=ma;
    ten=name;
    ns=birth;
    this->gpa=gpa;
}
void SinhVien1 :: Nhap(){
    cout <<"\nNhap id:";
    cin>>this->id;
    cin.ignore();
    cout <<"\nNhap Ten :"; 
    getline(cin,this->ten);
    cout <<"\nNhap Ngay Sinh :"; cin >>this->ns;
    cout <<"\nNhap diem :"; cin >> gpa;
}
void  SinhVien1::In(){
   cout <<id<<" "<<ten<<" "<<ns<<" "<<fixed<<setprecision(2)<<gpa<<endl;
}
// Khởi tạo  biến static cho lớp  
int SinhVien1 :: getDem1(){
    return dem1;
}
void SinhVien1 ::TangDem1(){
    dem1++;
}
int main(){
    // Biến static sẽ chịu ảnh hưởng của tất cả các đối tượng ,  này gọi là  biến toàn cục  
    SinhVien1 x;
    x.TangDem1(); //dem luc nay =1;
    x.TangDem1();// dem luc nay =2;

    SinhVien1 y;
    y.TangDem1();// dem luc nay =3;

    cout <<y.getDem1()<<endl;
    
}