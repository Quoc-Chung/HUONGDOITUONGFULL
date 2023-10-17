/* 
Nhập vào 2 đa thức rồi tính tổng, hiệu, tích, thương của
2 đa thức đó, kết quả trả về là 1 đa thức mới.
Yêu cầu: Phải xuất ra đầy đủ định dạng của 1 đa thức.
ĐA THỨC CÓ DẠNG: a0 * x^0 + a1 * x^1 + a2 * x^2 + ... + an * x^n
Dữ liệu trong đa thức sẽ có:
- Số bậc cao nhất của đa thức (n).
- Danh sách các hệ số của đa thức (từ a0 --> an).
Yêu cầu: Phải xuất ra theo đúng định dạng.
vd: 
Đa thức 1: 1 + 2 * x^1 + 3 * x^2
Đa thức 2: 4 + 5 * x^1 + 6 * x^2 + 7 * x ^ 3
=> Đa thức 1 + Đa thức 2 = 5 + 7 * x^1 + 9 * x^2 + 7 * x^3
=> Đa thức 1 - Đa thức 2 = -3 - 3 * x^1 - 3 * x^2 - 7 * x^3
=> Đa thức 1 * Đa thức 2 = 4 + 13 * x^1 + 28 * x^2 + 34 * x^3 + 32 * x^4 + 21 * x^5.
=> Đa thức 1 / Đa thức 2: Tự nháp.
*/

#include <iostream>
using namespace std;
struct DaThuc
{
	int n; // Số bậc cao nhất của đa thức.
	float *HeSo; // Mảng danh sách các hệ số.
};
typedef struct DaThuc DATHUC;
void NhapDaThuc(DATHUC *x)
{
	do{
		cout << "\nNhap vao so bac cua da thuc: ";
		cin >> x ->n;

		if(x ->n < 1)
		{
			cout << "\nSo bac cua da thuc phai >= 1. Xin kiem tra lai !";
		}
	}while(x ->n < 1);
	
	x ->HeSo = new float[x ->n + 1];
	for(int i = 0; i <= x ->n; i++)
	{
		cout << "\nNhap vao he so thu " << i << " la: ";
		cin >> x ->HeSo[i];
	}
}

void XuatDaThuc(DATHUC *x)
{
	if(x ->n == 1)
	{
		cout << x ->HeSo[0] << " + ";
		cout << x ->HeSo[1] << " * x";
	}
	else
	{
		cout << x ->HeSo[0] << " + ";
		cout << x ->HeSo[1] << " * x + ";
		for(int i = 2; i < x ->n; i++)
		{
			cout << x ->HeSo[i] << " * x^" << i << " + ";
		}
		cout << x ->HeSo[x ->n] << " * x^" << x ->n;
	}
}

int main(int argc, char **argv)
{
	DATHUC *x = new DATHUC;

	NhapDaThuc(x);
	XuatDaThuc(x);

	delete x;
	system("pause");
	return 0;
}