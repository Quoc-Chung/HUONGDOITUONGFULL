#include<iostream>
using namespace std;
class HCN{
	float cd,cr;
	public:
		HCN()
		{
			cd=cr=1;
		}
		HCN(float a,float b)
		{
			cd=a;cr=b;
		}
		void xuat(){ cout<<cd<<"\t"<<cr<<endl;
		}
		float dientich()
		{
			return cd*cr;
		}
};
int main()
{
	HCN h;//goi ham tao k doi
	HCN h1(100,60);//goi ham tao co doi
	h.xuat();
	cout<<"\ndien tich "<<h.dientich() ;
	
	cout<<"\ndien tich "<<h1.dientich() ;cout<<endl;h1.xuat();
}