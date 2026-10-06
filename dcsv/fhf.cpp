#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    string name;
    int age;
    string address;
    void lv()
    {
        cout << name << " is working." << endl;
    }
};

int main()
{
    Person ps1;
    ps1.name = "John";
    ps1.age = 30;
    ps1.address = "123 Main St";
    cout << "Name: " << ps1.name << endl;
    cout << "Age: " << ps1.age << endl;
    cout << "Address: " << ps1.address << endl;
    ps1.lv();
    return 0;
}
