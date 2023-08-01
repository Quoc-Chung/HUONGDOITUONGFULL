#include <iostream>
using namespace std;
class AClass{
private:
//x là của chung BỊ CHI PHỐI BỞI NHIỀU  lớp  đối tượng 
	static int x;//Thành phần dữ liệu tĩnh
	int y;
public:
	AClass(){
		y=0;
	}

	void getxy(){
		x = x + 100;
		cout<<"Value of x = "<<x<<endl;
		y = y + 10;
		cout<<"Value of y = "<<y<<endl;
	}
};

//CÁch khởi tạo biến tĩnh 
int AClass::x = 0;//gán giá trị cho dữ liệu tĩnh x
int main()
{
	AClass a;
	cout<<"Get x and y of a:"<<endl;
	a.getxy();
	AClass b;
	cout<<"Get x and y of b:"<<endl;
	b.getxy();
	system("pause");
}
/*
biến x thuộc về lớp Aclass, bất kỳ đối tượng nào thuộc lớp 
Aclass đều có thể dùng x và làm x thay đổi (x tăng lên 100 rồi 200). 
Biến y thì được cấp phát bộ nhớ riêng cho từng đối tượng,
biến y của a không liên quan gì biến y của b.
*/