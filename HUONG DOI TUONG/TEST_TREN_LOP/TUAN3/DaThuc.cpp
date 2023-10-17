#include<bits/stdc++.h>
using namespace std;
class DaThuc {
protected:
    int bac;        // Bậc của đa thức
   float* heSo;   // Mảng lưu trữ các hệ số của đa thức
public:
    // Constructor để khởi tạo đa thức với bậc và các hệ số ban đầu
    DaThuc(int n=0) : bac(n) {
        heSo = new float[n + 1]; // Mảng có kích thước bậc + 1
        for (int i = 0; i <= bac; i++) {
            heSo[i] = 0.0; // Khởi tạo tất cả hệ số ban đầu là 0
        }
    }
    ~DaThuc(){
        delete [] heSo;
    }
    void Nhap (){
        for (int i=0;i<bac+1;i++){
            cout<<"\nNhap he so bac "<<i<<":";
            cin >> heSo[i];
        }
    }
    void Xuat(){
	if(bac == 1){
		cout <<heSo[0]<<" + ";
		cout <<heSo[1]<<" * x";
	}
	else{
		cout <<heSo[0]<<" + ";
		cout <<heSo[1]<<" * x + ";
		for(int i = 2; i < bac; i++)
		{
			cout << heSo[i] <<" * x^"<<i<< " + ";
		}
		cout <<heSo[bac]<<" * x^"<<bac;
	}
  }
  DaThuc  operator+ (DaThuc &b){
    int maxbac =max(bac , b.bac);
    DaThuc result (maxbac);// như nay di kem voi viec cap phat dong  luon òi  
    for (int i=0;i<=maxbac;i++){
            float num1 = (i <= bac) ? heSo[i] : 0;
            float num2 = (i <= b.bac) ? b.heSo[i] : 0;
            result.heSo[i] = num1 + num2;
    }
    return result;
  }

  float GiaTriDaThuc(float x){
    float result =heSo[0];
    for(int i=1;i<=bac;i++){
     result += heSo[i]*pow(x,i);
  }
  return result;
  }
  float DaoHamDaThuc(float x) {
    float result = 0.0;
    for (int i = 1; i <= bac; i++) {
        result += i * heSo[i] * pow(x, i - 1);
    }
    return result;
}
};
int main(){
    int bac1,bac2;
    cout<<"\nNhap bac da thuc thu nhat :";
    cin >> bac1;
    DaThuc a(bac1);
    cout<<"\nNhap da thuc thu nhat :";
    a.Nhap();
    cout<<"\nNhap bac da thuc thu hai :";
    cin >>bac2;
    DaThuc b(bac2);
    cout<<"\nNhap da thuc thu hai :";
    b.Nhap();
    cout<<"\nXuat da thuc thu nhat :";
    a.Xuat();
    cout<<"\nXuat da thuc thu hai  :";
    b.Xuat();

    DaThuc result =a +b ; 
    cout<<"\nDa thuc tong  la      :";
    result.Xuat();

    float x; 
    cout<<"\nNhap  gia tri x:";
    cin >>x;
    float Tong = a.GiaTriDaThuc(x)+ b.DaoHamDaThuc(x);
    cout<<fixed<<setprecision(2)<<Tong<<endl;
    return 0;
}
