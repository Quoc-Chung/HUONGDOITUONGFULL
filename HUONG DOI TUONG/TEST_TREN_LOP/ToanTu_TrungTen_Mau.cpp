#include<bits/stdc++.h>
using namespace std;
//Khai báo cấu trúc sinh viên
struct SinhVien{
    string HoTen;
    int SBD;
    float Diem;
};
//Khai báo cấu trúc nhân viên
struct NhanVien{
    string TenNhanVien;
    int MaNV;
    float TienLuong;
};
// Khởi tạo hàm Mau dùng cho cả ba trường 
template <class T> void Nhap(const string& ThongBao,int &n, T *&a){
    cout<<"\nNhap n:";
    cin>>n;
    cout<<ThongBao<<endl;
    //Cap phat dong cho bien con tro mau
    a=new T[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
}
// Hàm in dùng cho mọi trường hợp :*sv chỉ là đại diện thôi
// HÀm mẫu này truyền  &n để nó lấy được giá trị của n ở trong Hàm Mẫu nhập 
//Nếu nhập ở trong hàm main thì không cần truyền tham chiếu 
template <class X> void InDS(const int &n,X *sv){
	for(int i=0; i<n; i++){
		cout<<sv[i]<<endl;
	}
}
template <class X> void TBC(const int n, X * tmp){
    float TB =0;
    for (int i=0;i<n;i++){
        TB+=tmp[i];
    }
    cout<<"\nTrung binh cong cua day vua nhap la :"<<fixed << setprecision(2)<<(float)TB/n<<endl;
}
// Nạp  chồng toán tử nhập cho mảng cấu trúc
// Hàm này chỉ trả về 1 sinh viên duy nhất 
istream& operator>> (istream &is ,SinhVien &sv){
   	cout<<"Nhap ten: ";
		is.ignore();
		getline(is, sv.HoTen);
		do{
		cout<<"Nhap so bao danh:  ";
		is>>sv.SBD;
	    }while(sv.SBD<0);
		do{
			cout<<"Nhap diem: ";
			is>>sv.Diem;
		}while(sv.Diem <0.0||sv.Diem>10.0);

    return is;
}
// Nạp  chồng toán tử xuất cho mảng cấu trúc
// HÀm này chỉ xuất một SinhVien
ostream&  operator<<(ostream& os, const SinhVien &sv){
    cout<<"HoTen: "<<sv.HoTen<<endl;
    cout<<"SBD: "<<sv.SBD<<endl;
    cout<<"Diem: "<<sv.Diem<<endl;
    return os;
}
// Nạp  chồng toán tử nhập NhanVien
istream&  operator>> (istream &is ,NhanVien &nv){
       is.ignore();
       cout<<"Nhap ten: ";
        getline(is, nv.TenNhanVien);
        do{
        cout<<"Nhap so bao danh:  ";
        is>>nv.MaNV;
        }while(nv.MaNV<0);
            cout<<"Nhap tien luong: ";
            is>>nv.TienLuong;
    return is;
}
// Nạp  chồng toán tử xuất NhanVien 
ostream& operator<<(ostream &os ,const NhanVien &nv){
    cout<<"TenNhanVien: "<<nv.TenNhanVien<<endl;
    cout<<"MaNV: "<<nv.MaNV<<endl;
    cout<<"TienLuong: "<<nv.TienLuong<<endl;
    return os;
}
int main(){
  int *a;
  NhanVien *nv;
  SinhVien *sv;
  int n;
  Nhap("Nhap mang so nguyen :", n,a);
  InDS(n,a);
  TBC(n,a);
  Nhap("Nhap Danh Sach Nhan Vien",n,nv);
   float *luong = new float[n];
    for (int i = 0; i < n; i++) {
        luong[i] = nv[i].TienLuong;
    }
  InDS(n,nv);
  TBC(n,luong);
  Nhap("Nhap Danh Sach Sinh Vien ",n,sv);
  float *diem = new float[n];
  for (int i = 0; i < n; i++) {
        diem[i] = sv[i].Diem;
    }
  InDS(n,sv);
  TBC(n,diem);

  //Xây dựng các hàm giải  phóng 
  delete[] a;
  delete[] nv;
  delete[] sv;
  delete[] diem;
  delete[] luong;

  return 0;
}