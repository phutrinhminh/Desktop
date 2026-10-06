#include <iostream>
#include <string>

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
        cout << "Nhap ma sach: ";
        getline(cin, maSach);
        cout << "Nhap ten sach: ";
        getline(cin, tenSach);
        cout << "Nhap ten tac gia: ";
        getline(cin, tacGia);
        cout << "Nhap the loai: ";
        getline(cin, theLoai);
    }

    void hienThiThongTin()
    {
        cout << "Ma sach: " << maSach << " | Ten: " << tenSach
             << " | Tac gia: " << tacGia << " | The loai: " << theLoai
             << " | Tinh trang: " << (tinhTrang ? "Con" : "Da cho muon") << endl;
    }

    string getMaSach() { return maSach; }
    bool getTinhTrang() { return tinhTrang; }
    void setTinhTrang(bool tt) { tinhTrang = tt; }
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
        cout << "Nhap ma doc gia: ";
        getline(cin, maDG);
        cout << "Nhap ho va ten: ";
        getline(cin, hoTen);
        cout << "Nhap ma sinh vien: ";
        getline(cin, maSV);
    }

    void hienThiThongTin()
    {
        cout << "Ma DG: " << maDG << " | Ho ten: " << hoTen
             << " | Ma SV: " << maSV << endl;
    }

    string getMaDG() { return maDG; }
    string getHoTen() { return hoTen; }
};

class Phieumuon
{
private:
    Docgia docGia;
    Sach sach;
    int soNgayMuon;

public:
    void nhapPhieuMuon(Docgia dg, Sach s)
    {
        docGia = dg;
        sach = s;
        cout << "Nhap so ngay muon: ";
        cin >> soNgayMuon;
        cin.ignore();
    }

    void hienThiPhieuMuon()
    {
        cout << "Nguoi muon: " << docGia.getHoTen() << endl;
        cout << "Sach muon: ";
        sach.hienThiThongTin();
        cout << "So ngay muon: " << soNgayMuon << endl;
    }
};

int main()
{
    int n, m, k;

    cout << "Nhap so luong sach (n): ";
    cin >> n;
    cin.ignore();
    Sach *danhSachSach = new Sach[n];
    for (int i = 0; i < n; i++)
    {
        danhSachSach[i].nhapThongTin();
    }

    cout << "Nhap so luong doc gia (m): ";
    cin >> m;
    cin.ignore();
    Docgia *danhSachDG = new Docgia[m];
    for (int i = 0; i < m; i++)
    {
        danhSachDG[i].nhapThongTin();
    }

    cout << "Nhap so luong phieu muon (k): ";
    cin >> k;
    cin.ignore();
    Phieumuon *danhSachPM = new Phieumuon[k];
    int countPM = 0;

    for (int i = 0; i < k; i++)
    {
        string maDG_TimKiem, maSach_TimKiem;

        cout << "Nhap Ma doc gia muon sach: ";
        getline(cin, maDG_TimKiem);
        cout << "Nhap Ma sach can muon: ";
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
            danhSachPM[countPM].nhapPhieuMuon(danhSachDG[viTriDG], danhSachSach[viTriSach]);
            danhSachSach[viTriSach].setTinhTrang(false);
            countPM++;
        }
        else
        {
            cout << "Thong tin khong hop le hoac sach da co nguoi muon.\n";
        }
    }

    cout << "\nDANH SACH PHIEU MUON\n";
    for (int i = 0; i < countPM; i++)
    {
        danhSachPM[i].hienThiPhieuMuon();
        cout << "---------------------\n";
    }

    delete[] danhSachSach;
    delete[] danhSachDG;
    delete[] danhSachPM;

    return 0;
}