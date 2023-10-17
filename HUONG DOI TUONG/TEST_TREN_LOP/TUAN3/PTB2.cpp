#include<bits/stdc++.h>
#include <conio.h> // Sử dụng thư viện conio.h
using namespace std;
class PTB2 {
private:
    int a, b, c;
public:
    PTB2() {
        a = b = c = 0;
    }
    void Nhap() {
        cout << "\nNhap he so :";
        cin >> a >> b >> c;
    }
    void Xuat() {
        cout << "\nPTB2 co dang:";
        cout << a << "X^2" << " + " << b << "X" << " + " << c << endl;
    }
    void GiaiPhuongTrinh() {
            float delta = b * b - 4 * a * c;
            if (delta > 0) {
                float x1 =(-b + sqrt(delta)) / (2 * a);
                float x2 =(-b - sqrt(delta)) / (2 * a);
                cout << "Phuong trinh co hai nghiem phan biet: x1 = " << x1 << " va x2 = " << x2 << std::endl;
            } else if (delta == 0) {
                float x = -b / (2 * a);
                cout << "Phuong trinh co mot nghiem kep: x = " << x << std::endl; 
            } else {
                cout << "Phuong trinh khong co nghiem nao" << std::endl;
            } 
    }
};
int main() {
    PTB2 p;
    char c;
    do{
    p.Nhap();
    p.Xuat();
    p.GiaiPhuongTrinh();
    cout<<"\nNhap phim khac ESC de tiep tuc :";
     c = _getch();
    }while(c != 27);   
    return 0;
}
