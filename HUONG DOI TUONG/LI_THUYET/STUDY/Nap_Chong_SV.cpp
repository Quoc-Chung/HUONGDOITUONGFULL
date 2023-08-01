#include<bits/stdc++.h>
using namespace std;

class ThoiGian{
 public:
   int hour;
   int minute;
   static float gio_toan_cuc;
 public:
   // Xay dụng ham khoi tao mặc định
   ThoiGian() : hour(0) ,minute(0) {}
   ThoiGian (int hour,int minute){
    this->hour=hour;
    this->minute=minute;
   }
   // Nạp chồng toán tử một ngôi 
   //Nạp chồng tiền tố :Cộng trước rồi mới làm việc  
   ThoiGian operator ++ (){
     ++minute;
     if(minute >=60){
      ++hour;
      minute-=60;
     }
     return ThoiGian(hour,minute);
   }
   // Nạp chồng  hậu  tố :Thêm biến  thời gian lưu giá 
   // trị rồi mới  cộng  sau 
   ThoiGian operator++(int) //hàm nạp chồng toán tử ++ hậu tố
    {
        ThoiGian T(hour, minute);
        ++minute;         
        if (minute >= 60)
        {
            ++hour;
            minute -= 60;
        }
        return T;
    }
  void DoiRaGio(ThoiGian T);
  void Do_Ra_Gio_Phut(float Gio);

    //Nạp  chồng toán tử hai  ngôi (Có hai biến thời gian)
     // hai  cái  trừ  đi nhau  là ra 
     friend ThoiGian operator - (ThoiGian& T1, ThoiGian& T2) 
    {
        ThoiGian T;
        T.hour = T1.hour - T2.hour;
        T.minute = T1.minute - T2.minute;
        return T;
    }

    //Nạp chồng toán tử cộng thời gian 
    friend ThoiGian operator +(ThoiGian &T1,ThoiGian &T2){
      ThoiGian T;
      T.hour =T1.hour+T2.hour;
      T.minute=T1.minute+T2.minute;
      return  T;
    }
    // nạp chồng toán tử hai ngôi so sánh 
      friend bool operator < (ThoiGian& T1, ThoiGian& T2)
    {
        if (T1.hour == T2.hour)
        {
            if (T1.minute < T2.minute)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else if(T1.hour < T2.hour)
        {
            return true;
        }
        return false;
    }
    // Nạp  chồng toán tử nhập ístream
    friend istream& operator >> (istream& is, ThoiGian& T) //nạp chồng toán tử nhập
    {
        cout << "hour = ";
        is >> T.hour;
        cout << "minute = ";
        is >> T.minute;
        return is;
    }
   //Nạp  chồng toán tử xuất ostream
    friend ostream& operator << (ostream& os, ThoiGian& T) // nạp chồng toán tử xuất
    {
        os << T.hour << "h:" << T.minute << "p" << endl;
        return os;
    }
};
 float ThoiGian ::gio_toan_cuc=0;
void ThoiGian ::DoiRaGio(ThoiGian T){
     float gio;
     gio+=(float)T.hour+ (float)T.minute / 60 ;
     gio_toan_cuc=gio;
     //Nếu giờ dang lớn hơn 
    cout <<"\nThong tin  gio la :"<<fixed<<setprecision(1)<<gio<<endl;   
}
void ThoiGian::Do_Ra_Gio_Phut(float gio){
  float phut=gio *60;
  int gio_doi=phut/60;
  int phut_doi=(int)phut-gio_doi*60;
 cout <<"\nBay gio la :"<<gio_doi<<" gio "<<phut_doi<<" phut "<<endl;
}
int main(){
  ThoiGian T1(8,59),T2(6,24);//Dùng hàm khởi tạo đã dựng bên trên
  ThoiGian T3; //Dùng toán tử mặc định 

  T3=T1+T2;
  // Dùng để gọi thời gian để đổi 
  ThoiGian x;
  x.DoiRaGio(T3);
  x.Do_Ra_Gio_Phut(ThoiGian::gio_toan_cuc);
   return 0;
}
