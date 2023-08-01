// Trong class các thuộc tính hay phương thức trong phạm vi private không thể truy cập được bên ngoài class, 
// vậy muốn truy xuất nó ở bên ngoài class ta phải làm như thế nào? 
#include <bits/stdc++.h>
using namespace std;
// Khai báo một class mang tên TamGiac 
class TamGiac{
    // Các thành phần a,b,c chỉ có thể được truy  cập khi  nó vẫn còn ở trong một lớp  
private:
	int a,b,c;
public:
	TamGiac()
	{
		a = 1;
		b = 1;
		c = 1;
	}
	TamGiac(int a, int b, int c): a(a), b(b), c(c) {};
    //khai báo một hàm constructor và đồng thời sử dụng danh sách khởi tạo 
    //để gán giá trị của các tham số a, b, và c
	
    //Khai báo hàm  bạn 
	friend bool kiemTraTG(TamGiac tg);
	
                                //một tham chiếu đến đối tượng kiểu ostream, đại diện cho luồng xuất dữ liệu
	friend ostream& operator << (ostream &os ,TamGiac &tg)
	{
		os<<"a = "<<tg.a<<" b = "<<tg.b<<" c = "<<tg.c<<endl;
		return os;
	}
};
	bool kiemTraTG(TamGiac tg)
	{
		if(tg.a>0 && tg.b>0 && tg.c>0 && (tg.a+tg.b>tg.c) && (tg.a+tg.c>tg.b) && (tg.b+tg.c>tg.a))
			return true;
		return false;
	}
	
int main()
{
	TamGiac t(3,4,5);
	cout<<kiemTraTG(t);
	cout<<t;
	return 0;
 }