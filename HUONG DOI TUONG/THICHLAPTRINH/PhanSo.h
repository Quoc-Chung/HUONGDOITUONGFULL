//Dây chính là tệp  dùng để định nghĩa 
//Đánh dấu tệp chỉ được  biên dịch một lần duy nhất 
#pragma once
using namespace std;
class PhanSo{
  private :
     int TuSo;
     int MauSo;
  public  :
     void Nhap();
     void Xuat();
     
    PhanSo(void);
    ~PhanSo(void);
};