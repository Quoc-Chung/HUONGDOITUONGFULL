#include<bits/stdc++.h>
using namespace std;
// Khai bao lop cha (Animal)
class Animal {
  private :
    string Loai;
  public :
  // Ham khoi tao (Contructor)
    Animal(){
        Loai="Animal";
    }
    // Xay dung ham ao tra ve LoaiVat
    virtual string getLoai(){
        return Loai;
    }
};
// Xay dung ham dog ke thua tu lop animal
class Dog : public Animal{
    private :
      string Loai;
    public :
     //Contructor
     Dog (){
        Loai="Dog";
     }
     string getLoai(){
        return Loai;
     }
};
class Cat: public Animal{
    private :
    string Loai;
    public :
      Cat(){
        Loai="Meo ";
      }
      string getLoai(){
        return Loai;
      }
};

void Printf(Animal *x){
    cout << "\nAnimal :"<<x->getLoai()<<endl;
}
int main(){
  Animal *x=new Animal();
  Printf(x);

  Animal *dog=new Dog(); //Khoi tao con tro tro den mot 
  // doi tuong cua lop dog
  Printf(dog);

  Animal *cat=new Cat();// Khoi tao con tro tro den mot
  //doi tuong cua lop cat
  Printf(cat);

  return 0;
}