#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class thangluong
{
private:
    double luongcoban, songaylamviec, sogiotangca;

public:
    void nhapthongtin()
    {
        cout << "Nhap luong co ban: ";
        cin >> luongcoban;
        cout << "Nhap so ngay lam viec: ";
        cin >> songaylamviec;
        cout << "Nhap so gio tang ca: ";
        cin >> sogiotangca;
    }
    double tinhluong()
    {
        return (luongcoban / 26) * songaylamviec + sogiotangca * 100000;
    }
    void xuatthongtin()
    {
        cout << "Luong co ban la: " << luongcoban << endl;
        cout << "So ngay lam viec la: " << songaylamviec << endl;
        cout << "So gio tang ca la: " << sogiotangca << endl;
        cout << "Luong nhan vien la: " << tinhluong() << endl;
    }
};
class nhanvien
{
private:
    string manv, tennv;
    thangluong luong1, luong2, luong3;

public:
    void nhapthongtin()
    {
        cout << "nhap ma nhan vien: ";
        cin >> manv;
        cout << "nhap ten nhan vien: ";
        cin.ignore();
        getline(cin, tennv);
        cout << "nhap thong tin luong thang 1: \n";
        luong1.nhapthongtin();
        cout << "nhap thong tin luong thang 2: \n";
        luong2.nhapthongtin();
        cout << "nhap thong tin luong thang 3: \n";
        luong3.nhapthongtin();
    }
    double tongquy()
    {
        return luong1.tinhluong() + luong2.tinhluong() + luong3.tinhluong();
    };
    void xuatthongtin()
    {
        cout << "thang 1: " << endl;
        luong1.xuatthongtin();
        cout << "thang 2: " << endl;
        luong2.xuatthongtin();
        cout << "thang 3: " << endl;
        luong3.xuatthongtin();
        cout << "Tong luong 3 thang la: " << tongquy() << endl;
    }
    string getmanv()
    {
        return manv;
    }
    string gettennv()
    {
        return tennv;
    }
};
int main()

{
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;
    nhanvien *dsnv = new nhanvien[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Nhap thong tin nhan vien thu " << i + 1 << " ---\n";
        dsnv[i].nhapthongtin();
    }
    cout << "\n--- Thong tin nhan vien ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Thong tin nhan vien thu " << i + 1 << " ---\n";
        dsnv[i].xuatthongtin();
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (dsnv[j].tongquy() > dsnv[i].tongquy())
            {
                nhanvien temp = dsnv[i];
                dsnv[i] = dsnv[j];
                dsnv[j] = temp;
            }
        }
    }
    cout << "\n--- Thong tin nhan vien sau khi sap xep theo tong luong giam dan ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Nhan vien co tong luong cao thu " << i + 1 << " ---\n";
        cout << "Ma nhan vien: " << dsnv[i].getmanv() << endl;
        cout << "Ten nhan vien: " << dsnv[i].gettennv() << endl;
        cout << "Tong luong 3 thang: " << dsnv[i].tongquy() << endl;
    }
    delete[] dsnv;
    return 0;
}

