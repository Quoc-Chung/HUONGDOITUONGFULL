#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class MH
{
	private:
		string mahang;
		string m;
		int sl, g;
	public:
		void nhap(ifstream &code)
		{
			code>>mahang>>m>>sl>>g;
		}
		void xuat()
		{
			cout<<"Ma hang la:"<<mahang<<endl;
			cout<<"Mau:"<<m<<endl;
			cout<<"So luong:"<<sl<<endl;
			cout<<"Gia:"<<g<<endl;
		}
		string mau()
		{
			return m;
		}
		string ma()
		{
			return mahang;
		}
		
};
class mh : public MH
{
	private:
		string kt;
	public:
		void nhap(ifstream &code)
		{
			MH::nhap(code);
			code.ignore();
			code>>kt;
		}
		string kichthuoc()
		{
			return kt;
		}
		void xuat()
		{
			MH::xuat();
			cout<<"Kich thuoc:"<<kt<<endl;
		}
};
int main()
{
	mh *a;
	int n;
	ifstream code("mathang_Nhung22.txt");
    if (!code) {
        cout<<"Loi game roi khong mo duoc tep dau :((" << endl;
        return 1;
    }
	code>> n;
	a= new mh[n];
	for(int i=0;i<n;i++)
	{
		a[i].nhap(code);
	}
	for(int i=0;i<n;i++)
	{
		a[i].xuat();
	}
	
	string e;
	string f;
	string g;
	cout<<"Nhap ma hang can tim:";
	getline(cin,e);
//	cout<<"Nhap mau cua mat hang:";
//	getline(cin,f);
//	cout<<"Nhap co cua mat hang:";
//	getline(cin,g);
	for(int i=0;i<n;i++)
	{
		if(a[i].ma()==e) 
		{
			cout<<"Tim thay";
			a[i].xuat();
		}
		else{
			cout<<"\nKhong tim thay";
		}
	}
}

