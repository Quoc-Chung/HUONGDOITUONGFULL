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
        virtual void Nhap (){
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
        virtual void Xuat(){
        cout<<"\nHinh tron co tam :("<<HoanhDo<<" , "<<TungDo<<")";
        cout<<"\nBan kinh:"<<BanKinh<<endl;
       }
       friend float DienTich(HinhTron &ht){
        return 3.14* ht.BanKinh * ht.BanKinh;
       }
       void NhapHinhTron(HinhTron *ht,int n){
        cout <<"\nNHAP HINH TRON:"<<endl;
        for(int i=0;i<n;i++){
            cout<<"\nNHAP HINH TRON THU "<<i <<":"<<endl;
             ht[i].Nhap();
       }
       }

       void XuatHinhTron(HinhTron *ht,int n){
         for (int i = 0; i < n; i++){
            cout<<ht[i];
         }
       }
       void SapXepGiamDan(HinhTron *ht,int n){
        for (int i = 0; i < n; i++){
            for (int j=0;j<n;j++){
                if(DienTich(ht[i]) < DienTich(ht[j])){
                    swap(ht[i],ht[j]);
                }
            }
       }
       cout<<"\nDanh sach hinh tron giam dan theo dien tich :";
       XuatHinhTron(ht,n);
       }
       void HinhTronThuocGoc2(HinhTron *ht ,int n){
        int  dem =0;
        cout <<"\nDanh sach hinh tron thuoc goc phan tu thu hai :"<<endl;
        for (int i=0;i<n;i++){
            if(ht[i].HoanhDo < 0 && ht[i].TungDo > 0){
                dem++;
                cout<<ht[i]<<endl;
            }
        }
        if(dem==0){
            cout <<"\nKhong co hinh tron nao thuoc goc phan tu thu hai."<<endl;
        }
        else {
            cout <<"\\nSo hinh tron thuoc goc phan tu thu hai la :"<<dem<<endl;
        }
       }
};
class Children_HinhTron : public HinhTron{
    private : 
       string mau;
    public :
       Children_HinhTron() : mau(""){}
       void Nhap() override {
        // Ghi đè phương thức Nhap
        HinhTron::Nhap();
        cout << "\nNhap mau: ";
        cin.ignore();
        getline(cin, mau);
    }
       void Xuat() override{
            HinhTron::Xuat();
            cout<<"\nMau la :"<<mau<<endl;
       }

       void TimDiemDoCoDienTichMax(Children_HinhTron * cht,int n){
        float max =0;
        int vitri;
        int xanh=0,vang =0;
        for(int i=0;i<n;i++){
            if(cht[i].mau =="do" && max < DienTich(cht[i]) ){
                max  = DienTich(cht[i]);
                vitri = i;
            } 
            else if(cht[i].mau =="xanh"){
                xanh++;
            }
            else if(cht[i].mau =="vang"){
                vang++;
            }
        }
        cout <<"\nHinh Tron mau do co dien tich max  la : "<< cht[vitri];
        cout <<"\nDien tich cua hinh tron la :"<<max <<endl;
        if(xanh < vang){
        cout <<"\nSo hinh tron mau xanh it hon so hinh tron mau vang"<<endl;
       }
        else if(xanh > vang){
        cout <<"\nSo hinh tron mau xanh nhieu hon so hinh tron mau vang"<<endl;
       }
        else{
        cout<<"\nSo hinh tron mau xanh = so hinh tron mau vang"<<endl;
       }
       }
};
int main(){
    // ĐỊT  CỤ CÁI BÀI  L 
}