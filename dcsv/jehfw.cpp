#include <iostream>
#include <string>
using namespace std;
class Diemhocky
{

double diemMieng double diem15p1 double diem15p2 double diem1Tiet1 double diem1Tiet2 double diemThi public : void nhapdiem()
    {
        cout << "  + Diem mieng: ";
        cin >> diemMieng;
        cout << "  + Diem 15 phut (2 cot): ";
        cin >> diem15p1 >> diem15p2;
        cout << "  + Diem 1 tiet (2 cot): ";
        cin >> diem1Tiet1 >> diem1Tiet2;
        cout << "  + Diem thi cuoi ky: ";
        cin >> diemThi;
    }
    double tinhtbkiemtra()
    {
        return (diemMeng + diem15p1 + diem15p2 + 2 * (diem1Tiet1 + diem1Tiet2)) / 7;
    }
    double tinhtbhocky()
    {
        return (tinhtbkiemtra() * 2 + diemThi) / 3;
    }
    void hienthichitiet()
    {
    }
};
class monhoc
{

string tenmonhoc
    Diemhocky hk1
        Diemhocky hk2 public : void
                               nhapdiem2hk()
    {
    }
    void hienthikq()
    {
    }
    double tinhdiemcanam()
    {
    }
    void indiemcanam()
    {
        cout << tinhdiemcanam();
    }
};