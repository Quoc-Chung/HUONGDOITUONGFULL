#include<bits/stdc++.h>
using namespace std;

/* - Định nghĩa lớp Engine - */
class Engine {
private:
    int power; // Công suất
public:
    /* - Xây dựng hàm khởi tạo không đối số - */
    Engine() {
        power = 100;
    }
    Engine(int power) : power(power) {} // Khởi tạo power từ đối số power
    void Show();
    int getPower() {
        return power;
    }
};
// Giới thiệu 
void Engine::Show() {
    cout << "\nXe co cong suat:" << power << endl;
}

/* -Định nghĩa lớp Car dẫn xuất từ lớp cơ sở trừu tượng Engine -*/
class Car : public virtual Engine {
private:
    int speed;
    string mark; //Nhãn hiệu   
    float price; // Giá xe
public:
    Car() : speed(0), price(0), mark(" ") {}

    Car(int speed, string mark, float price) : speed(speed), mark(mark), price(price) {}

    int getSpeed() {
        return speed;
    }
    string getMark() {
        return mark;
    }
    float getPrice() {
        return price;
    }
    void Show() {
        cout << "This is a " << mark << " having a speed of "
            << speed << "km / h and its price is $" << price << endl;

    }
};

/* - Định nghĩa lớp PublicTransport là lớp dẫn xuất của lớp Engine - */
class PublicTransport : public virtual Engine {
private:
    float ticket;   // Giá vé phương tiện        
public:
    PublicTransport() : ticket(0) {}

    PublicTransport(float ticket) : ticket(ticket) {}

    void Show() {
        cout << "This is a public transport having a ticket of $" << ticket << " and its power is " << getPower()
            << "KWh" << endl;
    }
};

/* - Khai báo lớp bus kế thừa lại hai lớp Car và PublicTransport*/
class Bus : public Car, public PublicTransport {
private:
    int label;
public:
    Bus() : label(0) {}
    void Show() {
        cout << "This is a bus on the line." << label << endl;
    }
};

int main() {
    // Tạo một đối tượng Bus
    Bus myBus;
    
    // Gọi các phương thức Show() của các lớp
    myBus.Show(); // Sẽ gọi phương thức Show() của lớp Bus

    // Gọi các phương thức Show() của lớp cơ sở Engine
    myBus.Engine::Show(); // Sẽ gọi phương thức Show() của lớp Engine

    // Gọi các phương thức Show() của lớp Car
    myBus.Car::Show(); // Sẽ gọi phương thức Show() của lớp Car

    // Gọi các phương thức Show() của lớp PublicTransport
    myBus.PublicTransport::Show(); // Sẽ gọi phương thức Show() của lớp PublicTransport

    return 0;
}
