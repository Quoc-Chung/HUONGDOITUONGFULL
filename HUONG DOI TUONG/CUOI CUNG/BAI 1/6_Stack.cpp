#include<bits/stdc++.h>
using namespace std;
class Stack{
  private :
    vector<int>data;
  public :
    bool isEmpty(){
        return data.empty();
    } 
    void push(int x){
      data.push_back(x);
    }
    void pop(int &top){
        // Ki?m tra stack dang r?ng
        if(isEmpty()){
            return;
        }
        top= data.back();
        data.pop_back();
    }
    int top(){
        return data.back();
    }
    void xuat(){
        cout<<"\nCac phan tu trong stack la :"<<endl;
        while(isEmpty()==false){
           int tmp;
           pop(tmp);
           cout<<tmp<<" ";
        }
    }  
};
int main() {
    Stack st;
    int luachon;

    while (true) {
        cout<<endl;
        cout << "1. push\n";
        cout << "2. pop\n";
        cout << "3. top\n";
        cout << "4. xuat\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;
        switch (luachon) {
            case 1:
                int x;
                cout << "Nhap gia tri can push: ";
                cin >> x;
                st.push(x);
                break;

            case 2:
                if (!st.isEmpty()) {
                    int top;
                    st.pop(top);
                    cout << "Phan tu duoc pop: " << top << endl;
                } else {
                    cout << "Stack rong. Khong the pop." << endl;
                }
                break;

            case 3:
                if (!st.isEmpty()) {
                    int top = st.top();
                    cout << "Phan tu o dau stack: " << top << endl;
                } else {
                    cout << "Stack rong. Khong the lay phan tu dau." << endl;
                }
                break;

            case 4:
                st.xuat();
                break;

            case 5:
                return 0;

            default:
                cout << "Lua chon khong hop le. Moi nhap lai." << endl;
                break;
        }
    }

    return 0;
}
