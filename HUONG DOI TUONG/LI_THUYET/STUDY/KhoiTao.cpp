#include <iostream>
using namespace std;
class TamGiac {
public:
    int a, b, c;
    TamGiac(int a, int b, int c) : a(a), b(b), c(c) {}
};
int main() {
    TamGiac tamGiac1(3, 4, 5);
    cout << "Tam giac co ba canh: " << tamGiac1.a << ", " << tamGiac1.b << ", " << tamGiac1.c << endl;

    TamGiac tamGiac2(6, 8, 10);
    cout << "Tam giac co ba canh: " << tamGiac2.a << ", " << tamGiac2.b << ", " << tamGiac2.c << endl;

    return 0;
}
