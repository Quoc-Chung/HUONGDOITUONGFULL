// 1. Xây dựng lớp SP (số phức)
//  Dữ liệu (private): phần thực, phần ảo
//  Các phương thức toán tử (public): + để cộng 2 số phức
//  Toán tử >> để nhập điểm
//  Toán tử << để xuất điểm ra màn hình
//  Toán tử gán
#include<bits/stdc++.h>
using namespace std;
class SP {
    private :
      float thuc,ao ;
    public :
       SP(){
        thuc = ao = 0 ;
       }
    friend istream& operator>>(istream& is, SP &sp){
        cout<<"\nNhap phan thuc:";
        is>>sp.thuc;
        cout<<"\nNhap phan ao :";
        is>>sp.ao;
        return is;
    }
   friend ostream& operator<<(ostream& os, SP &sp){
        if(sp.ao > 0){
             cout<<sp.thuc <<"+"<<sp.ao<<"i"<<endl;
        }
        else{
             cout<<sp.thuc <<" "<<sp.ao<<"i"<<endl;
        }
        return os;
     }
    SP operator+(SP &sp2){
       SP result ;
       result.thuc = thuc + sp2.thuc;
       result.ao = ao + sp2.ao ;
       return result ;
    }
    // Sử dụng toán tử gán phải tránh đói tượng gốc bị thay đổi 
     SP& operator=(const SP& sp) {
        this->thuc = sp.thuc;
        this->ao = sp.ao;
        return *this;
    }        
};
int main() {
    SP sp1, sp2, sp3;  
    cout<< "Nhap so phuc 1:" << endl;
    cin >> sp1; 
    cout<< "Nhap so phuc 2:" << endl;
    cin >> sp2;
    sp3 = sp1 + sp2; // Cộng hai số phức
    cout<< "Tong hai so phuc la: " << sp3 << endl;
    return 0;
}

