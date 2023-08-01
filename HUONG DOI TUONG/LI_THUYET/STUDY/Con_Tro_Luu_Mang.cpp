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
void main()
{
	Circle a[5];//Khai báo mảng các đối tượng
	float r=0;
	Circle* pc = new Circle; //Khai báo và sử dụng đối tượng kiểu con trỏ
	pc = a; //Con trỏ pc tham chiếu đến mảng a
    //Thực chất a cũng là con trỏ neenkhoong có  &a
	for(int i=0;i<5;i++){
		cout<<"Input radius of Circle "<<i<<": ";
		cin>>r;
		(pc+i)->setRadius(r);
		cout<<"Area of Circle "<<i<<" = "<<(pc+i)->calculateArea()<<endl;
	}
	system("pause");
}