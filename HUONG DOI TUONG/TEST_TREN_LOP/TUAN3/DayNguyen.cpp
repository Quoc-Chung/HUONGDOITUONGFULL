#include<bits/stdc++.h>
using namespace std;
class DayNguyen {
private:
    vector<int> a;
public:
    void Nhap() {
        int n;
        cout << "Nhap so phan tu cua day: ";
        cin >> n;
        a.resize(n); //  cập phát động cho vector a
        cout << "Nhap cac phan tu cua day: ";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
    }
    void Xuat() {
        cout << "Day: ";
        for (int num : a) {
            cout << num << " ";
        }
        cout << endl;
    }
    // Phương thức cộng hai dãy
    DayNguyen Cong(const DayNguyen& b){
        DayNguyen result;
        int n = max(a.size(), b.a.size());
        for (int i = 0; i < n; i++) {
            // Chỗ này  t  dùng toán tử ba ngôi để làm để nếu mảng a < b thì gán giá trị mảng a  = 0
            int num1 = (i < a.size()) ? a[i] : 0;
            int num2 = (i < b.a.size()) ? b.a[i] : 0;
            result.a.push_back(num1 + num2);
        }
        return result;
    }
    // Phương thức tính tổng các phần tử của dãy
    int TinhTong(){
        int sum = 0;
        for (int num : a) {
            sum += num;
        }
        return sum;
    }
    // Phương thức sắp xếp dãy theo thứ tự giảm dần
    void SapXepGiamDan() {
        sort(a.rbegin(), a.rend());
    }
    // Phương thức tìm giá trị lớn nhất của dãy
    int TimGiaTriLonNhat(){
        if (a.empty()) {
            return -1; // Trường hợp dãy rỗng
        }
        int max = a[0];
        for (int num : a) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }
    // Phương thức đếm số phần tử lẻ trong dãy
    int DemSoPhanTuLe(){
        int count = 0;
        for (int num : a) {
            if (num % 2 != 0) {
                count++;
            }
        }
        return count;
    }
};
int main() {
    DayNguyen d1, d2, ketqua;
    cout << "Nhap day thu nhat:\n";
    d1.Nhap();
    cout << "Nhap day thu hai:\n";
    d2.Nhap();
    cout << "Day thu nhat:\n";
    d1.Xuat();
    cout << "Day thu hai:\n";
    d2.Xuat();
    ketqua = d1.Cong(d2);
    cout << "Ket qua cua phep cong hai day:\n";
    ketqua.Xuat();
    int tong = d1.TinhTong();
    cout << "Tong cac phan tu cua day thu nhat: " << tong << endl;
    d1.SapXepGiamDan();
    cout << "Day thu nhat sau khi sap xep giam dan:\n";
    d1.Xuat();
    int max1 = d1.TimGiaTriLonNhat();
    int max2 = d2.TimGiaTriLonNhat();
    if (max1 > max2) {
        cout << "Gia tri lon nhat thuoc ve day thu nhat: " << max1 << endl;
    } else if (max1 < max2) {
        cout << "Gia tri lon nhat thuoc ve day thu hai: " << max2 << endl;
    } else {
        cout << "Hai day co gia tri lon nhat bang nhau: " << max1 << endl;
    }
    int demLe1 = d1.DemSoPhanTuLe();
    int demLe2 = d2.DemSoPhanTuLe();
    cout << "So phan tu le trong day thu nhat: " << demLe1 << endl;
    cout << "So phan tu le trong day thu hai: " << demLe2 << endl;
    return 0;
}
