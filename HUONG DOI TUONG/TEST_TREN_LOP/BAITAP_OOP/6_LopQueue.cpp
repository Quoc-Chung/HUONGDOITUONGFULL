#include <bits/stdc++.h>
using namespace std;
class Queue {
private:
    vector<int> data;
public:
    bool isEmpty() {
        return data.empty();
    }
    void push(int x) {
        data.push_back(x);
    }
    void pop(int &front) {
        if (isEmpty()) {
            return;
        }
        front = data.front();
        data.erase(data.begin());
    }
    int front() {
        return data.front();
    }
    void xuat() {
        cout << "\nCac phan tu trong queue la:" << endl;
        for (int i : data) {
            cout << i << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int luachon;
    while (true) {
        cout << endl;
        cout << "1. enqueue\n";
        cout << "2. pop\n";
        cout << "3. front\n";
        cout << "4. xuat\n";
        cout << "5. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luachon;
        switch (luachon) {
            case 1:
                int x;
                cout << "Nhap gia tri can enqueue: ";
                cin >> x;
                q.push(x);
                break;
            case 2:
                if (!q.isEmpty()) {
                    int front;
                    q.pop(front);
                    cout << "Phan tu duoc dequeue: " << front << endl;
                } else {
                    cout << "Queue rong. Khong the dequeue." << endl;
                }
                break;

            case 3:
                if (!q.isEmpty()) {
                    int front = q.front();
                    cout << "Phan tu o dau queue: " << front << endl;
                } else {
                    cout << "Queue rong. Khong the lay phan tu dau." << endl;
                }
                break;
            case 4:
                q.xuat();
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
