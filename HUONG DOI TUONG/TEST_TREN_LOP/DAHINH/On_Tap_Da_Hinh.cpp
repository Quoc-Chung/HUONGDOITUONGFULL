#include<bits/stdc++.h>
using namespace std;
class ConNguoi{
    public :
       ConNguoi(){}
      virtual void Show(){
           cout<<"\nCon Nguoi lop cha.";
       }
};

class NhanVien : public ConNguoi{
    public :
       NhanVien(){}
       void Show(){
        cout<<"\nCon nguoi lop nhan vien."<<endl;
       }
};

class HocSinh : public ConNguoi{
     public :
        HocSinh(){}
        void Show(){
            cout<<"\nCon nguoi lop hoc sinh.";
        } 
};

int main(){
    // ConNguoi *c=new HocSinh();
    // c->Show(); // Gọi ra hàm show của lớp ConNguoi nếu không có từ khóa  virtual trong phương thức showw của Lớp ConNguoi
    // c =new NhanVien();
    // c->Show();
    //    ConNguoi *c;
    //    c->Show();


    // ConNguoi *c = new NhanVien();
    // c->Show(); // Gọi ra hàm Show của lớp nhân viên vì nó đã hỗ trợ ghi đè.
    

    NhanVien nv;
    nv.Show();


    // ConNguoi nguoi;       // Đối tượng thuộc lớp cơ sở ConNguoi
    // NhanVien nhanVien;   // Đối tượng thuộc lớp dẫn xuất NhanVien
    // HocSinh hocSinh;     // Đối tượng thuộc lớp dẫn xuất HocSinh
    // c = &nguoi;   // Con trỏ c trỏ đến đối tượng nguoi (lớp ConNguoi)
    // c->Show();    // Gọi hàm Show() của lớp ConNguoi
    // c = &nhanVien; // Con trỏ c trỏ đến đối tượng nhanVien (lớp NhanVien)
    // c->Show();     // Gọi hàm Show() của lớp NhanVien
    // c = &hocSinh;  // Con trỏ c trỏ đến đối tượng hocSinh (lớp HocSinh)
    // c->Show();     // Gọi hàm Show() của lớp HocSinh
   return 0;

}
/*

- Hiện tại không có virtual thì nó sẽ không hộ trợ việc ghi đè ( tức là không cho phép hỗ trợ việc ghi đè lớp cha ): 
Con Nguoi lop cha.
Con Nguoi lop cha.
--> Nó  luôn luôn chỉ trỏ đến hàm Show của lớp cha .
- 

*/