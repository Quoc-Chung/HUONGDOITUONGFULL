#include<bits/stdc++.h>
using namespace std;
class Something
{
private:
    int m_value1;
    double m_value2;
    char m_value3;
public:
    /*
    Something()
    {
        // These are all assignments, not initializations
        m_value1 = 1;
        m_value2 = 2.2;
        m_value3 = 'c';
    }
    */
    Something():m_value1(1), m_value2(2.2), m_value3('c') {}
    Something(int m_value1, double m_value2, char m_value3) :  m_value1(m_value1), m_value2(m_value2) ,m_value3(m_value3) {}
    void print()
    {
        cout << "Something(" << m_value1 << ", " << m_value2 << ", " << m_value3 << ")\n";
    }
};
 
int main()
{
    Something something;
    something.print();
    return 0;
}
