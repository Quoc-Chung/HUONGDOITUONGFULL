#include<bits/stdc++.h>
#include <vector>
#include <string>
using namespace std;

class SinhVien {
private:
    string ht;
    float diem;
    int ma;

public:
     float getdiem(){
		return diem;
	 }
    SinhVien() {}
    SinhVien(string &ht, float diem, int ma) : ht(ht), diem(diem), ma(ma) {}
		friend istream & operator >>(istream &cin, SinhVien &sv){
			cout<<"Nhap ten: ";
			cin.ignore();
			getline(cin, sv.ht);
			do{
				cout<<"Nhap diem: ";
			cin>>sv.diem;
			}while(sv.diem<0||sv.diem>10);
			cout<<"Nhap ma sinh vien: ";
			cin>>sv.ma;
			return cin;
		}
		friend ostream &operator <<(ostream &cout, SinhVien &sv){
			cout<<" --Ten: "<<sv.ht<<" --Diem: "<<sv.diem<<" --Ma Sinh Vien: "<<sv.ma<<endl;
			return cout;
		}
		
};
class DanhSach{
	private:
		vector<SinhVien> danhsach;
	public:
		void nhap(int &n){
			danhsach.clear();
			for(int i=0; i<n; i++){
				SinhVien sv;
				cin>>sv;
				danhsach.push_back(sv);
			}
		}
		void TimDiemCao() {
			if(danhsach.empty()){
				cout<<"Danh sach rong"<<endl;
				return ;
			}
			float diemmax=0;
			for(int i=0; i< danhsach.size(); i++){
				if(diemmax<=danhsach[i].getdiem()){
					diemmax=danhsach[i].getdiem();
				}
			}
        }
       
};
int main(){
	DanhSach danhsach;
    int n;
    cout << "Nhap so luong sinh vien: ";
    cin >> n;
    danhsach.nhap(n);
    danhsach.TimDiemCao();
    
}