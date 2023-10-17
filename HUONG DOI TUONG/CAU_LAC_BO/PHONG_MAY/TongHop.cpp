#include <iostream>
using namespace std;
void swap(float &a  , float &b){
    float tmp =a;
    a =b;
    b =tmp;
}
class SoThuc {
private:
    float *x; 
    int n;
public:
    SoThuc(int n){
        this->n = n;
        x = new float[n]; 
    }
    void Nhap(){
        for (int i=0;i<n;i++) {
            cin>>x[i];
        }
    }
    void Xuat(){
        cout <<"Cac so duong: ";
        for (int i =0;i<n;i++) {
            if (x[i]>=0) {
                cout<<x[i]<<" ";
            }
        }
        cout << endl;
        cout <<"Cac so am: ";
        for (int i =0;i<n;i++) {
            if (x[i]<0) {
                cout<<x[i]<<" ";
            }
        }
        cout << endl;
    }
    ~SoThuc(){
        delete[] x;
    }
    void SapXep(){
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                    if(x[i] < x[j]){
                        swap(x[i],x[j]);;
                    }
            }
        }
    }
    void XuatCaDay(){
        for(int i=0;i<n;i++){
            cout<<x[i]<<" ";
        }
    }
};
int main() {
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    SoThuc x(n); 
    cout << "Nhap cac so thuc:\n";
    x.Nhap();
    x.Xuat();

    x.SapXep();
    x.XuatCaDay();
    return 0;
}
