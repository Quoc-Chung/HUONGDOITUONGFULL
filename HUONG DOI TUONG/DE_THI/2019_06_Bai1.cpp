#include<bits/stdc++.h>
using namespace std;

class Dathuc {  
private:
    int bac;
    int heso;
public:
    friend istream& operator >> (istream& is, Dathuc& d) {
        is >> d.heso;
        return is;
    }
    friend ostream& operator << (ostream& os, Dathuc d) {
        os << d.heso << " ";
        return os;
    }
    void setbac(int bac){
        this->bac=bac;
    }
    void Nhap(Dathuc* d);
    void In(Dathuc* d);
    void TinhDaThuc(Dathuc* d);
};
void Dathuc::Nhap(Dathuc* d) {
    cout <<"\nNhap cac  he  so :"<<endl;
    for (int i = 0; i <= bac; i++) {
        cin >> d[i];
    }
}
void Dathuc::In(Dathuc* d) {
    cout << "\nThong tin he so la :\n";
    for (int i = 0; i <= bac; i++) {
        cout << d[i].heso << " ";
    }
}

void Dathuc::TinhDaThuc(Dathuc* d) {
    int x;
    cout << "\nNhap x:";
    cin >> x;
    int dathuc = d[0].heso;
    for (int i = 1; i <= bac; i++) {
        dathuc += d[i].heso * pow(x, i);
    }
    cout << "\nGia tri cua da thuc la: " << dathuc << endl;
}
int main() {
    int n;
    cout << "\nNhap so bac: ";
    cin >> n;
    Dathuc* d = new Dathuc[n + 1];
    d->setbac(n);
    d->Nhap(d);
    d->In(d);
    d->TinhDaThuc(d);
    delete[] d;
    return 0;
}
