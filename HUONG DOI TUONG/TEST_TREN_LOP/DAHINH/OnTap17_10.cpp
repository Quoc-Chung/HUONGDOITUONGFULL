#include<bits/stdc++.h>
using namespace std;

class Mayvitinh{  
	public: 	 	 	
	void show(){
	    cout << "DAY LA MAY VI TINH O LOP CHA" << endl;
	}
}; 
class mayAcer: public Mayvitinh{  	
    public: 	 	 	
    void show(){
        cout << "DAY LA MAY ASUS CUA LOP CON " << endl;
    }
}; 

int main(){
    mayAcer may1; 
    may1.show(); 
}