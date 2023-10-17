#include<bits/stdc++.h>
using namespace std;
// base class    : class cha 
// derived class : class con 
class Person{
    private  :
       string name;
       string address;
    public :
       Person(string name, string address) : name(name), address(address){}
       string getName(){
          return name;
       }
       string getAddress(){
          return address;
       }
    void setName(string name){
        this->name = name;
    }
    void setAddress(string address){
        this->address = address;
    } 
    void In(){
        cout<< name<<"  "<< address<<endl;
    }
};
class Student: public Person{
    private:
       float gpa;
    public :
    /* - Cách viết hàm tạo cho hàm kế thừa - */
       Student(string name,string address,float gpa) : Person(name, address){
        this->gpa = gpa;
       }
       float getGpa(){
            return gpa;
        }
       void setGpa(float gpa){
          this->gpa = gpa;
        }    
        /* - Ghi đè hàm in - */
       void In(){
        cout<< getName()<< " " << getAddress()<< " " << gpa<<endl;
       }
       /* - Có thể sử dụng toán tử phạm vi " :: " như này cũng được 
       void In(){
        Person::In();
        cout<<gpa<<" "<<endl;
        }     
       */
};
class Teacher: public Person{
    private:
       float luong;
    public :
       
};

class Employee: public Person{
    private :
};

int main(){
    // Student s;
    // s.setName("Nguyen Van A");
    // s.setAddress("Hai Duong");
    // s.setGpa(4.0);
    // s.In();

    return 0;
}