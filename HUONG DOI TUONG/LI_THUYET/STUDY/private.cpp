#include <iostream>
using namespace std;
// Chúng ta không thể truy cập vào các thuộc  tính private
class Room{
private:
	int capacity;
public:
	double length;
	double breadth;
	double height;
public:
	void setSizeRoom(double rLength, double rBreadth, double rHeight);

	double calculateArea(){
		return length * breadth;
	}
	double calculateVolume(){
		return length * breadth * height;
	}
	void setCapacity(int rCapacity){
		capacity = rCapacity;
	}
	int getCapacity(){
		return capacity;
	}
};
void Room :: setSizeRoom(double rLength, double rBreadth, double rHeight){
		length = rLength;
		breadth = rBreadth;
		height = rHeight;
}
void main()
{
	Room r;//khai báo đối tượng
	r.setSizeRoom(9.5, 7.3, 4.8);
	cout<<"Area of Room = "<<r.calculateArea();
	r.setCapacity(50);
	 //cout<<"\nCapacity of Room = "<<r.capacity;//Lỗi khi truy cập đến thuộc tính private  
    //--KHONG THE TRUY CAP DEN DOI TUONG PRIVATE THONG QUA LỚP MÀ CHỈ GIÁN TIẾP QUA HÀM TRẢ VỀ
	cout<<"\nCapacity of Room = "<<r.getCapacity();//Truy cập thuộc tính private gián tiếp qua hàm
	system("pause");
}