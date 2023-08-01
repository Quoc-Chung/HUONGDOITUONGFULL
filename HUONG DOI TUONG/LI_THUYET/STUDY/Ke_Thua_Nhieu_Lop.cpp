#include <iostream>
using namespace std;
class base1{
private:
	int x1;
protected:
	float y1;
public:
	void nhap1(){
		cout<<"\nNhap gia tri x1:";
		cin>>x1;
	}
};
class base2{
private:
	int x2;
public:
	void nhap2(){
		cout<<"\nNhap gia tri x2:";
		cin>>x2;
	}
};
class derived : public base1, public base2{
private:
	int x;
public:
	void nhap(){
		cout<<"\nNhap gia tri x:";
		cin>>x;
	}
};
// Vừa kế thừa nhiều lớp
int main(){
	derived obj;
	obj.nhap1();obj.base1::nhap1();
	obj.nhap2();obj.base2::nhap2();
	obj.nhap();

	system("pause");
}
/*
-  Lớp dẫn xuất derived kế thừa public từ lớp base1 và base2 :
– x1, x2 không thể truy cập trong lớp derived.
– x là thuộc tính private của lớp derived.
– y1 là thuộc tính protected của lớp derived.
– nhap1(), nhap2(), nhap() là các hàm public của lớp derived.
*/