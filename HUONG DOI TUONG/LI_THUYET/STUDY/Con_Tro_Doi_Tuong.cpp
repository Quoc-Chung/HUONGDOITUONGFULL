#include <iostream>
using namespace std;
class Circle{
private:
	float r;
public:
	//Hàm khởi tạo mặc định
	Circle(){
		this->r = 1.0;
	}
	//Hàm khởi tạo có tham số
	Circle(float r){
		this->r = r;
	}
	void setRadius(float r){
		this->r = r;
	}
	float getRadius(){
		return r;
	}
	float calculateArea(){
		return 3.14 * r * r;
	}
};
/*
Tên_lớp* tên_biến_con_trỏ = new <hàm_khởi_tạo_của_lớp>;
Để truy xuất các thành phần của lớp từ con trỏ đối tượng trong C++, 
ta dùng toán tử “->” như sau:
                  Tên_con_trỏ -> Tên_thuộc_tính;
             Tên_con_trỏ -> Tên_hàm(giá_trị_các_khai_báo_tham_số);
*/
int main()
{
	Circle* c1 = new Circle();//sử dụng hàm khởi tạo mặc định
	Circle* c2 = new Circle(3.5);//sử dụng hàm khởi tạo có tham số
	   c1->setRadius(99);
  //  (*c1).setRadius(99);
	cout<<"Area of Circle c1 = "<<c1->calculateArea();
	cout<<"\nArea of Circle c2 = "<<c2->calculateArea()<<endl;
	system("pause");
}