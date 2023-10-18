#include<bits/stdc++.h>
using namespace std;
class NhanVien{
 private :
   int Ma;
   string Ho_Ten;
   int Nam_Sinh;
   long long Luong;
 public :
   NhanVien(){
     Ma = Nam_Sinh = Luong =0;
     Ho_Ten ="";
   }
    friend istream& operator>>(istream& is, NhanVien &nv){
    cout<<"\nNhap ma nhan vien:";
    is >> nv.Ma;
    cout<<"\nNhap Ho va Ten :";
    is.ignore();
    getline(is,nv.Ho_Ten);
    cout<<"\nNhap nam sinh :";
    is >> nv.Nam_Sinh;
    cout<<"\nNhap Luong :";
    is >> nv.Luong;
    return is;
   }
   friend ostream& operator<<(ostream& os, NhanVien &nv){
     os<<"\nMa nhan vien:"<<nv.Ma<<endl;
     os<<"\nHo va ten :"<<nv.Ho_Ten<<endl;
     os<<"\nNam Sinh:"<<nv.Nam_Sinh<<endl;
     os<<"\nLuong:"<<nv.Luong<<endl;
     return os;
   }
   int getMa(){
    return Ma;
   } 
};
class  NODE {
    public : 
      NhanVien data;
      NODE *pNext;
    public :
      NODE *KhoiTaoNode(NhanVien &nv){
        NODE *p =new NODE;
        if( p==NULL){
            cout<<"\nKhong khoi tao dc node.";
            exit(1);
        }
         p->data=nv;
         p->pNext=NULL;
         return p;
      }
};
class LIST{
    public :
       NODE *pHead ;
       NODE *pTail;
    public:
       LIST(){
        pHead = nullptr;
        pTail = nullptr;
       }
};

class QuanLiNhanVien {
   private:
     LIST l;
   public :
     void ThemVaoCuoi(NODE *p){
       if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
       } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
      void XoaNhanVien(int maNV) {
        NODE *current = l.pHead;// NODE duyệt từ đầu đến cuối 
        NODE *previous = nullptr;// NODE trước NODE curent

        while (current != nullptr) {
            // Nếu thấy mã giống 
            if (current->data.getMa() == maNV) {
                if (previous == nullptr) {
                    // Xóa nút đầu danh sách
                    l.pHead = current->pNext;// Dịch Node sang một bên 
                } else {
                    // Coi như nó cách ra một ô 
                    previous->pNext = current->pNext;
                }
                delete current;
                return;
            }
            // Cập nhật lại các Node sau khi không tìm thấy data giống 
            previous = current;
            current = current->pNext;
        }
    }
     void InDanhSach() {
      cout<<"\nTHONG TIN NHAN VIEN LA :\n";
        for (NODE *i = l.pHead; i != nullptr; i = i->pNext) {
            cout << i->data << endl;
        }
    }
};
int main() {
    QuanLiNhanVien qlnv;
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
   
    for (int i = 0; i < n; i++) {
        NhanVien nv;
        cin >> nv; // Nhập thông tin nhân viên từ bàn phím
        NODE *node = new NODE;
        node= node->KhoiTaoNode(nv);
        qlnv.ThemVaoCuoi(node);
    }
    // In danh sách nhân viên
    qlnv.InDanhSach();

    int maCanXoa;
    cout << "Nhap ma nhan vien can xoa: ";
    cin >> maCanXoa;
    qlnv.XoaNhanVien(maCanXoa);
    // In danh sách nhân viên sau khi xóa
    qlnv.InDanhSach();
    return 0;
}

/*
                  L.phead …… ......…… NODe xóa ở đây…………………………………..L.pTail 
                  Curent
Previous
                          Previous    Curent
- Nếu data đang ở node đầu tien mà  Node previeous đang trỏ tới nullptr 
+ Cho Node L.pHead dịch sang một Node  :L.pHead =L.pHead ->PNext;
Nếu nó không nằm ở Node đầu (previeous != nulll) 
// 5. Nhập dữ liệu cho danh sách
void NhapList(LIST &l,int x,int n){
 // Khởi tao list cho danh sach 
    KhoiTaoList (l);

    for(int i=0;i<n;i++){
        printf("\nNhap data NODE %d :",i+1);
        scanf("%d",&x);

        NODE *p=TaoNode(x);  // Đưa data vào Node p, tạo ra node p
        Them_Vao_Cuoi(l,p); // Them NODE p vào  cuối danh sách 
    

}

*/