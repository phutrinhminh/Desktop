#include <iostream>
#include <string>
using namespace std;

class TaiKhoan
{
    long long soDu; // VND
public:
    TaiKhoan(long long s = 0) : soDu(s) {}

    // Chuyen sang USD
    operator double()
    {
        return soDu / 25000.0;
    }

    // Chuyen sang trieu dong
    operator int()
    {
        return (int)(soDu / 1000000);
    }

    // Chuyen sang string
    operator string()
    {
        return "So du: " + to_string(soDu) + " VND";
    }
};

int main()
{
    TaiKhoan tk(17100000); // 17.1 trieu VND

    double usd = tk;
    int trieu = tk;
    string info = tk;

    cout << "So du quy doi sang USD = " << usd << endl;
    cout << "So du (trieu dong) = " << trieu << endl;
    cout << info << endl;
}