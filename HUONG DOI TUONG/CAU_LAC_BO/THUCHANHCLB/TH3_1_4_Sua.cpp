// TH3.4. Xây dựng lớp SP (Số Phức), gồm các thuộc tính (private): phần thực và phần ảo; các 
// phương thức (public): hàm tạo không đối và hàm tạo có hai đối để tạo và khởi gán số phức, các 
// hàm nhập và xuất một số phức và định nghĩa chồng phép toán ! để tính tổng bình phương của 
// phần thực và phần ảo (ví dụ: nếu z = 3 – 4i thì giá trị !z bằng 25).
// Viết tiếp hàm main( ) trong đó:
// - Nhập hai số phức s1 và s2, trong đó nhập s1 dùng hàm tạo có đối, nhập s2 dùng hàm nhập.
// - Tính tổng s = !s1 + !s2.
// - In các số phức s1, s2 và tổng s ra màn hình (mỗi số in trên một dòng).
#include<bits/stdc++.h>
using namespace std;
class SP {
private:
    float phanThuc;
    float phanAo;
public:
    SP(){
        phanThuc =phanAo =0;
    }
    SP(float phanThuc,float phanAo){
        this->phanThuc = phanThuc;
        this->phanAo = phanAo;
    }
    void nhap() {
        cout<<"Nhap phan thuc: ";
        cin>>phanThuc;
        cout<<"Nhap phan ao: ";
        cin>>phanAo;
    }
    void xuat() {
        cout<<phanThuc<<" + "<<phanAo<<"i"<<endl;
    }
    float operator!(){
        return phanThuc*phanThuc+phanAo*phanAo;
    }
};
int main() {
    SP s1(3,-4);
    SP s2; 
    s2.nhap();
    float tong = !s1 + !s2;
    cout<<"So phuc s1: ";
    s1.xuat();
    cout<<"So phuc s2: ";
    s2.xuat();
    cout<<"Tong binh phuong cua phan thuc va phan ao cua s1 va s2: "<<tong<<endl;
    return 0;
}


