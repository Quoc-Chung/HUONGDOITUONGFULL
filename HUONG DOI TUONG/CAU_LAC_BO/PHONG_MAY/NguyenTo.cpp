#include<bits/stdc++.h>
using namespace std;
bool Nguyento(int n) {
    if (n < 2) {
        return false;
    } else {
        for (int i=2;i<=sqrt(n);i++) {
            if (n%i==0) {
                return false;
            }
        }
    }
    return true;
}
class NguyenTo {
private:
    int n;
public:
    NguyenTo(int n) {
        this->n = n;
    }
    void KiemTra() {
        if (Nguyento(n)) {
            cout << "\nLa so nguyen to." << endl;
        } else {
            cout << "\nKhong la so nguyen to." << endl;
        }
    }
};
int main() {
    int n;
    cout << "\nNhap n:";
    cin >> n;
    NguyenTo a(n);
    a.KiemTra();
    return 0;
}
