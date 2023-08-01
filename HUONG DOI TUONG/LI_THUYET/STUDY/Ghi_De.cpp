#include <iostream>
using namespace std;
class A{
	// Thuộc tính  của  lớp cha 
private:
	int biena;
public:
    //Các phương thức của lớp cha 
	void hama(){
		biena = 0;
		cout<<"Gia tri cua bien a = "<<biena<<endl;
	}

	void nhap(){
		cout << "\nNhap gia tri cua bien a = "; cin >> biena;
	}

	void hienthi(){
		cout<<"\nGia tri cua bien a = "<<biena;
	}
};
class B: public A{
private:
    // Thuộc tính của lớp con 
	int bienb;
public:
    // Các phương thức của lớp con 
	void hamb(){
		bienb = 1;
		cout<<"Gia tri cua bien b = "<<bienb<<endl;
	}
	void nhap(){
		cout << "\nNhap gia tri cua bien b = "; cin >> bienb;
	}
};
void main(){
	B bobject; // Khởi tạo đối  tượng của lớp con 
	
	bobject.nhap();
	bobject.A::nhap();// Gọi hàm con  của lóp cha từ lớp con 
	system("pause");
}