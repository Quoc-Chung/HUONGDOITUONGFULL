#include<bits/stdc++.h>
using namespace std;
class HinhTron{
    private :
       float HoanhDo;
       float TungDo;
       float BanKinh;
    public:
       HinhTron(): HoanhDo(0), TungDo(0), BanKinh(0){}
       HinhTron(float HoangDo, float TungDo, float BanKinh):HoanhDo(HoangDo),TungDo(TungDo), BanKinh(BanKinh){}
       
        float DienTich() {
            return 3.14 * BanKinh * BanKinh;
        }
        float GetBanKinh() {
            return BanKinh;
        }
        float GetHoanhDo() {
            return HoanhDo;
        }
        float GetTungDo() {
            return TungDo;
        }

        void Nhap (){
        cout<<"\nNhap hoang do:";
        cin >> HoanhDo;
        cout <<"\nNhap tung do:";
        cin>>TungDo;
        cout<<"\nNhap ban kinh :";
        cin >> BanKinh;
       }
       friend ostream& operator<<(ostream& os,HinhTron &ht){
        os<<"\nHinh tron co tam :("<<ht.HoanhDo<<" , "<<ht.TungDo<<")";
        os<<"\nBan kinh:"<<ht.BanKinh<<endl;
        return os;
       }

       friend float DienTich(HinhTron &ht){
        return 3.14* ht.BanKinh * ht.BanKinh;
       }
};
class HinhTronMau : public HinhTron {
private:
    string mau;
public:
    HinhTronMau() : mau("") {}
    void NhapMau() {
        cout << "Nhap mau (do, xanh, vang): ";
        cin >> mau;
    }
    void XuatMau() {
        cout << "Mau: " << mau << endl;
    }
    string GetMau() {
        return mau;
    }
};


int main(){
    int n;
    cout <<"\nNhap so luong hinh tron:";
    cin >>n;
    HinhTronMau *htm = new HinhTronMau[n];
    for (int i=0;i<n;i++){
        cout<<"\nNHAP HINH TRON THU "<<i+1 <<":"<<endl;
        htm[i].Nhap();
        htm[i].NhapMau();
    }

    cout <<"\nDANH SACH HINH TRON :"<<endl;
    for (int i=0; i< n;i++){
        cout <<"\nHINH TRON "<< i+1<<" : "<<endl;
        cout<<htm[i];
        htm[i].XuatMau();
    }

        for (int i = 0; i < n; i++){
            for (int j=0;j<n;j++){
                if(DienTich(htm[i]) > DienTich(htm[j])){
                    swap(htm[i],htm[j]);
                }
            }
       }

        cout <<"\nDANH SACH HINH TRON GIAM DAN THEO DIEN TICH :"<<endl;
        for (int i=0; i< n;i++){
        cout <<"\nHINH TRON "<< i+1<<" : "<<endl;
        cout<<htm[i];
        htm[i].XuatMau();
      }

        int  dem =0;
        cout <<"\nDanh sach hinh tron thuoc goc phan tu thu hai :"<<endl;
        for (int i=0;i<n;i++){
            if(htm[i].GetHoanhDo() < 0 && htm[i].GetTungDo()> 0){
                dem++;
                cout<<htm[i]<<endl;
            }
        }
        if(dem==0){
            cout <<"\nKhong co hinh tron nao thuoc goc phan tu thu hai."<<endl;
        }
        else {
            cout <<"\\nSo hinh tron thuoc goc phan tu thu hai la :"<<dem<<endl;
        }
            // Xác định hình tròn màu đỏ có diện tích lớn nhất
        float maxDienTichDo = -1;
        int vitri=0;
        int countXanh = 0, countVang = 0;
        for (int i=0;i<n;i++) {
            if (htm[i].GetMau() == "do" && DienTich(htm[i]) > maxDienTichDo) {
                maxDienTichDo =DienTich(htm[i]) ;
            }
            else if(htm[i].GetMau() == "xanh"){
                 countXanh++;
            }
            else if(htm[i].GetMau() == "vang"){
                countVang++;
            }
        }
       cout << "Hinh tron mau do co dien tich lon nhat: " << htm[vitri]<<endl;
       cout <<"\nDien tich cua hinh tron max do la :"<<maxDienTichDo<<endl;
        if (countXanh > countVang) {
            cout << "So hinh tron mau xanh nhieu hon so hinh tron mau vang." <<endl;
        } else if (countXanh < countVang) {
            cout << "So hinh tron mau xanh it hon so hinh tron mau vang." <<endl;
        } else {
            cout << "So hinh tron mau xanh bang so hinh tron mau vang." <<endl;
        }

        return 0;
}