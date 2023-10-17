#include<bits/stdc++.h>
using namespace std;
/* - Định nghĩa lớp Engine - */
class Engine {
    private :
         int power; 	 // Công suất 
    public:
        /* - Khởi tạo không tham số - */
        Engine(){
          power = 0;
        }	
        /* - Khởi tạo có tham số - */
        Engine(int power) : power(power) {}

        float getPower() {
            return power;
        };
        void show(){
            cout << "Cong xuat cua dong co la : " << power << "KWH" << endl;
        }
};

/* - Định nghĩa lớp Car dẫn xuất từ lớp cơ sở trừu tượng Engine  - */
class Car : public virtual Engine {
    private:
        int  speed;        // Tốc độ  
        string  mark;      // Nhãn hiệu
        float price;       // Giá xe 						
    public:
    /* - Hàm khởi tạo không tham số - */
        Car(){
            speed = price = 0;
            mark = " ";
        }
    /* - Hàm khởi tạo có tham số - */
        Car(int speed, string mark, float price) : speed(speed), mark(mark),price(price) {} 

        float getSpeed() {
            return speed;
        };
        string getMark() {
            return mark;
        };
        float getPrice() {
            return price;
        };
        void show(){
        cout << "This is a " << mark << " having a speed of "
		<< speed << "km / h and its price is $" << price << endl;
	    return;
        }  
};

/* - Định nghĩa lớp PublicTransport dẫn xuất trừu tượng từ lớp Engine - */
class PublicTransport : public virtual Engine {
    private:
        float ticket; 	 	// Giá vé phương tiện
    public:
    /* - Hàm khởi tạo không tham số - */
        PublicTransport(){
            ticket = 0;
        }  
    /* - Hàm khởi tạo có tham số truyền vào có thêm khởi tạo engine để có thể dùng biến công xuất */	
       
    /* : Engine(power) trong PublicTransport giúp truyền giá trị power từ lớp
     PublicTransport xuống lớp Engine, để lớp Engine biết về giá trị công suất của động cơ. */  

        PublicTransport(int power, float ticket) : Engine(power) {
        this->ticket = ticket;
        }  

        float getTicket() {
            return ticket;
        };

        void show(){
        cout << "This is a public transport havìn a ticket of $" << ticket << " and its power is " 
        << getPower() << "KWh" << endl;
        } 	 

    };
/* - Định nghĩa lớp Bus kế thừa từ lớp Car và PublicTransport - */
class Bus : public Car, public PublicTransport { 
    private:	
        int label;  	// Số hiệu tuyến xe  	
    public:
      
        /* - Khởi tạo không có tham số - */
        Bus() : Engine() , Car(), PublicTransport(){
            label =0;
        }
        /* - Khởi tạo có tham số - */
        Bus(int power, int speed, string mark, float price, float ticket, int label) :
	    Engine(power), Car(speed, mark, price), PublicTransport(power, ticket) {
	    this->label = label;
        }
        void show(){
            cout << "This is a bus on the line " << label
		<< ", its speed is " << getSpeed()
		<< "km / h, power is" << Car::getPower()
		<< "KWh, mark is " << getMark() << ", price is $" << getPrice()
		<< " and ticket is " << getTicket() << endl;

        }	 	
};
// phương thức main 
int main() {
	Bus myBus(250, 100, "Mercedes", 3000, 1.5, 27);

	myBus.Car::Engine::show();  	// Hàm của lớp Engine 

	myBus.PublicTransport::Engine::show();// Hàm của lớp Engine 

	myBus.Car::show(); 	 	 	// Hàm của lớp Car 

	myBus.PublicTransport::show(); 	// Hàm của lớp PublicTransport 

	myBus.show(); 	 	 	 	// Hàm của lớp Bus 

	system("pause");
	return 0;
}