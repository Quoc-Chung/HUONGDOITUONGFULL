#include<bits/stdc++.h>
using namespace std;
// Bạn  để thấy  rằng  bán  kính r với đối số  nó đều đặt là r ==>  gây  rỗi loạn nhập nhằng  
class Circle{
private:
	float r;//Bán kính, thành phần dữ liệu của từng đối tượng
public:
	void setRadius(float r)
	{
		r = r;//Nhập nhằng 
	}
	float getRadius(){
		return r;
	}
};
// Cho con trỏ this trỏ đến đối tượng trong lớp để phân biệt tránh sự nhập nhằng 
class Circle{
private:
	float r;//Bán kính, thành phần dữ liệu của từng đối tượng
public:
	void setRadius(float r)
	{
		this->r = r;
	}
	float getRadius(){
		return r;
	}
};
int main(){

}