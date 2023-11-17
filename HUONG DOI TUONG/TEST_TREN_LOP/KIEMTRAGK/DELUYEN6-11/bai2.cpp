#include<bits/stdc++.h>
using namespace std;
class Nguoi{
     private:
    string HoTen;
    int Ma, NamSinh, gt;
    public:
        Nguoi(string HoTen = " ", int Ma = 0 , int NamSinh = 2000, int gt = 0){
            this->HoTen = HoTen;
            this->Ma = Ma;
            this->NamSinh = NamSinh;
            this->gt = gt;
        }
        void Nhap(){
            cout<<"Nhap ho ten:";cin.ignore();getline(cin, HoTen);
            cout<<"Nhap Ma:";cin>>Ma;
            cout<<"Nhap nam sinh:";cin>>NamSinh;
            do{
                cout<<"Nhap gioi tinh (0:nam, 1: nu):";cin>>gt;
            }while(gt!=0&& gt!=1);
        }
        void Xuat(){
            cout<<"Ho ten:"<<HoTen<<" - Ma:"<<Ma<<" - Nam sinh:"<<NamSinh<<" - Gioi tinh:"<<gt;
        }
        int getNamSinh(){
            return NamSinh;
        }
        int getGioiTinh(){
            return gt;
        }
};
class HocVien:public Nguoi{
    private:
    int sogio, sotuongtac;
    public:
        HocVien(string HoTen = " ", int Ma = 0 , int NamSinh = 2000, int gt = 0, int sogio = 0, int sotuongtac = 0)
            :Nguoi(HoTen,Ma,NamSinh,gt){
                this->sogio = sogio;
                this->sotuongtac = sotuongtac;
            }
        void Nhap(){
            Nguoi::Nhap();
            cout<<"Nhap so gio hoc:";cin>>sogio;
            cout<<"Nhap so tuong tac:";cin>>sotuongtac;
        }
        void Xuat(){
            Nguoi::Xuat();
            cout<<" - So gio:"<<sogio<<" - So tuong tac:"<<sotuongtac<<endl;
        }

        int getThoiGian(){
            return sogio;
        }

        int getTuongTac(){
            return sotuongtac;
        }
};
class UngDung{
    int n;
    HocVien *a;
    public:
        void Nhap(){
            cout<<"Nhap n:";cin>>n;
            a = new HocVien[n];
            for(int i = 0;i<n;i++)
                a[i].Nhap();
        }
        void Xuat(){
            cout<<"Danh sach hoc vien:"<<endl;
            for(int i = 0 ;i<n;i++)
                a[i].Xuat();
        }
        void ThanhVienTreNhat(){
            int Max = 0;
            for(int i = 0;i<n;i++)
                if(Max < a[i].getNamSinh()) Max = a[i].getNamSinh();
            cout<<"Nhung nhan vien tre nhat:"<<endl;
            for(int i = 0;i<n;i++)
                if(a[i].getNamSinh()==Max)
                    a[i].Xuat();
        }
        void SapXepTangDan(){
            for(int i = 0;i<n-1;i++)
                for(int j = i+1;j<n;j++)
                    if(a[i].getThoiGian() > a[j].getThoiGian())
                        {
                            HocVien tg;
                            tg = a[i];
                            a[i] = a[j];
                            a[j] = tg;
                        }
        }
        void TuongTacNhieuNhat(){
            int Max = 0;
            for(int i = 0;i<n;i++)
                if(a[i].getGioiTinh() ==1 &&a[i].getTuongTac() > Max){
                    Max = a[i].getTuongTac();
                }
                cout<<"Hoc vien nu co so tuong tac nhieu nhat:"<<endl;
            for(int i = 0;i<n;i++)
                if(a[i].getGioiTinh() == 1 && a[i].getTuongTac() == Max)
                    a[i].Xuat();
        }
};
int Main(){
    UngDung ud;
    ud.Nhap();
    ud.ThanhVienTreNhat();
    ud.SapXepTangDan();
    ud.Xuat();
    ud.TuongTacNhieuNhat();
}



