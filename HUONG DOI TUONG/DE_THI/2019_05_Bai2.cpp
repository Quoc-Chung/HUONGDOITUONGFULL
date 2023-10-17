#include <bits/stdc++.h>
using namespace std;
class Book {
private:
    int MaSach;
    string TenSach;
    string TenTacGia;
    int NamXuatBan;
    string NhaXuatBan;
public:
    int getNamXuatBan() {
        return NamXuatBan;
    }
    istream& operator >>(istream& is, Book& k) {
    cout << "\nNhap Ma Sach :";
    is >> k.MaSach;
    cin.ignore(); // Clear the input buffer (consume newline)
    cout << "\nNhap Ten Sach:";
    getline(is, k.TenSach);
    cout << "\nNhap Tac Gia:";
    getline(is, k.TenTacGia);
    cout << "\nNam Xuat Ban :";
    is >> k.NamXuatBan;
    cin.ignore(); // Clear the input buffer (consume newline)
    cout << "\nNha xuat ban:";
    getline(is, k.NhaXuatBan);
    return is;
}
     ostream& operator<<(ostream& os, Book k) {
        cout << "\nNhap Ma Sach :" << k.MaSach;
        cout << "\nNhap Ten Sach:" << k.TenSach;
        cout << "\nNhap  Tac Gia:" << k.TenTacGia;
        cout << "\nNam Xuat Ban :" << k.NamXuatBan;
        cout << "\n Nha xuat ban:" << k.NhaXuatBan;
        return os;
    }
};
class QLBook : public Book {
private:
    int n;
    QLBook* k;
public:
    void setn(int n) {
        this->n = n;
    }
    int getn() {
        return n;
    }
    void NhapSach(QLBook* k, int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nNhap Sach Thu" << i + 1 << ":" << endl;
            cin >> k[i];
            cin.ignore(); // Clear the input buffer after reading integer
            // xoa sach dau vao bô dem sau khi dọc  kiểu số  nguyên int 
        }
    }
    void In(QLBook *k, int n) {
        for (int i = 0; i < n; i++) {
            cout << "\nThong tin sach thu :" << i + 1 << ":" << endl;
            cout << k[i];
        }
    }
    void NhapVaoNam(QLBook *k, int n) {
        int nam;
        cout << "\nNhap Nam Tim Sach :";
        cin >> nam;
        for (int i = 0; i < n; i++) {
            if (k[i].getNamXuatBan() == nam) {
                cout << k[i];

            }
        }
    }
  void ThongTinSachTangDan(QLBook* k, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (k[i].getNamXuatBan() > k[j].getNamXuatBan()) {
                QLBook* tmp = &k[i];
                k[i] = k[j];
                k[j] = *tmp;
            }
        }
    }
    cout << "\nThong tin cua n cuon sach la:\n";
    In(k, n);
}

};
int main() {
    int n;
    cout << "\nNhap so cuon sach :";
    cin >> n;
    QLBook* k = new QLBook[n]; // Create an array of QLBook objects
    QLBook q;
    q.setn(n);
    q.NhapSach(k, q.getn());

    q.In(k, q.getn());
    q.NhapVaoNam(k, q.getn());
    q.ThongTinSachTangDan(k, q.getn());

    delete[] k; // Don't forget to free the memory allocated with 'new'
    return 0;
}





