#include<bits/stdc++.h>
using namespace std;
class HS{
	private:
		string mahs,hoten;
		int ut,diemrl;
	public:
		HS(){ 
		mahs="";hoten="";
		ut=0;diemrl=0;
		}
		friend istream & operator >>(istream& cin,HS &a){
			cout<<"Nhap ma hoc sinh: ";
			cin.ignore();
			getline(cin,a.mahs);
			cout<<"Nhap ho ten: ";
			getline(cin,a.hoten);
			cout<<"Nhap muc uu tien: ";
			cin>>a.ut;
			cout<<"Nhap diem ren luyen : ";
			cin>>a.diemrl;
			return cin;
		}
		friend ostream & operator <<(ostream &cout, const HS &a){
			cout<<"Ma hoc sinh : "<<a.mahs <<"\tHo ten: "<<a.hoten<<"\tMuc uu tien:"<<a.ut<<"\tDiem ren luyen: "<<a.diemrl<<endl;
			return cout;
		}
		int getTong(){
			return ut+diemrl;
		}
		string getTen(){
			return hoten;
		}
		int getUutien(){
			return ut;
		}
		
};
class ungdung{
	int n;
	HS *ds;
	public:
		void nhap(){
			cout<<"Nhap so hoc sinh:";
			cin>>n;
			ds = new HS[n];
			for(int i=0;i<n;i++)
			{
				cin>>ds[i];
			}
		}
		void inGiamDan(){
			HS temp;
			for (int i=0;i<n;i++)
				for (int j=i+1;j<n-1;j++)
				{
					if (ds[i].getTong()<ds[j].getTong()){
						temp=ds[i];
						ds[i]=ds[j];
						ds[j]=temp;
					}
				}
			for (int i=0;i<n;i++)
			{
				cout<<ds[i];
			}
		}
		void thongke(){
			int dem1=0,dem2=0,dem3=0,dem4=0;
			for (int i=0;i<n;i++){
				if (ds[i].getUutien()==1) dem1++;
				else if (ds[i].getUutien()==2) dem2++;
				else if (ds[i].getUutien()==3) dem3++;
				else if (ds[i].getUutien()==4) dem4++;
			}
			cout<<"\nSo hoc sinh muc uu tien 1 2 3 4 lan luot la :"<<dem1<<" "<<dem2<<" "<<dem3<<" "<<dem4;
		}
		void timtheoten(){
			string ht;
			cout<<"\nNHap ten can tim:";
			cin.ignore();
			getline(cin,ht);
			for (int i=0;i<n;i++)
			{
				if (ds[i].getTen()==ht){
					cout<<ds[i];
				}
			}
		}
};
int main()
{
	ungdung a;
	a.nhap();
	a.inGiamDan();
	a.thongke();
	a.timtheoten();
}
