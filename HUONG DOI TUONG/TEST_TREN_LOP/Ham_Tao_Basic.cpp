#include<bits/stdc++.h>
using namespace std;
class NhanVien{ 
	string manv; char ht[30];char *phongban;
	int sonamcongtac;
	;
	public : 
	/*	 NhanVien() { 
		 	manv="";
		 	strcpy(ht,"");
		 	phongban=new char[20];
		 	strcpy(phongban,"Hanh chinh");
		 	sonamcongtac=0;
		  }*/
 	NhanVien(string ma="",char *hoten="", char *phong="Hanh chinh",int nct=0) { 
		 	manv=ma;
		 	strcpy(ht,hoten);
		 	phongban=new char[strlen(phong)];
		 	strcpy(phongban,phong);
		 	sonamcongtac=nct;
		  }
};
void f(NhanVien ob)
{
	
}
//Viết hàm tạo của lớp NhanVien(string mnv, char ht[30],
// char *phongban, int sonamcongtac)
main ()
{
	NhanVien nv1;
	NhanVien nv2("kt01","Minh Anh","Ky thuat", 13);
}

