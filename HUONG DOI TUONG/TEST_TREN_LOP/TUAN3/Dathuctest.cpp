#include<iostream>
using namespace std;
#include<math.h>
// khai báo một lớp đa thức 
class DaThuc{
	int bac;
	 float *hs;
	 public:
	 	void nhap();
	 	void xuat();
        // Khai báo một hàm float tính  giá trị  của đa thức 
	 	float tinhdt(float);
        //Xây dựng toán tử operator chỉ truyền vào một Đa thức , đa thức còn lại dùng để cồng chúng 
        // ta sẽ đùng DaThuc p = *this;
	 	DaThuc operator+(DaThuc); 
};


void DaThuc::nhap(){
	do{
		cout<<"nhap bac cua dathuc ";cin>>bac;
	}while(bac<0);
	hs=new float [bac+1];
	for(int i=0;i<=bac;i++)
	{
		cout<<"nhap hs thu "<<i<<":";cin>>hs[i];
	}
}


void DaThuc::xuat(){
	for(int i=0;i<=bac;i++) cout<<hs[i]<<" ";
}

// Tính  giá trị của đa thức 
float DaThuc::tinhdt(float d)
	 	{
		 	float s=0;
		 	for(int i=0;i<=bac;i++)
		 		s+=hs[i]*pow(d,i);
		 	return s;
		 }
//Xây dựng toán tử operator 
DaThuc DaThuc::operator+(DaThuc Q){
	DaThuc P,R;// R là đa thức tổng  
	P=*this;

	R.bac=(P.bac>Q.bac)?P.bac:Q.bac;
// Khai báo cấp phát động  
	R.hs=new float [R.bac+1];
	for (int i=0;i<R.bac ;i++){
        float num1= ( i<=P.bac ) ? P.hs[i] : 0;
        float num2= ( i<=Q.bac)  ? Q.hs[i] : 0;
		R.hs[i]=num1+num2;
    }
	return R;
}
int main()
{
	DaThuc P,Q,R;
	float d;
	cout<<"nhap da thuc P :\n";
	P.nhap();
	cout<<"nhap da thuc Q :\n";
	Q.nhap();
	P.xuat();
	cout<<endl;
	Q.xuat();
	cout<<"\nP+Q=";
	R=P+Q;//P.cong(Q);
	R.xuat();
	cout<<"\nnhap so thuc d ";cin>>d;
	cout<<"Ket qua "<<P.tinhdt(d)+Q.tinhdt(d);
}
