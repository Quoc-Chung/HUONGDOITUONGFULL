#include<bits/stdc++.h>
using namespace std;

class MaTran {
private:
    int n;
    int **a;

public:
    MaTran() : n(0), a(NULL) {}

    MaTran(int n) {
        this->n = n;
        a = new int*[n];
        for (int i = 0; i < n; i++) {
            a[i] = new int[n];
        }
        cout<<"\nNhap ma tran :"<<endl;
        for(int i=0;i<n;i++){
        	for (int j =0;j<n;j++){
        		cout<<"a["<<i<<"]["<<j<<"]:";
        		cin >>a[i][j]; 
			}
		}
    }

    friend istream& operator>>(istream& is, MaTran &mt) {
        cout << "\nNhap kich thuoc ma tran: ";
        is >> mt.n;
        mt.a = new int*[mt.n];
        for (int i = 0; i < mt.n; i++) {
            mt.a[i] = new int[mt.n];
        }
        cout << "\nNhap cac gia tri cho ma tran: ";
        for (int i = 0; i < mt.n; i++) {
            for (int j = 0; j < mt.n; j++) {
                cout << "\na[" << i << "][" << j << "]: ";
                is >> mt.a[i][j];
            }
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, MaTran &mt) {
        os << "\nMa tran vua nhap la: "<<endl;
        for (int i = 0; i < mt.n; i++) {
            for (int j = 0; j < mt.n; j++) {
                os << mt.a[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }

   friend int GiaTriMax(MaTran &mt) {
        int max = INT_MIN;
        int vitri1 = 0, vitri2 = 0;
        for (int i = 0; i < mt.n; i++) {
            for (int j = 0; j < mt.n; j++) {
                if (max < mt.a[i][j]) {
                    max = mt.a[i][j];
                    vitri1 = i;
                    vitri2 = j;
                }
            }
        }
      return max;
    }

    int TrungBinhCong() {
        int dem = 0;
        int tong = 0;
        for (int i = 0; i < this->n; i++) {
            for (int j = 0; j < this->n; j++) {
                if (i == j && this->a[i][j] % 2 != 0) {
                    tong += this->a[i][j];
                    dem++;
                }
            }
        }
        if (dem != 0) {
            return (float)tong / dem;
           
        } else {
            return 0;
        }
    }

    ~MaTran() {
        for (int i = 0; i < n; i++) {
            delete[] a[i];
        }
        delete[] a;
    }
};

int main() {
    int kt;
    cout << "\nNhap n: ";
    cin >> kt;
    MaTran A(kt);
    cout << A;
    
    MaTran B;
    cout << "\nNhap lai ma tran B: ";
    cin >> B;
    cout << B << endl;
    int max1= GiaTriMax(A);
    int max2= GiaTriMax(B);
    
    float tb1 = A.TrungBinhCong();
    float tb2 = B.TrungBinhCong();
    float kq = 23122021 / (max1 + max2);
    cout <<"\nKet qua la :"<<fixed <<setprecision(2)<<kq<<endl;
    
    float kq1 = sqrt(tb1  - tb2);
    cout<<"\nKet qua thu hai :"<<kq1<<endl;
    

    return 0;
}

