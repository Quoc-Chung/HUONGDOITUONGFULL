#include<bits/stdc++.h>
using namespace std;
class Book{
  private :
    int MaSach;
    string TenSach;
    string TenTacGia;
  public:
    /* - Hàm khởi tạo không đối số - */
    Book(): MaSach(0), TenSach(""), TenTacGia(""){}
    void Nhap(){
        cout <<"\nNhap MaSach :";
        cin >>MaSach;
        cout<<"\nNhap Ten Sach:";
        cin.ignore();
        getline(cin,TenSach);
        cout<<"\nNhap ten tac gia:";
        getline(cin,TenTacGia);
    }
    /* - Xay dung toán tử nhập - */
    friend istream& operator>>(istream& is,Book &b){
        cout <<"\nNhap MaSach :";
        is >>b.MaSach;
        cout<<"\nNhap Ten Sach:";
        is.ignore();
        getline(is,b.TenSach);
        cout<<"\nNhap ten tac gia:";
        getline(is,b.TenTacGia);
        return is;
    }
    void Xuat(){
        cout<<"\nMa sach :"<<MaSach;
        cout<<"\nTen sach:"<<TenSach;
        cout<<"\nTen tac gia :"<<TenTacGia;
    }
    friend ostream& operator<<(ostream& os,Book &b){
        cout<<"\nMa sach :"<<b.MaSach;
        cout<<"\nTen sach:"<<b.TenSach;
        cout<<"\nTen tac gia :"<<b.TenTacGia;
        return os;
    }
    void TimNhungQuyenSachCungTenTacGia(Book* b, int n) {
    map<string, vector<string>> sachCungTacGia; 
    for (int i = 0; i < n; i++) {
        string tacGia = b[i].TenTacGia;
        string tenSach = b[i].TenSach;       
        // Kiểm tra tên tác giả đã tồn tại trong map chưa
        if (sachCungTacGia.find(tacGia) == sachCungTacGia.end()) {
            // Nếu chưa tồn tại, thêm tác giả và tên sách đầu tiên của họ vào map
            sachCungTacGia[tacGia] = {tenSach};
        } else {
            // Nếu tác giả đã tồn tại, thêm tên sách của họ vào danh sách
            sachCungTacGia[tacGia].push_back(tenSach);
        }
    }
    // Duyệt qua map để in thông tin
    for (auto& it : sachCungTacGia) {
        string tacGia = it.first;
        vector<string> tenSach = it.second;
        cout << "Tac gia: " << tacGia << endl;
        cout << "Danh sach sach cua tac gia: ";
        for ( string& ten : tenSach) {
            cout << ten << ", ";
        }
        cout << endl;
    }
}
};
int main(){
    int n;
    cout<<"\nNhap so luong sach:";
    cin >> n;
    Book *b = new Book[n];
    for(int i=0;i<n;i++){
        b[i].Nhap();
    }
    cout<<"\nSach vua nhap la :"<<endl;
    for (int i=0;i<n;i++){
        b[i].Xuat();
    }
    b[0].TimNhungQuyenSachCungTenTacGia(b,n);
    return 0;  
}