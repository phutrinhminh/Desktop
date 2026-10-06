#include <iostream>

using namespace std;

template <typename T>
T maxs(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T>
void hoanvi(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T mins(T a, T b)
{
    return (a < b) ? a : b;
}

int main()
{

    int d1 = 8;
    int d2 = 9;
    double d3 = 8.75, d4 = 9.25;
    cout << "diem cao nhat int: " << maxs(d1, d2) << endl;
    cout << "diem cao nhat double: " << maxs(d3, d4) << endl;
    cout << "diem thap nhat int: " << mins(d1, d2) << endl;
    cout << "diem thap nhat double: " << mins(d3, d4) << endl;
    cout << "truoc khi hoan vi: " << d1 << " , " << d2 << endl;
    hoanvi(d1, d2);
    cout << "sau khi hoan vi: " << d1 << " , " << d2 << endl;

    return 0;
}