#include<iostream> 
using namespace std; 
  
class TestClass 
{
public: 
    static int sNum;  //Khai báo biến static
public: 
      
    // static member function 
    static void func1()  { cout<<sNum; } ////Khai báo hàm static 
}; 
  
//Khởi tạo giá trị cho biến static
int TestClass::sNum = 100;

int main() 
{ 
    /*Truy cập các hàm thành viên mà không tạo ra instance*/
    TestClass::func1(); //100
}
