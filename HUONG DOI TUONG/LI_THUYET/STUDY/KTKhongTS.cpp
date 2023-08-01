#include<bits/stdc++.h>
using namespace std;
class Circle{
private:
	float r;
public:
// Hàm khởi tạo không có tham số truyền vào 
// Tên_lớp (Tên_lớp &obj){
// 	/* Các câu lệnh dùng các thuộc tính của đối tượng obj để gán cho các thuộc tính của đối tượng mới*/
// }
	Circle(){
		r = 1.0;
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
// Nếu lớp không có hàm khởi tạo nào, 
// trình biên dịch sẽ cung cấp một hàm khởi tạo mặc định không đối số và không code trong nó.
int main()
{
	Circle c;//sử dụng hàm khởi tạo mặc định
	cout<<"Area of Circle = "<<c.calculateArea()<<endl;
	system("pause");
}