#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class vector2d
{
private:
    int x, y;

public:
    vector2d(int x = 0, int y = 0) : x(x), y(y) {}
    void hienthi()
    {
        cout << "(" << x << "," << y << ")";
    }
    friend istream &operator>>(istream &is, vector2d &v0)
    {
        cout << "hoanh do la: ";
        is >> v0.x;
        cout << "tung do la: ";
        is >> v0.y;
        return is;
    }
    friend ostream &operator<<(ostream &os, vector2d &v0)
    {
        os << "(" << v0.x << "," << v0.y << ")";
        return os;
    }
    void *operator new(size_t size)
    {
        cout << "cap phat " << size << " byte" void *p = malloc(size);
        if (!p)throw bad_alloc(
		return p;
    }
    void operator delete(void *p)
    {
        cout << "giai phong bo nho" free(p);
    }
};
int main()
{
    int n;
    cin >> n;
    vector2d *ds = new vector2d[n];
    vector2d v4;
    cout << v4;