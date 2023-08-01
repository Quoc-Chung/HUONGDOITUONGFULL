#include<bits/stdc++.h>
using namespace std;
class Shape{
  protected:
    float dimension; // kích thước
  public :
    void getDimension(){
        cin>>dimension; 
    }
    // khai báo lớp thuần ảo 
    virtual float CalculateArea() =0; 
};
// Xây dựng các lớp kế thừa 
class Square :public Shape{
    public :
      float CalculateArea(){
        return  dimension *dimension;
      }
};
class Circle :public Shape{
    public :
     float CalculateArea(){
         return 3.14 * dimension * dimension;
     }
};
int main(){
    // KHởi tạo đối tượng cho hai lớp kết thừa 
    // Square square;
    // Circle circle;
    
    // cout << "Enter the length of the square: ";
    // square.getDimension();
    // cout << "Area of square: " << square.CalculateArea() << endl;

    // cout << "\nEnter radius of the circle: ";
    // circle.getDimension();
    // cout << "Area of circle: " << circle.CalculateArea() << endl;
	// system("pause");

    Shape *x =new Square;
   
    cout << "Enter the length of the square: ";
    x->getDimension();
    cout << "Area of square: " << (*x).CalculateArea() << endl;

    Shape *y =new Circle;
    cout << "\nEnter radius of the circle: ";
    y->getDimension();
    cout << "Area of circle: " << (*y).CalculateArea() << endl;
	system("pause");


}