#include <iostream>
using namespace std;
class LopCoSo{
public:
// HÀm  khởi tạo của lớp cha 
	LopCoSo(){
		cout << "Ham khoi tao cua lop co so!" << endl;
	}
    // HÀm  hủy cua lớp cha 
	~LopCoSo(){
		cout << "Ham huy cua lop co so!" << endl;
	}
};
class LopDanXuat : public LopCoSo{
public:
// HÀm khởi tạo  của lớp con 
	LopDanXuat(){
		cout << "Ham khoi tao cua lop dan xuat!" << endl;
	}
    // Hàm hủy của lớp con 
	~LopDanXuat(){
		cout << "Ham huy cua lop dan xuat!" << endl;
	}
};
int  main(){
	LopDanXuat obj;// KHởi tạo đối  tượng của lớp  con 
    
}
/*
- Ham khoi tao cua lop co so!
- Ham khoi tao cua lop dan xuat!
- Ham huy cua lop dan xuat!
- Ham huy cua lop co so!
*/