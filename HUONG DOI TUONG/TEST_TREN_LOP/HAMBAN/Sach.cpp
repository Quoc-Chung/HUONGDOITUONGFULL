#include<bits/stdc++.h>
using namespace std;
class BOOK {
private:
    int MaSach;
    string TenSach;

public:
    int getMaSach() {
        return MaSach;
    }
    // Hàm toán tử nhập (không cần friend)
    istream& operator>>(istream& is) {
        cout << "Nhap Ma Sach: ";
        is >> MaSach;
        cout << "Nhap Ten Sach: ";
        is.ignore(); // Xóa ký tự '\n' còn lại trong bộ đệm
        getline(is, TenSach);
        return is;
    }

    // Hàm toán tử xuất (không cần friend)
    ostream& operator<<(ostream& os){
        os << "Ma Sach: " << MaSach << "\n";
        os << "Ten Sach: " << TenSach << "\n";
        return os;
    }
};
/* - Muốn định nghĩa các hàm toán tử nhập xuất bên ngoài lớp 
và muốn  truy cập trực tiếp vào các thành viên private của lớp mà 
không cần thông qua các phương thức thành viên public -  */
class Book {
private:
    int MaSach;
    string TenSach;

public:
    int getMaSach() {
        return MaSach;
    }

    friend istream& operator>>(istream& is, Book& k) {
        // Truy cập MaSach và TenSach trong hàm bạn
    }

    friend ostream& operator<<(ostream& os, const Book& k) {
        // Truy cập MaSach và TenSach trong hàm bạn
    }
};
int main (){
    Book b;
    cin >>b;
    cout <<b;
    
    /* -  Không sử dung dược khi ra khỏi ngoài hàm  - */
    BOOK x;
    // cin >> x;
    // cour <<"\nVua nhap la :"<<x<<endl;
    return 0;  
}