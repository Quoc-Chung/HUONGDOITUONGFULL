#include<bits/stdc++.h>
using namespace std;
class Cat{
    private:
      string kikat;//Một lại chocolate 
    public:
      Cat():kikat(""){}
      Cat(string KiKat):kikat(KiKat){}
    
    /* - Hàm bạn của lớp Cat có the truy cap vào thuộc tính 
              private - */
    friend void Fox(Cat cat);
     
    /* - Lớp bạn của lớp Cat có thể truy cập vào thuộc tính 
              private - */
    friend class Foxx;
};
void Fox(Cat c ){
    /* - Không thể truy cập thuộc tính kikat khi o ben ngoai lop - */
    cout<<c.kikat<<endl;
}
class Foxx{
    public : 
      Foxx(){}
      void Display(Cat cat){
        /* - Chưa theer truy cập khi chưa là bạn - */
        cout <<cat.kikat<<endl;
      }
};
int main (){
    Cat c("Toi la sieu nhan .");
    Fox(c);

    /* - Khai báo hàm bạn - */
    Foxx cao;
    cao.Display(c);
    return 0;
    
}