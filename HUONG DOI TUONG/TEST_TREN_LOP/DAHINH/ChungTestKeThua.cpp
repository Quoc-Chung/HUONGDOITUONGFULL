#include<bits/stdc++.h>
using namespace std;
class A{
    public :
    virtual void Xuat(){
         cout<<"\nAi keu toi day. Co A day." <<endl;
       }

    virtual void TinhToan () =0 ;// Phương thức thuần ảo 
};
class B : public A{
    public :
       void Xuat(){
         cout<<"\nAi keu toi day. Co B day." <<endl;
       }
       void TinhToan(){
        cout<<"\nDa tinh xong "<<endl;
       }
};

class C : public A{
    public :
       void Xuat(){
         cout<<"\nAi keu toi day. Co C day." <<endl;
       }
       void TinhToan(){
        cout<<"\n co tinh xong dau C "<<endl;
       }
};
int main(){
    /* Dùng lớp cha khởi tạo đối tượng lớp con */
    /*Câu lệnh A *x = new A; tạo một con trỏ x kiểu A và cấp phát bộ nhớ để tạo một đối tượng thuộc lớp A.- */
    A *x = new C;
    x->Xuat();
    x->TinhToan();
    /* Nó chỉ hiện ra : "Ai keu toi day. Co A day. "*/

    /*Câu lệnh A *x1 = new B; tạo một đối tượng của lớp B và gán nó cho con trỏ x1 kiểu A.*/
    A * x1 = new B;
    x1->Xuat();
}