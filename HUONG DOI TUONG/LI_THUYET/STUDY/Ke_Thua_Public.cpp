#include <iostream>
using namespace std;
class A{
private: 
	int biena;
public :
    int bienTest;
public:
	void hama(){
		biena = 0;
		cout<<"Gia tri cua bien a = "<<biena<<endl;
	}
};
// Với public thì B có thể truy  cập  được  vào các  thành phần  publicc của  lớp cha As
class B: public A{
private:
	int bienb;
public:
    void Gan_Test(){
     bienTest=2;
    }
	void hamb(){
		bienb = 1;
		cout<<"Gia tri cua bien b = "<<bienb<<endl;
	}
};
int main(){
	B bobject;
	//truy cập các thành viên
	bobject.hama();
	bobject.hamb();
	system("pause");
}