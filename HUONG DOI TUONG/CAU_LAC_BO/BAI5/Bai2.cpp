// 2. Xây dựng lớp  biểu diễn điểm trong không gian 2 chiều, trong đó có dữ liệu 
// (private) gồm hoành độ, tung độ và các phương thức (public) sau:
//  Toán tử >> để nhập điểm
//  Toán tử << để xuất điểm ra màn hình
//  Toán tử * để “nhân” hai điểm theo công thức: (x1,y1) , (x2 ,y2)  = ( x1*x2 , y1 *y2)
//  Phương thức tính khoảng cách giữa hai điểm
#include<bits/stdc++.h>
using namespace std;
class  {
    private : 
      float x;
      float y;
    public  :
      (){
       x = y =0; 
      }
      friend istream& operator>>(istream& is , &d) {
        cout<<"\nNhap hoanh do :";
        is>>d.x;
        cout<<"\nNhap tung do :";
        is >>d.y;
        return is;
      }
      friend ostream& operator<<(ostream& os , &d) {
        cout<< "(" <<d.x<<","<<d.y << ")"<<endl;
        return os;
      }
       operator*( &d2){
         tmp ;
        tmp.x = x * d2.x;
        tmp.y = y * d2.y;
        return tmp;
      }
      float TinhKhoangCach( D2) {
    // Sử dụng công thức khoảng cách Euclid để tính
     D1=*this;
    float khoangCach = sqrt(pow(D2.x - D1.x, 2) + pow(D2.y - D1.y, 2));
    return khoangCach;
    }
};

int main(){
    A,B;
   cout<<"\nNhap  A:";
   cin >> A;
   cout<<"\nNhap  B :";
   cin >> B;
   cout<<"\n A la :"<<A ;
   cout<<"\n B la :"<<B ;
   float kc =A.TinhKhoangCach(B);//A.TinhKhoangCach(A,B);
   cout<<"Khoang cach: "<<fixed<<setprecision(2)<<kc<<endl;
    tich = A*B;
   cout<<"\nTich hai  A va B :"<<tich<<endl;
   return 0;
}