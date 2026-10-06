#include <iostream>
using namespace std;
class ThoiGian
{
private:
    int phut;

public:
    ThoiGian(int p = 0)
    {
        phut = p;
    }
    operator int()
    {
        return phut / 60;
    }
    operator float()
    {
        return phut % 60;
    }
    void hienThi()
    {
        cout << phut / 60 << " gio " << phut % 60 << " phut";
    }
};
int main()
{
    int p;
    cout << "Nhap so phut: ";
    cin >> p;
    ThoiGian t(p);
    int gio = t;
    float phut = t;
    cout << "Thoi gian: ";
    t.hienThi();
    cout << endl;
    cout << "So gio: " << gio << endl;
    cout << "So phut: " << phut << endl;
    return 0;
}