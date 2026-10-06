#include <iostream>
using namespace std;

// Lớp Vector2D biểu diễn véc tơ trong hệ Oxy
class Vector2D
{
    int x, y; // 2 thành phần x,y của toạ độ
public:
    // Hàm tạo
    Vector2D(int a = 0, int b = 0) : x(a), y(b) {}

    // Nạp chồng toán tử [] để truy cập thành phần
    int &operator[](int index)
    {
        if (index == 0)
            return x; // index=0 thì trả về x
        else
            return y; // Khác 0 thì trả về y
    }

    // Nạp chồng toán tử () để tính tích vô hướng 2 véc tơ
    int operator()(const Vector2D &v)
    {
        return x * v.x + y * v.y; // Công thức tích vô hướng: x1*x2 + y1*y2
    }

    // Hàm hiển thị
    void HienThi()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Vector2D v1(2, 3), v2(4, -1);

    cout << "Toa do v1: ";
    v1.HienThi(); // In ra: (2, 3)

    // Sử dụng toán tử []
    cout << "Thanh phan x cua v1: " << v1[0] << endl;
    cout << "Thanh phan y cua v1: " << v1[1] << endl;

    // Thay đổi giá trị bằng []
    v1[0] = 5; // Lúc này x của v1 = 5
    cout << "v1 sau khi thay doi: ";
    v1.HienThi(); // In ra: (5, 3)

    // Sử dụng toán tử () để tính tích vô hướng
    int tichVH = v1(v2); // Tính v1.operator()(v2)
    cout << "Tich vo huong cua v1 va v2: " << tichVH << endl;

    return 0;
}