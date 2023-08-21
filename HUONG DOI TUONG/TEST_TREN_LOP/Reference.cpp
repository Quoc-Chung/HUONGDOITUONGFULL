#include<bits/stdc++.h>
using namespace std;
// void  PassByValue(int  value);
// void PassByReference(int &value);
void  PassByValue(int value){
// change value to value 
   cout << "Dia chi cua tham tri :"<<&value<<endl;
  value = 10; 
}
void PassByReference(int &value){
    cout << "Dia chi cua tham chieu :"<<&value<<endl;
    value  = 15;
}

int main(){
    // Initialize value for value
    int value =5;
    cout << "Dia chi cua gia tri ban dau khi truyen tham tri :"<<&value<<endl;
    cout << "Gia tri ban dau:"<<value<<endl;
    PassByValue(value);
    cout << value <<endl;  // Not change value

    // PassByReference(value);
    // cout << "Gia tri sau khi goi ham tham chieu :"<<value<<endl;
    return 0;

}
