// Xây dựng lớp Điểm, gồm:
//  Dữ liệu (private): hoành độ, tung độ
//  Các phương thức (public): 
// o Nhập điểm, Xuất điểm ra màn hình theo dạng (hoành độ, tung độ)
// o Tính khoảng cách giữa hai điểm
// Xây dựng hàm main():
//  Nhập tọa độ ba điểm và tính diện tích của tam giác có các đỉnh là ba 
// điểm trên.
//  Nhập tọa độ của n điểm và tính độ dài đường gấp khúc lần lượt đi qua 
// các điểm 1, 2, 3,…, n-1, n.
#include<bits/stdc++.h>
using namespace std;
class  {
    private : 
    float HoanhDo;
    float TungDo ;
    public  :
      (){
       HoanhDo = TungDo =0; 
      }
      float getHoanhDo(){
        return HoanhDo;
      }
      float getTungDo(){
        return TungDo;
      }

      void Nhap1 ();
      void In1();
      //float TinhKhoangCach( D1 , D2);
      float TinhKhoangCach( D2);
      
};
void ::Nhap1() {
    cout<<"\nNhap hoanh do :";
    cin >> HoanhDo ;
    cout<<"\nNhap tung do :";
    cin >> TungDo ;  
}
void ::In1(){
    cout<<"\n la :"<<"("<<HoanhDo<<","<< TungDo <<")"<<endl;
}
float ::TinhKhoangCach( D2) {
    // Sử dụng công thức khoảng cách Euclid để tính
     D1=*this;
    float khoangCach = sqrt(pow(D2.HoanhDo - D1.HoanhDo, 2) + pow(D2.TungDo - D1.TungDo, 2));
    return khoangCach;
}
void DienTichTamGiac( D1,  D2,  D3) {
    float AB = D1.TinhKhoangCach(D2);
    float BC = D2.TinhKhoangCach(D3);
    float CA = D3.TinhKhoangCach(D1);
    if (AB + BC > CA && AB + CA > BC && BC + CA > AB) {
        // Kiểm tra tính đúng đắn của tam giác
        float p = (AB + BC + CA) / 2; 
        float S = sqrt(p * (p - AB) * (p - BC) * (p - CA));  
        cout << "Dien tich tam giac ABC: " << fixed << setprecision(2) << S << endl;
    } else {
        cout << "Ba  khong tao thanh mot tam giac hop le." << endl;
    }
}
void DuongGapKhuc( *d,int n){
    float dodai =0;
    for (int i=0;i<n-1;i++){
     dodai += d[i].TinhKhoangCach(d[i+1]);
    }
    cout<<"\nDo dai duong gap khuc :"<<dodai<<endl;
}
int main(){
     D1,D2,D3;
    cout<<"\nNhap  1:";
    D1.Nhap1();
    cout<<"\nNhap  2:";
    D2.Nhap1();
    cout<<"\nNhap  3:";
    D3.Nhap1();
    DienTichTamGiac(D1,D2,D3);

    int n;
    cout<<"\nNhap n:";
    cin >>n;
     *d= new [n];
    if(d==NULL) exit(1);
    for(int i=0;i<n;i++){
        d[i].Nhap1();
    }
    DuongGapKhuc(d,n);
    return 0;
}
