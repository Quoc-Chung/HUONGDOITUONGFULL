#include <iostream>
using namespace std;
class AClass{
private:
	static int x;//Thành phần dữ liệu tĩnh
	int y;
public:
	AClass(){
		y=0;
		x = x + 100;
	}
	static void getx(){//Hàm thành phần tĩnh
		cout<<"Value of x = "<<x<<endl;
	}
};
int AClass::x = 0;//gán giá trị cho dữ liệu tĩnh x
void main()
{
	AClass a;
	AClass::getx();//Gọi hàm thành phần tĩnh
	AClass b;
	AClass::getx();//Gọi hàm thành phần tĩnh
	system("pause");
}  //Tên_lớp::Tên_hàm_thành_phần_tĩnh(Các_tham_số);