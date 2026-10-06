#include <iostream>
#include <cmath>
using namespace std;

class Circle;
class Point;

// Khai báo hàm bạn
string Vitri(const Circle &c, const Point &p);

class Point
{
private:
    double x, y;

public:
    Point(double a = 0.0, double b = 0.0) : x(a), y(b) {}
    friend string Vitri(const Circle &, const Point &);
};

class Circle
{
private:
    double cx, cy, r;

public:
    Circle(double x = 0.0, double y = 0.0, double radius = 1.0)
        : cx(x), cy(y), r(radius) {}
    friend string Vitri(const Circle &, const Point &);
};

// Định nghĩa hàm kiểm tra vị trí của điểm so với đường tròn
string Vitri(const Circle &c, const Point &p)
{
    double dx = p.x - c.cx, dy = p.y - c.cy;
    double dist = sqrt(dx * dx + dy * dy);
    double eps = 1e-6;
    // Kiểm tra vị trí nếu dist = r thì điểm  thuộc đường tròn; nếu dist<r thì điểm nằm trong đường tròn và còn lại là nằm ngoài đường tròn
    if (fabs(dist - c.r) <= eps)
        return "Thuoc duong tron";
    else if (dist < c.r)
        return "Nam trong";
    else
        return "Nam ngoai";
}

int main()
{
    Circle c(0, 0, 5);
    Point p1(3, 4), p2(1, 1), p3(6, 0);

    cout << "Diem p1: " << Vitri(c, p1) << endl;
    cout << "Diem p2: " << Vitri(c, p2) << endl;
    cout << "Diem p3: " << Vitri(c, p3) << endl;

    return 0;
}