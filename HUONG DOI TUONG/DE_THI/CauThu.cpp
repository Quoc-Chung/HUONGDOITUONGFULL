#include<bits/stdc++.h>
using namespace std;
// Xây dựng lớp người  
class Nguoi{
  private:
    string HoTen;
    int Tuoi;
  public:
  // Láy ra các thuộc  tính  private để sử dụng ở class Cầu Thủ 
    int getTuoi(){
        return Tuoi;
    }
    string getHoTen(){
        return HoTen;
    }
    // Xây dựng hàm nhập riêng của lớp  Người để tí gọi vào hàm  nhập  của lớp Cầu Thủ 
    void Nhap(){
        cin.ignore();// Xóa sạch bộ nhớ đệm  
        cout << "\nNhap Ho Ten :";
        getline(cin, HoTen);
        cout << "\nNhap Tuoi :";
        cin >> Tuoi;
    }
    void Xuat(){
        cout << "\nHo Ten : " << HoTen << "---" << "Tuoi : " << Tuoi;
    }
};
// Xây dựng  lớp  Cầu Thủ Kế thưa từ lớp Người 
class CauThu : public Nguoi{
    private:
        int SBT; // Số bàn thắng 
        int PhutThiDau;
    public:
        void Nhap(){
            Nguoi::Nhap();//Gọi lại hàm nhập của lớp Người  
            cout << "\nNhap So Ban Thang :";
            cin >> SBT;
            cout << "\nNhap So Phut Thi Dau:";
            cin >> PhutThiDau;
        }
        void Xuat(){
            Nguoi::Xuat(); // Gọi lại hàm xuất của lơp Người
            cout << "--- So Ban Thang : " << SBT << "---" << "So Phut Thi Dau:" << PhutThiDau << endl;
        }
        void CauThuLonTuoiNhat(CauThu *ds,int  n){
            int max=0;
            string HoTen1;
           for (int i=0;i<n;i++){
            if(max<ds[i].getTuoi()){
               max=ds[i].getTuoi();
               HoTen1=ds[i].getHoTen();
            }
           }
           cout <<"\nCau thu lon tuoi nhat la :"<<HoTen1<<endl;
        }
        void TienThuongTungCauThu(CauThu *ds,int n){
            for (int i=0;i<n;i++){
             int tienThuong = 0;
            if(ds[i].PhutThiDau > 300){
                tienThuong += 10000000;
            }
            tienThuong += ds[i].SBT * 5000000;
            cout << "Tien thuong cua " << ds[i].getHoTen() << " la: " << tienThuong << " VND" << endl;
            }
            
        }
};
int main(){
    int n;
    cout << "Nhap so luong cau thu: ";
    cin >> n;
    // Khởi tạo  bài mẫu  cầu thủ 
    CauThu* dsCauThu = new CauThu[n];
    for(int i = 0; i < n; i++){
        cout << "\nNhap thong tin cho cau thu thu " << i + 1 << ":" << endl;
        dsCauThu[i].Nhap();
    }
    cout << "\nThong tin cac cau thu:" << endl;
    for(int i = 0; i < n; i++){
        dsCauThu[i].Xuat();
    }
    // Tìm và hiển thị thông tin cau thu lon tuoi nhat
    cout << "\nTong so cau thu: " << n << endl;
    dsCauThu[0].CauThuLonTuoiNhat(dsCauThu,n);
    // Tien thuong cua tung cau thu
        dsCauThu[0].TienThuongTungCauThu(dsCauThu,n);
    delete[] dsCauThu;
    return 0;
}
