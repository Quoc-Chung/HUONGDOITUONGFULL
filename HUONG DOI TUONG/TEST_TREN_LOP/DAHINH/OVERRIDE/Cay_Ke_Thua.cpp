#include<bits/stdc++.h>
using namespace std;

class Hinh {
public:
    virtual string ten() {
        return "Hinh";
    }
    virtual void in() {
       cout << "Day la mot hinh."<<endl;
    }
};
class HinhHaiChieu : public Hinh {
public:
    virtual string ten() {
        return "Hinh hai chieu";
    }

    virtual void in() {
        cout<<"Day la mot hinh hai chieu."<<endl;
    }

    virtual double dt() {
        return 0.0; 
    }
};
class HinhBaChieu : public Hinh {
public:
    virtual string ten() {
        return "Hinh ba chieu";
    }
    virtual void in() {
        cout << "Day la mot hinh ba chieu."<<endl;
    }
    virtual double tt() {
        return 0.0;
    }
};
class Tron : public HinhHaiChieu {
private:
    double banKinh;
public:
    Tron(double r) : banKinh(r) {}

    virtual string ten() {
        return "Tron";
    }
    virtual void in() {
       cout << "Day la mot hinh tron." <<endl;
    }
    virtual double dt() {
        return M_PI * banKinh * banKinh;
    }
};
class Vuong : public HinhHaiChieu {
private:
    double canh;
public:
    Vuong(double a) : canh(a) {}

    virtual string ten() {
        return "Vuong";
    }
    virtual void in() {
        cout << "Day la mot hinh vuong." <<endl;
    }

    virtual double dt() {
        return canh * canh;
    }
};

class TamGiac : public HinhHaiChieu {
private:
    double a, b, c; // Độ dài các cạnh

public:
    TamGiac(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {}

    virtual string ten() {
        return "Tam giac";
    }

    virtual void in() {
        cout << "Day la mot tam giac." <<endl;
    }

    virtual double dt() {
        // Sử dụng công thức Heron để tính diện tích tam giác
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class Cau : public HinhBaChieu {
private:
    double banKinh;

public:
    Cau(double r) : banKinh(r) {}

    virtual std::string ten() {
        return "Cau";
    }

    virtual void in() {
        std::cout << "Day la mot hinh cau." << std::endl;
    }

    virtual double tt() {
        return (4.0 / 3.0) * M_PI * banKinh * banKinh * banKinh;
    }
};

class LapPhuong : public HinhBaChieu {
private:
    double canh;

public:
    LapPhuong(double a) : canh(a) {}

    virtual std::string ten() {
        return "Lap phuong";
    }

    virtual void in() {
        std::cout << "Day la mot hinh lap phuong." << std::endl;
    }

    virtual double tt() {
        return canh * canh * canh;
    }
};
int main() {
    Hinh* hinh1 = new Tron(5.0);
    Hinh* hinh2 = new Vuong(4.0);
    Hinh* hinh3 = new TamGiac(3.0, 4.0, 5.0);
    Hinh* hinh4 = new Cau(6.0);
    Hinh* hinh5 = new LapPhuong(3.0);

    Hinh* danhSachHinh[] = {hinh1, hinh2, hinh3, hinh4, hinh5};

    for (int i = 0; i < 5; i++) {
        std::cout << "Ten hinh: " << danhSachHinh[i]->ten() << std::endl;
        danhSachHinh[i]->in();
        if (dynamic_cast<HinhHaiChieu*>(danhSachHinh[i])) {
            std::cout << "Dien tich: " << dynamic_cast<HinhHaiChieu*>(danhSachHinh[i])->dt() << std::endl;
        }
        if (dynamic_cast<HinhBaChieu*>(danhSachHinh[i])) {
            std::cout << "The tich: " << dynamic_cast<HinhBaChieu*>(danhSachHinh[i])->tt() << std::endl;
        }
        std::cout << std::endl;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 5; i++) {
        delete danhSachHinh[i];
    }

    return 0;
}
