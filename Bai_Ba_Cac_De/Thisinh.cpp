//     Xây dựng lớp biểu diễn các đối tượng thí sinh gồm các thuộc tính : số báo danh , họ tên , năm sinh , giới tính 
//, điểm thi toán , lí , hóa , các hàm toán tử nhập uất , phương thức lấy số báo danh.

//     Tiếp theo xây dựng lớp quản lí một một danh sách thí sinh của một cuộc thi bằng danh sách liên kết ( Sử dụng
// lớp list của C++ ) có  các phương thức sau : thêm một thí sinh , Xóa một thí sinh theo mã.

//     In danh sách thí sinh lên màn hình , tìm kiếm thí sinh theo số báo danh bằng thuật toán tìm kiếm tuần tự  
#include<bits/stdc++.h>
using namespace std;
class ThiSinh{
    private:
       int SoBaoDanh;
       string HoTen;
       int NamSinh;
       string GioiTinh;
       float Toan,Li,Hoa;
    public:
       int GetSoBaoDanh(){
        return SoBaoDanh;
       }
       ThiSinh(): SoBaoDanh(0),HoTen(""),NamSinh(0),GioiTinh(""),Toan(0),Li(0),Hoa(0){}
      
       friend istream& operator>>(istream& is,ThiSinh& ts){
        cout <<"\nNhap so bao danh:";
        is>>ts.SoBaoDanh;
        cout<<"\nNhap ho ten:";
        is.ignore();
        getline(is,ts.HoTen);
        cout<<"\nNhap nam sinh:";
        is>>ts.NamSinh;
        cout<<"\nNhap gioi tinh:";
        is.ignore();
        getline(is,ts.GioiTinh);
        cout<<"\n Nhap diem toan - li - hoa:";
        is>>ts.Toan>>ts.Li>>ts.Hoa;
        return is;
       }

       friend ostream& operator<<(ostream& os,ThiSinh & ts){
        os<<"\nSo bao danh:"<<ts.SoBaoDanh;
        os<<"\nHo Ten :"<<ts.HoTen;
        os<<"\nNam sinh :"<<ts.NamSinh;
        os<<"\nGioi tinh :"<<ts.GioiTinh;
        os<<"\nDiem Toan- Li - Hoa  :"<<ts.Toan<<" - "<<ts.Li<<" - "<<ts.Hoa<<endl;
        return os;
       }
};

class QuanLi{
    private:
       list<ThiSinh> danhsachThiSinh;
    public:
       void ThemMotThiSinh(ThiSinh &ts){
          danhsachThiSinh.push_back(ts);
       }
       void XoaThiSinh(int SoBaoDanh){
        bool TimThay = false;
        for(auto it = danhsachThiSinh.begin();it !=danhsachThiSinh.end();it++){
            if((*it).GetSoBaoDanh()==SoBaoDanh){
                danhsachThiSinh.erase(it);
                TimThay=true;
                break;
            }
        }
        if(TimThay){
             cout<<"\nXoa thanh cong"<<endl;
        }
        else{
             cout<<"\nKhong tim thay de xoa"<<endl;
        }
    }
       void InDanhSachThiSinh(){
        int i=1;
        for(ThiSinh ts :danhsachThiSinh){
            cout <<"\nDanh sach thi sinh thu"<<i<<" : "<<ts;
        }
       }
       ThiSinh* TimKiemThiSinhTheoSoBaoDanh(int SoBaoDanh){
          for(ThiSinh &ts :danhsachThiSinh){
            if(ts.GetSoBaoDanh() == SoBaoDanh){
            /* - Trả về ThiSinh*  == &ts - */
                     return &ts;
            }                
           }
           return nullptr;
       }
       void TimKiemThiSinh(int SoBaoDanh){
        for (auto it =danhsachThiSinh.begin();it != danhsachThiSinh.end();it++){
            if(it->GetSoBaoDanh() == SoBaoDanh){
                cout <<"\nTIM THAY SINH VIEN:"<<endl;
                cout <<(*it)<<endl;
            }
        }
    }
};

int main(){
    int n;
    cout<<"\nNhap so luong thi sinh:";
    cin >> n;
    QuanLi qlThiSinh;
    for(int i=0;i<n;i++){
        cout <<"\nNHAP THI SINH :";
        ThiSinh ts;
        cin >> ts;
        qlThiSinh.ThemMotThiSinh(ts);
    }
    cout <<"\nDANH SACH THI SINH :";
    qlThiSinh.InDanhSachThiSinh();

    int SoBaoDanhTimKiem;
    cout << "\nNhap so bao danh de tim kiem: ";
    cin >> SoBaoDanhTimKiem;

    ThiSinh* tsTimThay = qlThiSinh.TimKiemThiSinhTheoSoBaoDanh(SoBaoDanhTimKiem);

    if (tsTimThay != nullptr) {
        cout << "Tim thay thi sinh: " << *tsTimThay << endl;
    } else {
        cout << "Khong tim thay thi sinh co So Bao Danh " << SoBaoDanhTimKiem << endl;
    }
     qlThiSinh.TimKiemThiSinh(SoBaoDanhTimKiem);
     return 0;
}
/*
for(ThiSinh &ts :danhsachThiSinh){
            if(ts.GetSoBaoDanh() == SoBaoDanh){
                     return &ts;
            }                
           }
- Hàm này trả về ThiSinh* hay cũng là một con trỏ lưu địa chỉ
- Hàm duyệt tham chiếu sẽ tham chiếu trực tiếp đến biến tránh tạo 
ra bản sao gây sai lệch dữ liệu  
*/