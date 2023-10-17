// Xây dựng lớp quản lý một danh sách nhân viên của một công ty bằng danh sách liên kết đơn
//  (giả sử các lớp tạo danh sách liên kết đơn đã có), có các phương thức sau:
// Tạo 1 danh sách có n nhân viên, các nhân viên lần lượt được thêm vào cuối danh sách.
// Xóa một nhân viên có mã là x, x được nhập từ bàn phím.
// In danh sách các nhân viên có lương lớn hơn 2.000.000 lên màn hình.
#include <bits/stdc++.h>
using namespace std;
class NhanVien {
private:
    int MaNhanVien;
    string HoTen;
    int NamSinh;
    string GioiTinh;
    long long Luong;
public:
    NhanVien() {
        MaNhanVien = NamSinh = Luong = 0;
        HoTen = GioiTinh = "";
    }
    friend istream &operator>>(istream &is, NhanVien &nv) {
        cout << "Nhap ma nhan vien: ";
        is >> nv.MaNhanVien;
        is.ignore();
        cout << "Nhap ho ten : ";
        getline(is, nv.HoTen);
        cout << "Nhap nam sinh : ";
        is >> nv.NamSinh;
        cin.ignore();
        cout << "Nhap gioi tinh: ";
        getline(is, nv.GioiTinh);
        cout << "Nhap Luong: ";
        is >> nv.Luong;
        return is;
    }
    friend ostream &operator<<(ostream &os, NhanVien &nv) {
        os << nv.MaNhanVien << " " << nv.HoTen << " " << nv.NamSinh << " " << nv.GioiTinh << " " << nv.Luong << endl;
        return os;
    }
   int getMaNhanVien(){
    return MaNhanVien;
   }
   long long getLuong(){
    return Luong;
   }
};
struct Node {
    NhanVien nv;
    Node *pNext;
};
struct List {
    Node *pHead;
    Node *pTail;
};
void KhoiTaoList(List &l) {
    l.pHead = l.pTail = NULL;
}
Node *KhoiTaoNode(NhanVien &nv) {
    Node *p = new Node;
    if (p == NULL) {
        cout << "Cap phat bo nho that bai!" << endl;
        return NULL;
    }
    p->nv = nv;
    p->pNext = NULL;
    return p;
}
void ThemNodeVaoDau(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void ThemNodeVaoCuoi(List &l, Node *p) {
    if (l.pHead == NULL) {
        l.pHead = l.pTail = p;
    } else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void XoaNodeDau(List &l) {
    if (l.pHead == NULL) {
        return;
    }
    Node *p = l.pHead;
    l.pHead = l.pHead->pNext;
    delete p;
}
void XoaNodeSauQ(List &l, Node *q) {
    if (q != NULL && q->pNext != NULL) {
        Node *p = q->pNext;
        q->pNext = p->pNext;
        delete p;
    }
}
void XoaNodeCoKhoaX(List &l, int x) {
    if (l.pHead == NULL) {
        return;
    }
    if (l.pHead->nv.getMaNhanVien() == x) {
        XoaNodeDau(l);
        return;
    }
    for (Node *k = l.pHead; k != NULL; k = k->pNext) {
        if (k->pNext != NULL && k->pNext->nv.getMaNhanVien() == x) {
            XoaNodeSauQ(l, k);
            return;
        }
    }
}
void InDanhSachLuongCaoHon2M(List &l) {
    for (Node *p = l.pHead; p != NULL; p = p->pNext) {
        if (p->nv.getLuong() > 2000000) {
            cout << p->nv;
        }
    }
}
int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    List l;
    KhoiTaoList(l);

    for (int i = 0; i < n; i++) {
        NhanVien nv;
        cout << "Nhap thong tin nhan vien thu " << i + 1 << endl;
        cin >> nv;
        Node *p = KhoiTaoNode(nv);
        ThemNodeVaoCuoi(l, p);
    }

    cout << "Danh sach nhan vien co luong > 2.000.000:" << endl;
    InDanhSachLuongCaoHon2M(l);

    return 0;
}
