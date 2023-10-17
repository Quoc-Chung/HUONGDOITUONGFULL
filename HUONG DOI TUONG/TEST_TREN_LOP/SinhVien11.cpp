#include<bits/stdc++.h>

using namespace std;
struct SinhVien{
	string ht; 
	float diem;
};
istream& operator>>(istream &cin, SinhVien &sv){
	cout<<"Nhap ten: ";
	cin.ignore();
	getline(cin, sv.ht);
	do{
		cout<<"Nhap diem: ";
		cin>>sv.diem;
	}while(sv.diem<0.0||sv.diem>10.0);
	return cin;
}
// cái này đúng rồi mà 
ostream &operator<<(ostream &cout, SinhVien &sv){
	cout<<"Ho ten: "<<sv.ht<<"--------Diem: "<<sv.diem<<endl;
	return cout;
}

// này là m sắp xếp nó tăng dần   giảm dần là nếu điểm a nhỏ hơn điểm b thì tráo a với b để đẩy b về cuối 
bool operator>(SinhVien &sv1, SinhVien &sv2){
	bool X;
	X=(sv1.diem <sv2.diem)?true:false;
	return X;
}
void SapXep(int n, SinhVien *sv) {
    // nãy m duyệt đến n-i thôi mà lại so sánh j+1 làm nó bị tràn 
    for (int i = 0; i < n - 1; i++) { 
        for (int j = 0; j < n - i - 1; j++) { 
            if (sv[j] > sv[j + 1]) {
                swap(sv[j], sv[j + 1]);
            }
        }
    }
}
int main(){
	int n; 
    cout<<"\nNhap n :";
    cin>>n;
    // chỗ này  cần cấp phát nè 
	SinhVien *sv = new SinhVien[n];
    // kiểm tra cấp phát được chưa  này 
    if(sv==NULL){
        cout<<"\nKhhong cap phat duoc.";
        exit(1) ;
    } 
    for(int i=0;i<n;i++){
        cin>>sv[i];
    }
    for(int i=0;i<n;i++){
        cout<<sv[i]<<endl;
    }
	cout<<"Danh sach sinh vien co diem giam dan: "<<endl;
	SapXep(n, sv);
	for(int i=0;i<n;i++){
        cout<<sv[i]<<endl;
    }
}
