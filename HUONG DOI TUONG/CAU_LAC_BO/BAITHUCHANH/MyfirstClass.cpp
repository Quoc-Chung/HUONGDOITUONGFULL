#include<bits/stdc++.h>
using namespace std;
class MyFirstClass{
  public :
    int ClassMember;// Thành viên lớp
};
int main(){
   MyFirstClass myFirstClass;
   myFirstClass.ClassMember = 10;
   cout << myFirstClass.ClassMember;
}