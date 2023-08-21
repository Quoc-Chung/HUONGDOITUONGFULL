#include<bits/stdc++.h>
using namespace std;
class PhanSo {
private:
    int TuSo;
    int MauSo;
public:
    // Constructor có tham số
    PhanSo(int TuSo, int MauSo) {
        this->TuSo = TuSo;
        this->MauSo = MauSo;
    }
    void Nhap() {
        cout << "\nNhap Tu So: "; cin >> TuSo;
        cout << "Nhap Mau So: "; cin >> MauSo;
    }
    void InPhanSo() {
        cout << "(" << TuSo << "/" << MauSo << ")";
    }
};
int main() {
    int TuSo, MauSo;
    cout << "Nhap Tu So cho Phan So: ";
    cin >> TuSo;
    cout << "Nhap Mau So cho Phan So: ";
    cin >> MauSo;

    PhanSo p(TuSo, MauSo); // Sử dụng constructor có tham số để khởi tạo đối tượng p
    p.InPhanSo();

    return 0;
}
