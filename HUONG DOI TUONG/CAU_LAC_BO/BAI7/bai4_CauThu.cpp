// Xây dựng lớp Nguoi:
//  Thuộc tính (private): họ tên, tuổi
//  Phương thức: nhập, xuất, các phương thức khác
// Xây dựng lớp Cauthu dẫn xuất của lớp Nguoi, trong đó bổ sung thêm 
// các thuộc tính (private): sbt (số bàn thắng), sptd (số phút thi đấu).
// Viết hàm main() thực hiện:
//  Nhập n cầu thủ.
//  Tìm cầu thủ lớn tuổi nhất.
//  Xác định số tiền thưởng của từng cầu thủ biết rằng cầu thủ thi đấu 
// tổng cộng trên 300 phút thì được thưởng 10 triệu, và cứ ghi được 1 
// bàn thắng thì được thưởng thêm 5 triệu đồng.
#include<bits/stdc++.h>
using namespace std;
class Nguoi{
  private:
    string HoTen;
    int Tuoi;
  public :
  string getHoTen(){
    return HoTen;
  }
   int getTuoi(){
    return Tuoi;
   }
    Nguoi(){
        HoTen = "";
        Tuoi = 0;
    }
    void Nhap(){
        cout<<"\nNhap Ho Ten:";
        cin.ignore();
        getline(cin, HoTen);
        cout<<"\nNhap Tuoi:";
        cin>>Tuoi;
    }
    void Xuat(){
        cout<<"\nHo va ten :"<<HoTen<<" - "<<"Tuoi :"<<Tuoi<<endl;
    }
};
class CauThu :public Nguoi{
   private:
     int SoBanThang;
     int SoPhutThiDau;
  public :
     CauThu(){
        SoBanThang =SoPhutThiDau =0;
     }
     int getSoBanThang(){
        return SoBanThang;
     }
     int getSoPhutThiDau(){
        return SoPhutThiDau;
     }
     void Nhap(){
        Nguoi::Nhap();
        cout<<"\nNhap so ban thang:";
        cin >> SoBanThang;
        cout<<"\nNhap so phut thi dau:";
        cin >> SoPhutThiDau;
     }
     void Xuat(){
        Nguoi::Xuat();
        cout<<"\nSo ban thang:"<<SoBanThang<<" - "<<"SoPhutThiDau"<<SoPhutThiDau<<endl;
     }  
     int TinhTienThuong() {
        int TienThuong = 0;
        if (SoPhutThiDau > 300) {
            TienThuong += 10000000;
        }
        TienThuong += SoBanThang * 5000000;
        return TienThuong;
    }
};
int main() {
    int n;
    cout << "\nNhap so cau thu: ";
    cin >> n;
    CauThu *ct = new CauThu[n];
    // Nhập thông tin cho n cầu thủ
    for (int i = 0; i < n; i++) {
        ct[i].Nhap();
    }
    // Tìm cầu thủ lớn tuổi nhất
    int maxTuoi = ct[0].getTuoi();
    int i = 0;
    for (int k = 1; k < n; k++) {
        if (ct[k].getTuoi() > maxTuoi) {
            maxTuoi = ct[k].getTuoi();
            i=k;
        }
    }
    cout << "\nCau thu lon tuoi nhat la:\n";
    cout << "Ten: " << ct[i].getHoTen() << endl;
    cout << "Tuoi: " << ct[i].getTuoi() << endl;
    cout << "So phut thi dau: " << ct[i].getSoPhutThiDau() << endl;
    cout << "So ban thang: " << ct[i].getSoBanThang() << endl;
    // Tính và hiển thị số tiền thưởng của từng cầu thủ
    cout << "\nSo tien thuong cua tung cau thu:\n";
    for (int i = 0; i < n; i++){
        int tienThuong = ct[i].TinhTienThuong();
        cout << "Ten: " << ct[i].getHoTen()<< ", Tien thuong: " << tienThuong << " VND" << endl;
    }
    delete[] ct; // Giải phóng bộ nhớ sau khi sử dụng mảng động
    return 0;
}