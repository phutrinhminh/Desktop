#include <iostream>
using namespace std;

class Connguoi
{
public:
    virtual void hoatdong() = 0;
};

// Sinh viên
class SinhVien : public Connguoi
{
public:
    void hoatdong() override
    {
        cout << "Sinh vien dang hoc tap." << endl;
    }
};

class GiangVien : public Connguoi
{
public:
    void hoatdong() override
    {
        cout << "Giang vien dang giang day." << endl;
    }
};

class Canbo : public Connguoi
{
public:
    void hoatdong() override
    {
        cout << "Can bo dang lam viec hanh chinh." << endl;
    }
};

int main()
{
    Connguoi *ds[3];

    ds[0] = new SinhVien();
    ds[1] = new GiangVien();
    ds[2] = new Canbo();

    for (int i = 0; i < 3; i++)
    {
        ds[i]->hoatdong();
    }

    for (int i = 0; i < 3; i++)
    {
        delete ds[i];
    }

    return 0;
}