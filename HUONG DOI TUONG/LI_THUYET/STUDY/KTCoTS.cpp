#include<bits/stdc++.h>
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
};
void main()
{
      // Nếu trong lớp đã có ít nhất một hàm khởi tạo thì hàm khởi tạo mặc định do trình biên dịch cung cấp sẽ không còn nữa.
     // Khi đó, bạn phải sử dụng các hàm khởi tạo được định nghĩa trong lớp nếu không sẽ gây ra lỗi.
	//Circle c;//lỗi vì không có hàm khởi tạo mặc định
	Circle c1(3.5);//ok vì có hàm khởi tạo được định nghĩa
	system("pause");
}