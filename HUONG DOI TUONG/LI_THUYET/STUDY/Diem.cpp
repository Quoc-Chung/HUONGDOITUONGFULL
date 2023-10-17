#include<bits/stdc++.h>
using namespace std;
class Diem {
    private :
        float HoanhDo, TungDo;
    public :
      Diem (){
            HoanhDo = TungDo =0;
        }
        float getHoanhDo(){
            return HoanhDo;
        }
        float getTungDo(){
            return TungDo;
        }
        void Nhap(){
            cout<<"\nNhap hoanh do :";
            cin >> HoanhDo;
            cout<<"\nNhap tung do :";
            cin >> TungDo;
        }
        void Xuat(){
            cout<<"\n la :" <<"("<<HoanhDo <<","<<TungDo<<")"<<endl;
        }
        float tinhKhoangCach() {
            return sqrt(HoanhDo * HoanhDo + TungDo * TungDo);
        }
};
class DiemMoi :public Diem  {
  private:
      string mau;
  public :
    DiemMoi(){
        mau="";
    }
    string getmau(){
       return mau;
    }
    void Nhap(){
       Diem  :: Nhap();
       cout<<"\nNhap mau :";
       cin.ignore();
       getline(cin, mau);
    } 
};
int main() {
    int n;
    cout << "Nhap so : ";
    cin >> n;
    
    DiemMoi *List = new DiemMoi[n];
    for (int i = 0; i < n; i++) {
        cout << "\nNhap  thu " << i + 1 << ":" << endl;
        List[i].Nhap();
    }
    // Thống kê số điểm theo mau
    int dem1 = 0, dem2 = 0, dem3 = 0;
    for (int i = 0; i < n; i++) {
        if (List[i].getmau() == "do") {
            dem1++;
        } else if (List[i].getmau() == "xanh") {
            dem2++;
        } else if (List[i].getmau() == "vang") {
            dem3++;
        }
    }
    cout << "So  theo mau:" << endl;
    cout << "Do: " << dem1 << " " << endl;
    cout << "Xanh: " << dem2 << " " << endl;
    cout << "Vang: " << dem3 << " " << endl;
    // Tìm điểm đỏ xa gốc tọa độ nhất
    float maxKhoangCach = 0;
    int vitri  =0;
    for (int i = 0; i < n; i++) {
        if (List[i].getmau() == "do") {
            float khoangCach = List[i].tinhKhoangCach();
            if (khoangCach > maxKhoangCach) {
                maxKhoangCach = khoangCach;
                vitri=i;
            }
        }
    }
    if(maxKhoangCach==0){
        cout<<"\nKhong co  do nao.";
    }
    else{
        cout<<"\n Xa goc toa do nhat :"<<endl;
        List[vitri].Xuat();
    }
    delete[] List; // Giải phóng bộ nhớ sau khi sử dụng mảng động
    return 0;
}
