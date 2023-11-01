#include<bits/stdc++.h>
using namespace std;
class Diem{
	private:
		string tendiem;
		float x,y,z;
		int mau;
	public:
		Diem(){
			tendiem="";
			x=0.0;y=0.0;z=0.0;
			mau=0;
		}
		friend istream & operator >>(istream &cin, Diem &a){
			cout<<"Nhap ten diem:";
			cin>>a.tendiem;
			cout<<"Nhap hoanh do:";
			cin>>a.x;
			cout<<"Nhap tung do:";
			cin>>a.y;
			cout<<"Nhap cao do:" ;
			cin>>a.z;
			cout<<"Nhap mau:(1,2,3) : ";
			cin>>a.mau;
			return cin;
		}
		friend ostream & operator <<(ostream& cout, Diem &a){
			cout<<a.tendiem<<"( "<<a.x<<" , "<<a.y<<" , "<<a.z<<" )"<<"\tMau : "<<a.mau; 
		}
		int getMau(){
			return mau;
		}
		
		float getKcoxy(){
			return sqrt(x*x+y*y);
		}
		float getKcoxyz()
		{
			return sqrt(getKcoxy()*getKcoxy()+z*z);
		}
		float khoangcach(){
			return (abs(x)+abs(y)+abs(z))/3;
		}
		
};
class ungdung{
	int n;
	Diem *d;
	public:
		void nhap(){
			cout<<"Nhap so diem :";
			cin>>n;
			d=new Diem[n];
			for (int i=0;i<n;i++)
			{
				cin>>d[i];
			}
		}
		void maxdo(){
			int index;
			bool  ktra=false;
			float max=0;
			for (int i=0;i<n;i++)
			{
				if (d[i].getMau()==1)
				{
					if (max < d[i].getKcoxyz()) 
					{
						max=d[i].getKcoxyz();
						 index=i;
					}
					ktra=true;
				}
			}
			if (ktra==true){
				cout<<"Diem do xa nhat la :"<<d[index];
			}
			else if (ktra==false) cout<<"Khong co diem do !";
		}
		void tongkhoangcach(){
			float tong=0;
			bool ktra=false;
			for (int i=0;i<n;i++)
			{
				if (d[i].getMau()==3)
				{
					tong+=d[i].khoangcach();
					ktra =true;
				}
			}
			if (ktra==true){
				cout<<"\nTong khoang cach diem vang la :"<<tong;
			}
			else if (ktra==false) cout<<"Khong co diem vang";
		}
};
int main()
{
	ungdung a;
	a.nhap();
	a.maxdo();
	a.tongkhoangcach();
	return 0;
}
