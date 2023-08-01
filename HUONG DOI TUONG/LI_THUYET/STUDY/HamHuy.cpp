//  Hàm hủy (destructor)
// Hàm huỷ sẽ tự động được gọi trước khi giải phóng một đối tượng để giải phóng vùng nhớ 
// trước khi đối tượng được hủy bỏ. Hàm hủy có các đặc điểm sau:

// − Mỗi lớp chỉ có một hàm hủy.

// − Hàm hủy không có kiểu, không có giá trị trả về và không có đối số.

// − Tên hàm huỷ cùng tên với tên lớp và có một dấu ngã (~) ngay trước tên.
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
	void setRadius(float r){
		this->r = r;
	}
	float getRadius(){
		return r;
	}
	float calculateArea(){
		return 3.14 * r * r;
	}
	~Circle(){
		cout<<"Radius of circle has destroyed."<<endl;
	}
};
void main()
{
	Circle c1(3.5);
	cout<<"Area of Circle = "<<c1.calculateArea();
}

// Kết quả
// Area of Circle = 38.465
// Radius of circle has destroyed.