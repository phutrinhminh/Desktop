#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Sach
{
private:
    string maSach;
    string tenSach;
    string tacGia;
    string theLoai;
    bool tinhTrang;

public:
    Sach()
    {
        tinhTrang = true;
    }

    void nhapThongTin()
    {
        cout << "  + Nhap ma sach: ";
        getline(cin, maSach);
        cout << "  + Nhap ten sach: ";
        getline(cin, tenSach);
        cout << "  + Nhap ten tac gia: ";
        getline(cin, tacGia);
        cout << "  + Nhap the loai: ";
        getline(cin, theLoai);
    }

    void hienThiThongTin() const
    {
        cout << left << setw(10) << maSach
             << setw(20) << tenSach
             << setw(20) << tacGia
             << setw(15) << theLoai
             << setw(15) << (tinhTrang ? "Con" : "Da cho muon") << "\n";
    }

    string getMaSach() const
    {
        return maSach;
    }

    string getTenSach() const
    {
        return tenSach;
    }

    bool getTinhTrang() const
    {
        return tinhTrang;
    }

    void setTinhTrang(bool tt)
    {
        tinhTrang = tt;
    }
};

class Docgia
{
private:
    string maDG;
    string hoTen;
    string maSV;

public:
    void nhapThongTin()
    {
        cout << "  + Nhap ma doc gia: ";
        getline(cin, maDG);
        cout << "  + Nhap ho va ten: ";
        getline(cin, hoTen);
        cout << "  + Nhap ma sinh vien: ";
        getline(cin, maSV);
    }

    void hienThiThongTin() const
    {
        cout << left << setw(10) << maDG
             << setw(25) << hoTen
             << setw(15) << maSV << "\n";
    }

    string getMaDG() const
    {
        return maDG;
    }

    string getHoTen() const
    {
        return hoTen;
    }
};

class Phieumuon
{
public:
    Docgia docGia;
    Sach sach;
    int soNgayMuon;

    void nhapPhieuMuon()
    {
        cout << "Nhap so ngay muon: ";
        cin >> soNgayMuon;
        cin.ignore();
    }

    void hienThiPhieuMuon() const
    {
        cout << left << setw(25) << docGia.getHoTen()
             << setw(25) << sach.getTenSach()
             << setw(15) << soNgayMuon << "\n";
    }
};

int main()
{
    int n, m, k;

    cout << "Nhap so luong sach: ";
    cin >> n;
    cin.ignore();
    Sach *danhSachSach = new Sach[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Nhap thong tin sach thu " << i + 1 << " ---\n";
        danhSachSach[i].nhapThongTin();
    }

    cout << "\nNhap so luong doc gia: ";
    cin >> m;
    cin.ignore();
    Docgia *danhSachDG = new Docgia[m];
    for (int i = 0; i < m; i++)
    {
        cout << "\n--- Nhap thong tin doc gia thu " << i + 1 << " ---\n";
        danhSachDG[i].nhapThongTin();
    }

    cout << "\nNhap so luong phieu muon: ";
    cin >> k;
    cin.ignore();
    Phieumuon *danhSachPM = new Phieumuon[k];

    for (int i = 0; i < k; i++)
    {
        cout << "\n=== LAP PHIEU MUON THU " << i + 1 << " ===\n";
        string maDG_TimKiem, maSach_TimKiem;

        cout << "  + Nhap ma doc gia can muon: ";
        getline(cin, maDG_TimKiem);
        cout << "  + Nhap ma sach can muon: ";
        getline(cin, maSach_TimKiem);

        int viTriDG = -1;
        int viTriSach = -1;

        for (int j = 0; j < m; j++)
        {
            if (danhSachDG[j].getMaDG() == maDG_TimKiem)
                viTriDG = j;
        }

        for (int j = 0; j < n; j++)
        {
            if (danhSachSach[j].getMaSach() == maSach_TimKiem)
                viTriSach = j;
        }

        if (viTriDG != -1 && viTriSach != -1 && danhSachSach[viTriSach].getTinhTrang())
        {
            // Lưu trực tiếp vào vị trí i
            danhSachPM[i].docGia = danhSachDG[viTriDG];
            danhSachPM[i].sach = danhSachSach[viTriSach];

            danhSachPM[i].nhapPhieuMuon();

            danhSachSach[viTriSach].setTinhTrang(false);
        }
        else
        {
            cout << "  -> Thong tin khong hop le hoac sach da co nguoi muon! Vui long nhap lai.\n";
            i--; // Lùi biến đếm i lại 1 bước
        }
    }

    cout << "\n\n=================================================================\n";
    cout << ">>> DANH SACH PHIEU MUON <<<\n";
    cout << "-----------------------------------------------------------------\n";
    cout << left << setw(25) << "Ten doc gia"
         << setw(25) << "Ten sach"
         << setw(15) << "So ngay muon" << "\n";
    cout << "-----------------------------------------------------------------\n";
    // In trực tiếp đến k vì chắc chắn đã mượn thành công k phiếu
    for (int i = 0; i < k; i++)
    {
        danhSachPM[i].hienThiPhieuMuon();
    }
    cout << "=================================================================\n";

    delete[] danhSachSach;
    delete[] danhSachDG;
    delete[] danhSachPM;

    return 0;
}