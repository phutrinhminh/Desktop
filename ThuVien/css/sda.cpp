#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PhuongTien
{
public:
    virtual void Hien_thi_thong_tin() = 0;
    virtual double Tinhchiphi(double quangduong) = 0;
    virtual int getSoKhachToiDa() = 0;
    virtual ~PhuongTien() {}
};

class GrabBike : public PhuongTien
{
public:
    void Hien_thi_thong_tin() override
    {
        cout << "[GrabBike] - Danh cho 1 khach. Gia re, di chuyen nhanh." << endl;
    }
    double Tinhchiphi(double quangduong) override
    {
        return 8000 * quangduong;
    }
    int getSoKhachToiDa() override
    {
        return 1;
    }
};

class GrabCar : public PhuongTien
{
public:
    void Hien_thi_thong_tin() override
    {
        cout << "[GrabCar] - Danh cho toi da 4 khach. Tien nghi hon, phu hop nhom nho." << endl;
    }
    double Tinhchiphi(double quangduong) override
    {
        return 12000 * quangduong;
    }
    int getSoKhachToiDa() override
    {
        return 4;
    }
};

class GrabCarPlus : public PhuongTien
{
public:
    void Hien_thi_thong_tin() override
    {
        cout << "[GrabCarPlus] - Danh cho toi da 7 khach. Xe rong rai, thoai mai, thich hop gia dinh/nhom dong nguoi." << endl;
    }
    double Tinhchiphi(double quangduong) override
    {
        return 15000 * quangduong;
    }
    int getSoKhachToiDa() override
    {
        return 7;
    }
};

int main()
{
    PhuongTien *danhSachXe[3];
    danhSachXe[0] = new GrabBike();
    danhSachXe[1] = new GrabCar();
    danhSachXe[2] = new GrabCarPlus();

    int soKhach;
    double quangDuong;

    cout << "--- HE THONG DAT XE GRAB ---" << endl;
    cout << "Nhap so luong khach: ";
    cin >> soKhach;
    cout << "Nhap quang duong di chuyen (km): ";
    cin >> quangDuong;

    cout << "\n--- KET QUA TIM KIEM PHUONG TIEN PHU HOP ---" << endl;
    bool coXePhuHop = false;

    for (int i = 0; i < 3; i++)
    {
        if (soKhach <= danhSachXe[i]->getSoKhachToiDa())
        {
            coXePhuHop = true;
            danhSachXe[i]->Hien_thi_thong_tin();
            cout << "=> Chi phi du kien: " << fixed << setprecision(0)
                 << danhSachXe[i]->Tinhchiphi(quangDuong) << " VND\n"
                 << endl;
        }
    }

    else
    {
        cout << "Hien tai ung dung khong co phuong tien nao dap ung duoc so luong khach tren." << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete danhSachXe[i];
    }

    return 0;
}
