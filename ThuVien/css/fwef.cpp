#include <iostream>
#include <string>

using namespace std;

void print(int a)
{
    cout << "ham thuong int: " << a << endl;
}
template <typename T>
void print(T a)
{
    cout << "ham template: " << a << endl;
}
int main()
{
    print(70);
    print(70.1);
    print("kdhfjsf");
    print('s') ;
    return 0;
}
