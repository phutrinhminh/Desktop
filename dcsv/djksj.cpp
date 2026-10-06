#include <iostream>
using namespace std;
class grab
{
public:
    virtual void datxe(int quangdg)
    {
        cout << "dang dat xe" << endl;
    }
};
class grabbike : public grab
{
public:
    void datxe(int quangdg) override
    {
        int gia = quangdg * 8000;
        cout << "dat xe may, gia: " << gia << endl;
    }
};
class grabcar : public grab
{
public:
    void datxe(int quangdg) override
    {
        int gia = quangdg * 15000;
        cout << "dat xe o to, gia: " << gia << endl;
    }
};
class grabcarplus : public grab
{
public:
    void datxe(int quangdg) override
    {
        int gia = quangdg * 20000;
        cout << "dat xe o to plus, gia: " << gia << endl;
    }
};
int main()
{
    grabbike phuongtien;
    phuongtien.datxe(10);
}
