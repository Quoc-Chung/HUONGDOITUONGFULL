#include<bits/stdc++.h>
using namespace std;
// Khởi tạo  lớp  Book
class Book {
private:
    int MaSach;
    string TenSach;
    string TenTacGia;
    int NamXuatBan;
    string NhaXuatBan;
public:
   // Hàm lấy ra năm xuất bản để tí đem đi so sánh 
    int getNamXuatBan() {
        return NamXuatBan;
    }
   // Hàm nhập bình thường 
    void Nhap() {
        // Khi chuyen nhap tu  int -> string phải có cin.ignore() để xóa bộ nhớ đêm đầu vào 
        cout << "Nhap Ma Sach: ";
        cin >> MaSach;
        cin.ignore(); //  Xoa  sach  bo nho  dem dau vao 
        cout << "Nhap Ten Sach: ";
        getline(cin, TenSach);
        cout << "Nhap Tac Gia: ";
        getline(cin, TenTacGia);
        cout << "Nam Xuat Ban: ";
        cin >> NamXuatBan;
        cin.ignore(); //Xoa sach bo nho  dem dau vao
        cout << "Nha xuat ban: ";
        getline(cin, NhaXuatBan);
    }
    // Hàm xuất bình thường 
    void Xuat() const {
        cout << "Ma Sach: " << MaSach << endl;
        cout << "Ten Sach: " << TenSach << endl;
        cout << "Tac Gia: " << TenTacGia << endl;
        cout << "Nam Xuat Ban: " << NamXuatBan << endl;
        cout << "Nha xuat ban: " << NhaXuatBan << endl;
    }
};
//Xây dựng lớp quản lí sách ( QLBook )
class QLBook {
private:
    int n;
    Book* dsSach;// Một mảng đối tượng sách  chứa các thuộc tính của Sách 
   
public:
   //Xây dựng  hầm hủy và hàm  quản  lí sách 
    QLBook() {
        n = 0;
        dsSach = nullptr;
    }
    ~QLBook() {
        delete[] dsSach;
    }

    //Hàm nhập sách truyền vào 
    void NhapDS(int sl) {
        n = sl;
        dsSach = new Book[n];// khoi tao mang doi tuong quan li sach lop Book 
        for (int i = 0; i < n; i++) {
            cout << "\nNhap thong tin sach thu " << i + 1 << ":" << endl;
            dsSach[i].Nhap();
        }
    }
    void TimSachTheoNamXuatBan(int nam) {
        cout << "\nCac cuon sach duoc xuat ban nam " << nam << " la:" << endl;
        for (int i = 0; i < n; i++) {
            if (dsSach[i].getNamXuatBan() == nam) {
                dsSach[i].Xuat();
            }
        }
    }
   void SapXepTheoNamXuatBan() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (dsSach[i].getNamXuatBan() > dsSach[j].getNamXuatBan()) {
                Book tmp = dsSach[i];
                dsSach[i] = dsSach[j];
                dsSach[j] = tmp;
            }
        }
    }
    cout << "\nThong tin cac cuon sach theo thu tu tang dan cua nam xuat ban:" << endl;
    for (int i = 0; i < n; i++) {
        dsSach[i].Xuat();
    }
}
};
int main() {
    int n;
    cout << "Nhap so cuon sach: ";
    cin >> n;
    cin.ignore(); // xóa bộ đệm  đầu vào  khi nhập  n
    QLBook ds; // giờ ex khởi tạo  một đối tượng  bằng class  QLBook đẻ gọi  ra các  hàm  
    ds.NhapDS(n);

    int namTim;
    cout << "\nNhap nam can tim sach: ";
    cin >> namTim;

    ds.TimSachTheoNamXuatBan(namTim);

    ds.SapXepTheoNamXuatBan();

    return 0;
}
