#include <iostream>
using namespace std;
class Point
{

public:
    int x;
    int y;
    friend istream &operator>>(istream &in, Point &p)
    {
        cout << "nhap tu so: ";
        in >> p.x;
        cout << "nhap mau so: ";
        in >> p.y;
        return in;
    }
    int main()
    {
        Point p;
        cin >> p;
        cout << "tu so: " << p.x << endl;
        cout << "mau so: " << p.y << endl;
        return 0;
    }