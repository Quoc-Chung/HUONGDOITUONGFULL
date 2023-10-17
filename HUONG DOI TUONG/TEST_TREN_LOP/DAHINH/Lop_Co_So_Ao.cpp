#include<bits/stdc++.h>
using namespace std;
class A {
    public: 
       int a;
};

/* - Lớp B kế thừa lại từ lớp cha (A) - */
class B: public A {
    public: 
       int b;
};

/* - Lớp C kế thừa lại từ lớp cha (A) - */
class C: public A {
    public: 
       int c;
};

/* - Lớp D kế thừa lại từ lớp cha ( B và C ) - */
class D: public B, public C{
    public: 
       int d;
};

int main(){
    D h;
    /* - h có thể truy cập đến các thuôc tính lớp D , của lớp kế thừa B ,C - */
    h.d= 4;
    cout<<h.d<<endl; // 4
    h.c= 5;
    cout<<h.c<<endl; // 5
    h.b= 6;
    cout<<h.b<<endl; // 6

    
    /* - h còn có thể dựa vào lớp kế thừa B để truy cập đến thành phần lớp cha  (A) - */
    /* - giải quyết sự mơ hồ (ambiguity) trong việc truy cập đến biến a từ lớp cha A khi
     lớp D kế thừa cả lớp B và C, và cả hai lớp này đều có một thành viên tên là a. - */
    h.B::a = 7;
    cout<<h.B::a<<endl; // 7
  //  cout<<h.a; // lỗi!
     /* - Vì ở đây tồn tại sự mơ hồ :
    Trình biên dịch không thể biết được thuộc tính „a‟ của D sẽ kế thừa thông qua B hay
     thông qua C */

   /* - Các fix lỗi : Thêm từ khóa virtual khi khai báo B và C  - */
}