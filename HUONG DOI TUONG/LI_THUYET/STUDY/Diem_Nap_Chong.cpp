#include<bits/stdc++.h>
using namespace std;
class Diem{
    private :
   int hoanh ,tung;
    public:
       // Nạp  chồng toán tử nhập ístream
    friend istream& operator >> (istream& is,Diem& D) //nạp chồng toán tử nhập
    {
        cout << "Hoanh do = ";
        is >> D.hoanh;
        cout << "Tung do = ";
        is >> D.tung;
        return is;
    }
   //Nạp  chồng toán tử xuất ostream
    friend ostream& operator << (ostream& os,Diem& D) // nạp chồng toán tử xuất
    {
        os <<"("<<D.hoanh<<","<<D.tung<<")"<<endl;
        return os;
    }
    friend Diem operator*(Diem &D1,Diem &D2){
        Diem D3;
        D3.hoanh=D1.hoanh*D2.hoanh;
        D3.tung=D1.tung*D2.tung;
        return D3;
    }
    void KhoangCach(Diem D1,Diem D2){
        float khoang_cach= sqrt(pow(D2.hoanh-D1.tung,2)+pow(D2.tung-D1.tung,2));
        cout <<"\nKhoang cach giua hai diem :"<< khoang_cach<<endl;
    }
};
int main() {
    Diem main;
    Diem D1, D2;
    cout << "Nhap thong tin cho diem D1: " << endl;
    cin >> D1;
    cout << "Nhap thong tin cho diem D2: " << endl;
    cin >> D2;

    Diem D3=D1*D2;
    cout<<D3<<endl;
    main.KhoangCach(D1,D2);
    return 0;
}
