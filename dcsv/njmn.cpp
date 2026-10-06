#include <iostream>

using namespace std;

int main()
{
    int *pa = new int(2);
    char *pb = new char('a');
    float *pc = new float(3.14);

    cout << "Dia chi cua bien a: " << pa << endl;
    cout << "Dia chi cua bien b: " << pb << endl;
    cout << "Dia chi cua bien c: " << pc << endl;

    delete pa;
    delete pb;
    delete pc;

    return 0;
}