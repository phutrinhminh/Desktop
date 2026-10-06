#include <iostream>

using namespace std;

int main()
{
    int a = 2;
    char b = 'a';
    float c = 3.14;

    int *pa = &a;
    char *pb = &b;
    float *pc = &c;

    cout << "Dia chi cua bien a: " << pa << endl;
    cout << "Dia chi cua bien b: " << pb << endl;
    cout << "Dia chi cua bien c: " << pc << endl;

    return 0;
}