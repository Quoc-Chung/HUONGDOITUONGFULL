#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    int MaSach;
    string TenSach;
    string TenTacGia;
    int NamXuatBan;
    string NhaXuatBan;

public:
    // Hàm tạo không có đối số
    Book() {
        MaSach = NamXuatBan = 0;
        TenSach = TenTacGia = NhaXuatBan = "";
    }

    void Nhap() {
        cout << "\nNhap Ma Sach: ";
        cin >> MaSach;

        cout << "\nNhap Ten Sach: ";
        cin.ignore();
        getline(cin, TenSach);

        cout << "\nNhap Ten Tac Gia: ";
        getline(cin, TenTacGia);

        cout << "\nNhap Nam Xuat Ban: ";
        cin >> NamXuatBan;

        cout << "\nNhap Nha Xuat Ban: ";
        cin.ignore();
        getline(cin, NhaXuatBan);
    }

    void Xuat() {
        cout << "\nMa Sach: " << MaSach;
        cout << "\nTen Sach: " << TenSach;
        cout << "\nTen Tac Gia: " << TenTacGia;
        cout << "\nNam Xuat Ban: " << NamXuatBan;
        cout << "\nNha Xuat Ban: " << NhaXuatBan;
    }

    void TimTacGia(Book* k, int n) {
        string TacGia;
        cin.ignore();
        cout << "\nNhap Ten Tac Gia: ";
        getline(cin, TacGia);
        cout << "\nTat Ca cac cuon sach cua Tac Gia " << TacGia << " la:\n";
        for (int i = 0; i < n; i++) {
            if (k[i].TenTacGia.compare(TacGia) == 0) {
                cout << k[i].TenSach << endl;
            }
        }
    }
};

int main() {
    int n;
    cout << "\nNhap n: ";
    cin >> n;
    cin.ignore(); // Xóa bộ đệm đầu vào sau khi nhập n
    Book* b = new Book[n];
    for (int i = 0; i < n; i++) {
      cout<<"\nNHAP CUON SACH THU "<<i+1<<":"<<endl;
        b[i].Nhap();
    }
    for (int i=0;i<n;i++){
       b[i].Xuat();
    }
    b[0].TimTacGia(b, n);
    return 0;
}
