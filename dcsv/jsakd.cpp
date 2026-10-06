#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class SanPham
{
private:
    string ma;
    string ten;
    double gia;

public:
    SanPham()
    {
        ma = "";
        ten = "";
        gia = 0.0;
    }

    SanPham(string _ma, string _ten, double _gia)
    {
        ma = _ma;
        ten = _ten;
        gia = _gia;
    }

    double layGia()
    {
        return gia;
    }

    void hienThi()
    {
        cout << left << setw(10) << ma
             << left << setw(20) << ten
             << right << setw(15) << fixed << setprecision(2) << gia << endl;
    }
};

// Sử dụng template khuôn mẫu như trên máy chiếu
template <typename T>
class DanhSachSanPham
{
private:
    T danhSach[100]; // Mảng chứa các phần tử kiểu T (ở bài này sẽ là SanPham)
    int n;           // Số lượng phần tử hiện tại

public:
    DanhSachSanPham()
    {
        n = 0;
    }

    void themSanPham(T sp)
    {
        if (n < 100)
        {
            danhSach[n] = sp;
            n++;
        }
        else
        {
            cout << "Danh sach da day, khong the them!" << endl;
        }
    }

    void hienThiDanhSach()
    {
        cout << "\n--- DANH SACH SAN PHAM ---" << endl;
        cout << left << setw(10) << "Ma"
             << left << setw(20) << "Ten"
             << right << setw(15) << "Gia" << endl;
        for (int i = 0; i < n; i++)
        {
            danhSach[i].hienThi();
        }
    }

    T laySanPhamGiaCaoNhat()
    {
        if (n == 0)
            return T();

        T spGiaCaoNhat = danhSach[0];
        for (int i = 1; i < n; i++)
        {
            // Hàm layGia() sẽ được gọi dựa trên kiểu thực tế của T khi biên dịch
            if (danhSach[i].layGia() > spGiaCaoNhat.layGia())
            {
                spGiaCaoNhat = danhSach[i];
            }
        }
        return spGiaCaoNhat;
    }
};

int main()
{
    // Khởi tạo danh sách với đối số template là kiểu SanPham
    DanhSachSanPham<SanPham> dsSanPham;
    int soLuong;

    cout << "Nhap so luong san pham: ";
    cin >> soLuong;

    for (int i = 0; i < soLuong; i++)
    {
        string ma, ten;
        double gia;

        cout << "\nNhap thong tin san pham thu " << i + 1 << ":" << endl;
        cout << "Ma san pham: ";
        cin >> ws;
        getline(cin, ma);
        cout << "Ten san pham: ";
        getline(cin, ten);
        cout << "Gia san pham: ";
        cin >> gia;

        SanPham sp(ma, ten, gia);
        dsSanPham.themSanPham(sp);
    }

    dsSanPham.hienThiDanhSach();

    cout << "\n--- SAN PHAM CO GIA CAO NHAT ---" << endl;
    cout << left << setw(10) << "Ma"
         << left << setw(20) << "Ten"
         << right << setw(15) << "Gia" << endl;

    SanPham spMax = dsSanPham.laySanPhamGiaCaoNhat();
    spMax.hienThi();

    return 0;
}