#include<iostream>
using namespace std;
class Person {
    // Lớp Person có 4 thuôc tính  truyền vào 
private:
	int id;
	string name;
	int age;
	string address;
public:
// Trả về giá trị các thuộc  tính 
	int getId() {
		return id;
	}
	string getName() {
		return name;
	}
    int getAge() {
		return age;
	}
    string getAddress() {
		return address;
	}
// Gán giá trị  cho  các thuộc tính 
    void setId(int id) {
		this->id = id;
	}
	void setName(string name) {
		this->name = name;
	}
	void setAge(int age) {
		this->age = age;
	}
	
	void setAddress(string address) {
		this->address = address;
	}
};

int main() {
    // Khởi tạo đối tượng p
	Person p;
    //Gán giá trị cho các thuộc tính 
	p.setId(1001);
	p.setName("Quynh");
	p.setAge(24);
	p.setAddress("Ha Noi");
    // Truy cập các đối tượng p
	cout << "Id: " << p.getId() << endl;
	cout << "Name: " << p.getName() << endl;
	cout << "Age: " << p.getAge() << endl;
	cout << "Address: " << p.getAddress() << endl;
	return 0;
}