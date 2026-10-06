#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class DiemHocKy
{
private:
    double diemMieng;
    double diem15p1, diem15p2;
    double diem1Tiet1, diem1Tiet2;
    double diemThi;

public:
    void nhapDiem()
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

    double tinhTBKiemTra() const
    {
        return (diemMieng * 1 + (diem15p1 + diem15p2) * 1 + (diem1Tiet1 + diem1Tiet2) * 2) / 7.0;
    }

    double tinhTBHocKy() const
    {
        return (2 * tinhTBKiemTra() + diemThi) / 3.0;
    }

    void hienThiChiTiet(string tenHK) const
    {
        cout << left << setw(8) << tenHK
             << setw(12) << diemMieng
             << setw(6) << diem15p1 << ", " << setw(7) << diem15p2
             << setw(6) << diem1Tiet1 << ", " << setw(7) << diem1Tiet2
             << setw(12) << diemThi
             << setw(15) << fixed << setprecision(2) << tinhTBKiemTra()
             << setw(15) << fixed << setprecision(2) << tinhTBHocKy() << "\n";
    }
};

class MonHoc
{
private:
    string tenMon;
    DiemHocKy hk1;
    DiemHocKy hk2;

public:
    void nhapDiem()
    {
        cout << "Nhap ten mon hoc: ";
        cin.ignore();
        getline(cin, tenMon);

        cout << "--- Nhap diem Hoc Ky 1 ---\n";
        hk1.nhapDiem();

        cout << "--- Nhap diem Hoc Ky 2 ---\n";
        hk2.nhapDiem();
    }

    double tinhDiemCaNam() const
    {
        return (hk1.tinhTBHocKy() + 2 * hk2.tinhTBHocKy()) / 3.0;
    }

    void hienThiKetQua() const
    {
        cout << "\n========================================================================================\n";
        cout << "MON HOC: " << tenMon << " | DIEM TRUNG BINH CA NAM: " << fixed << setprecision(2) << tinhDiemCaNam() << "\n";
        cout << "----------------------------------------------------------------------------------------\n";
        cout << left << setw(8) << "Hoc ky"
             << setw(12) << "Diem mieng"
             << setw(15) << "15p (2 bai)"
             << setw(15) << "1 tiet (2 bai)"
             << setw(12) << "Thi cuoi ky"
             << setw(15) << "TB kiem tra"
             << setw(15) << "TB hoc ky" << "\n";
        cout << "----------------------------------------------------------------------------------------\n";
        hk1.hienThiChiTiet("HK1");
        hk2.hienThiChiTiet("HK2");
        cout << "========================================================================================\n";
    }

    string getTenMon() const
    {
        return tenMon;
    }
};

int main()
{
    int soLuong;
    cout << "Nhap so luong mon hoc can quan ly: ";
    cin >> soLuong;

    MonHoc *danhSachMonHoc = new MonHoc[soLuong];

    for (int i = 0; i < soLuong; i++)
    {
        cout << "\n=== MON HOC THU " << i + 1 << " ===\n";
        danhSachMonHoc[i].nhapDiem();
    }

    cout << "\n\n>>> BANG KET QUA CHI TIET TUNG MON <<<";
    for (int i = 0; i < soLuong; i++)
    {
        danhSachMonHoc[i].hienThiKetQua();
    }

    for (int i = 0; i < soLuong - 1; i++)
    {
        for (int j = i + 1; j < soLuong; j++)
        {
            if (danhSachMonHoc[i].tinhDiemCaNam() < danhSachMonHoc[j].tinhDiemCaNam())
            {
                MonHoc temp = danhSachMonHoc[i];
                danhSachMonHoc[i] = danhSachMonHoc[j];
                danhSachMonHoc[j] = temp;
            }
        }
    }

    cout << "\n\n>>> DANH SACH MON HOC XEP THEO DIEM CA NAM (GIAM DAN) <<<\n";
    cout << left << setw(5) << "STT" << setw(20) << "Ten mon hoc" << setw(15) << "Diem ca nam" << "\n";
    cout << "----------------------------------------\n";
    for (int i = 0; i < soLuong; i++)
    {
        cout << left << setw(5) << i + 1
             << setw(20) << danhSachMonHoc[i].getTenMon()
             << setw(15) << fixed << setprecision(2) << danhSachMonHoc[i].tinhDiemCaNam() << "\n";
    }

    delete[] danhSachMonHoc;

    return 0;
}