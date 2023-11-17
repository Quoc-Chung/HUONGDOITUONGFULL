#include<bits/stdc++.h>
using namespace std;
class Elip{
	private:
		float a,b;
	public:
		Elip(): a(0),b(0) {}
	    void Nhap(){
	    	cout<<"\nNhap hai ban kinh:";
	    	cin >> a>> b;
	    }
	    void Xuat(){
	    	cout <<"\nBan kinh :"<<"("<< a<<" , "<<b<<")"<<endl;
	    }
	    void NhapNhieuElip(Elip *e,int n){
	    	for(int i=0;i<n;i++){
	    		cout<<"\nNhap thong tin elip "<<i<<":"<<endl;
	    		e[i].Nhap();
				}
		}
		void XuatNhieuElip(Elip *e ,int n){
		cout <<"\nXUAT ELIP "<<endl;
		for (int i=0;i<n;i++){
	    cout <<"\nElip thu "<<i+1<<":"<<endl;
		e[i].Xuat() ;
		  }
		} 
	    void KiemTraTangGiam(Elip *e, int n) {
	    bool check1 = true, check2 = true;
	    for (int i = 0; i < n - 1; i++) {
	        if (e[i].a > e[i + 1].a) {
	            check1 = false;
	        }
	        if (e[i].b > e[i + 1].b) {
	            check2 = false;
	        }
	    }
	    if (check1 && check2) {
	        cout << "\nDay tang dan theo a va b"<<endl;
	    } else {
	        cout << "\nDay khong thoa man dieu kien de bai."<<endl;
	    }
	}
	
void DienTichMax(Elip *e, int n) {
    float epsilon = 0.001;  
    float DienTichMax = 0;
    bool check = false;
    for (int i = 0; i < n; i++) {
        float dt = 3.14 * e[i].a * e[i].b;
        if (dt > DienTichMax) {
            DienTichMax = dt;
            check = true;
        }
    }
    if (check) {
        cout << "\n Cac hinh elip co dien tich max la: " << endl;
        for (int i = 0; i < n; i++) {
            float dt = 3.14 * e[i].a * e[i].b;
            if (abs(dt - DienTichMax) < epsilon) {  // So sanh sai so trong qua trinh tinh toan 
                cout << "\nHinh tron o vi tri " << i << endl;
                e[i].Xuat();
            }
        }
    } else {
        cout << "\nKhong ton tai elip hinh tron." << endl;
    }
}


};
int main (){
	 int n;
	 cout<<"\nNhap so duong elip :";
	 cin >>n;
	 Elip *e = new Elip[n];
	 if(e==NULL){
	 	cout <<"\nKhong the mo duoc."<<endl;
	 	exit(1);
	}
	e[0].NhapNhieuElip(e,n);
	e[0].XuatNhieuElip(e,n);
	e[0].DienTichMax(e,n);
	e[0].KiemTraTangGiam(e,n);
	}
	

