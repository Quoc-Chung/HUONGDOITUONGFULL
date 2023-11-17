#include<bits/stdc++.h>
using namespace std;
class  Nguoi {
    private:
       string HoTen;
       int NamSinh;
    public:
        int getNamSinh(){
            return NamSinh;
        }
       Nguoi(): HoTen(""),NamSinh(0) {}
       void Nhap (){
        cout<<"\nNhap Ho Ten:";
        cin.ignore();
        getline(cin, HoTen);
        cout <<"\nNhap Nam Sinh:";
        cin >> NamSinh;
       }
       void Xuat(){
        cout<<"\nHo va ten :"<<HoTen;
        cout<<"\nNam sinh :"<< NamSinh;
       }
};
class BenhNhan:public Nguoi{
    private:
       char  Benh;
    public:
        BenhNhan (): Benh(' '){}
        void Nhap(){
            Nguoi::Nhap();
            cout<<"\nNhap benh :";
            cin >> Benh;
        }
        void Xuat(){
            Nguoi::Xuat();
            cout<<"\nBenh :"<<Benh;
        }
        void NhapNhieu(BenhNhan *bn,int n){
            for(int i=0;i<n;i++){
                cout<<"\nNhap benh nhan thu "<<i+1<<" :"<<endl;
                bn[i].Nhap();
            }
        }
        void XuatNhieu(BenhNhan *bn,int n){
            for (int  i =0; i<n; i++){
                 cout <<"\nBanh nhan thu nhat la :"<<i+1<<":"<<endl;
                 bn[i].Xuat();
            }
           
        }
            
        void Thongke(BenhNhan *bn, int n) {
            int d1 = 0,d2 = 0,d3 = 0,d4 = 0;
            for (int i =0;i<n;i++) {
                if (bn[i].Benh =='A' || bn[i].Benh=='a') d1++;
                else if (bn[i].Benh == 'B' || bn[i].Benh == 'b') d2++;
                else if (bn[i].Benh == 'C' || bn[i].Benh == 'c') d3++;
                else if(bn[i].Benh == 'D' || bn[i].Benh == 'd') d4++;
            }
            cout << "Du lieu can tim la:" << endl;
            cout << "Co " << d1 << " benh nhan mac benh A" << endl;
            cout << "Co " << d2 << " benh nhan mac benh B" << endl;
            cout << "Co " << d3 << " benh nhan mac benh C" << endl;
            cout << "Co " << d4 << " benh nhan mac benh D" << endl;
        }

        void Tim(BenhNhan *bn, int n) {
            int max = INT_MIN;
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (bn[i].Benh == 'D' || bn[i].Benh =='d') {
                    found = true;
                    if (bn[i].getNamSinh() > max) max = bn[i].getNamSinh();
                }
            }
            if (found) {
                cout << "Benh nhan can tim la:" << endl;
                for (int i = 0; i < n; i++) {
                    if (bn[i].getNamSinh() == max) bn[i].Xuat();
                }
            } else {
                cout << "Khong tim thay benh nhan nao mac benh D." << endl;
            }
        }
};
int main(){
    int n;
    cout <<"\nNhap so benh nhan :";
    cin >> n;
    BenhNhan *bn = new BenhNhan[n];
    if( bn == NULL){
        cout <<"\nKhoi tao loi."<<endl;
        exit(1);
    }
    bn[0].NhapNhieu(bn,n);
    bn[0].XuatNhieu(bn,n);
    bn[0].Thongke(bn,n);
    bn[0].Tim(bn,n);
    return 0;

}