#include<bits/stdc++.h>
using namespace std;
class Room {
public:
    double length;
    double breadth;
    double height;

public:
    double calculateArea();
    double calculateVolume();
};

double Room::calculateArea() {
    return length * breadth;
}

double Room::calculateVolume() {
    return length * breadth * height;
}

class Student {
    //Chỉ truy cập được vào các đối tượng khi ở trong lớp
    private:
	string id;
	bool gender;
	float math;
	float literature;
public:
	void setID(string str_id){
		id = str_id;
	}
	string getID(){
		return id;
	}
};
int main(){
    //Khởi tạo mặc định 
    Room r;
    r.length=5.9;
    r.breadth=6.7;
    cout <<"\nDien tich la :"<<r.calculateArea()<<endl;

    Student s;
    

}