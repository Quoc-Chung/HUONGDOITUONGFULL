// Hãy tạo một lớp Student để quản lý thông tin về điểm của sinh viên gồm có 
// các thành phần riêng tư :
// tên sinh viên (name), 
// điểm toán (mathScore),
// điểm văn (literatureScore) và
// điểm anh văn (englishScore).
// Sau đó, viết một hàm bạn (friend function) có tên calculateAverage để tính điểm trung bình 
// của một sinh viên dựa trên các điểm toán, văn và anh văn. 
#include<bits/stdc++.h>
using namespace std;
class SinhVien{
  private :
     string name;
     float DiemToan;
     float DiemVan;
     float DiemAnh;
  public :
    //Xây dựng hàm khởi tao 
     SinhVien(string name,float DiemToan,float DiemVan,float DiemAnh){
    this->name=name;
    this->DiemToan=DiemToan;
    this->DiemVan=DiemVan;
    this->DiemAnh=DiemAnh;
    }
    friend float calculateAverage(SinhVien &sv); 
};
float calculateAverage(SinhVien &sv){
    return (sv.DiemAnh+sv.DiemToan+sv.DiemAnh) /3;
}
int main(){
   SinhVien sv1("Nguyen Van A", 8.5, 7.9, 9.2);
   SinhVien sv2("Tran Thi B", 7.0, 8.0, 6.5);

    float average1 = calculateAverage(sv1);
    float average2 = calculateAverage(sv2);

    cout << "Diem trung binh cua sinh vien 1: " << average1 << endl;
    cout << "Diem trung binh cua sinh vien 2: " << average2 << endl;

    return 0;
}
