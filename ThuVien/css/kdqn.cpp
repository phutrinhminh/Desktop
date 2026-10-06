#include <iostream>

using namespace std;

template <typename T>
void hoanvi(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{

    int x = 10, y = 20;
    cout << "Truoc khi hoan vi: x = " << x << ", y = " << y << endl;
    hoanvi(x, y);
    cout << "Sau khi hoan vi: x = " << x << ", y = " << y << endl;
    float a = 1.5, b = 2.7;
    hoanvi(a, b);
    cout << "Sau khi hoan vi: a = " << a << ", b = " << b << endl;
    string s1 = "Hello", s2 = "World";
    hoanvi(s1, s2);
    cout << "Sau khi hoan vi: s1 = " << s1 << ", s2 = " << s2 << endl;

    return 0;
}
