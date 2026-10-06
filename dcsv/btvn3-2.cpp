#include <iostream>
#include <string>

using namespace std;

class TaiKhoan
{
private:
    string soTK;
    string tenKH;
    double soDu;

public:
    friend istream &operator>>(istream &in, TaiKhoan &tk)
    {
        cout << "Nhap so tai khoan: ";
        in >> tk.soTK;
        cout << "Nhap ten khach hang: ";
        getline(in >> ws, tk.tenKH);
        cout << "Nhap so du: ";
        in >> tk.soDu;
        return in;
    }

    friend ostream &operator<<(ostream &out, const TaiKhoan &tk)
    {
        out << "So tai khoan: " << tk.soTK << "\n";
        out << "Ten khach hang: " << tk.tenKH << "\n";
        out << "So du: " << tk.soDu << "\n";
        return out;
    }
};

int main()
{
    TaiKhoan tk;

    cout << "--- NHAP THONG TIN TAI KHOAN ---\n";
    cin >> tk;

    cout << "\n--- THONG TIN TAI KHOAN VUA NHAP ---\n";
    cout << tk;

    return 0;
}