//Biến này sẽ chịu ảnh hưởng bởi tất các đối tượng thuộc lớp chưa biến static 
#include <iostream>
#include <string>
using namespace std;
class TestClass
{
public:    
    int num;          //Khai báo biến thông thường

    static int sNum;  //Khai báo biến static

public:
    TestClass(){ num = 10;} 
};

//Khởi tạo giá trị cho biến static
int TestClass::sNum = 100;

int main()
{   
    // Có thể truy cập đến biến static thông qua lớp luôn chứ không cần  qua đối tượng khởi 
    //tạo  trong hàm chính 
    cout << TestClass::sNum<<endl; // 100
    // cout << TestClass::num;  // error: invalid use of non-static data member
    TestClass s;
    cout << s.num<<endl;
}
