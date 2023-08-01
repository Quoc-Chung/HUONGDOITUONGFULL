#include <iostream>
using namespace std;
class Circle{
private:
	float r;
public:
	//Hàm khởi tạo có tham số
	Circle(float r){
		this->r = r;
	}
    // Hàm đặt bán kính 
	void setRadius(float r){
		this->r = r;
	}
    // Hàm trả về bán kính 
	float getRadius(){
		return r;
	}
    // Hàm tính toán diện  tích
	float calculateArea(){
		return 3.14 * r * r;
	}
};
// Hàm setCircle() có cách truyền tham trị với đối tượng. 
// Thuộc tính r của đối tượng c1 không đổi sau khi ra khỏi hàm.
// đặt bán kính có phạm  vi private 
void setCircle(Circle c){//truyền tham trị
	c.setRadius(100);
}
void main()
{
	Circle c1(3.5);
	setCircle(c1);//gọi hàm truyền tham trị
	cout<<"Radius of Cirle c1 = "<<c1.getRadius();
	cout<<"\nArea of Circle = "<<c1.calculateArea();
	system("pause");
}