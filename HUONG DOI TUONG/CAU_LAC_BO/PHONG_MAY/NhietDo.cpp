// In bảng nhiệt độ: bên trái là độ C (Celsius), với giá trị là các số chẵn từ
// 10 đến 40 và bên phải là độ F (Fahrenheit) tương ứng, biết độ F được
// tính theo công thức: F = C * 9/5 + 32. 
#include<bits/stdc++.h>
using namespace std;
class TemperatureConverter{
    private :
      int LessCelsius;
      int GreaterCelsius;

    public :
      // Ham khoi tao co doi so truyen vao
      TemperatureConverter(int LessCelsius ,int GreaterCelsious){
        this->LessCelsius = LessCelsius;
        this->GreaterCelsius = GreaterCelsious;
     
      }
    // Xay dung ham tinh toan  do F
    double CaculateF(int do_C){
        return (do_C * 9.0/5.0 + 32.0);
    }
    void  PrintfTable(){
        cout <<"Do_C \tDo_F"<<endl;
        for (int Celsius = LessCelsius;Celsius<=GreaterCelsius; Celsius+=2){
            double do_F = CaculateF(Celsius);
            cout << Celsius << "\t" << do_F << endl;
        }
    }
};
int main(){
    int LessCelsius = 10;
    int GreaterCelsious = 40;

    TemperatureConverter T(LessCelsius,GreaterCelsious);
    T.PrintfTable();
    return 0;
}