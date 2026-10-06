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
    string tinhTrang;

public:
    void nhapSach()
    {
        cout << "Nhap ma sach: ";
        getline(cin >> ws, maSach);
        cout << "Nhap ten sach: ";
        getline(cin >> ws, tenSach);
        cout << "Nhap tac gia: ";
        getline(cin >> ws, tacGia);
        cout << "Nhap the loai: ";
        getline(cin >> ws, theLoai);
        tinhTrang = "Con";
    }

    void hienThiSach()
    {
        cout << "Ma: " << maSach << " | Ten: " << tenSach
             << " | Tac gia: " << tacGia << " | The loai: " << theLoai
             << " | Tinh trang: " << tinhTrang << endl;
    }

    string getMaSach() { return maSach; }
    string getTinhTrang() { return tinhTrang; }
    void setTinhTrang(string tt) { tinhTrang = tt; }
};

class Docgia
{
private:
    string maDocGia;
    string hoTen;
    string maSV;

public:
    void nhapDocGia()
    {
        cout << "Nhap ma doc gia: ";
        getline(cin >> ws, maDocGia);
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap ma sinh vien: ";
        getline(cin >> ws, maSV);
    }

    void hienThiDocGia()
    {
        cout << "Ma DG: " << maDocGia << " | Ho ten: " << hoTen
             << " | Ma SV: " << maSV << endl;
    }

    string getMaDocGia() { return maDocGia; }
};

class Phieumuon
{
private:
    Docgia docGia;
    Sach sachDuocMuon;
    int soNgayMuon;

public:
    void lapPhieu(Docgia docGia, Sach sachDuocMuon)
    {
        this->docGia = docGia;
        this->sachDuocMuon = sachDuocMuon;
        cout << "Nhap so ngay muon: ";
        cin >> soNgayMuon;
    }

    void hienThiPhieu()
    {
        cout << "--- THONG TIN PHIEU MUON ---" << endl;
        cout << "Nguoi muon: ";
        docGia.hienThiDocGia();
        cout << "Sach muon: ";
        sachDuocMuon.hienThiSach();
        cout << "So ngay muon: " << soNgayMuon << " ngay\n";
        cout << "----------------------------" << endl;
    }
};

int main()
{
    int n, m, k;

    cout << "Nhap so luong sach (n): ";
    cin >> n;
    Sach *danhSachSach = new Sach[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n--- Nhap thong tin sach thu " << i + 1 << " ---\n";
        danhSachSach[i].nhapSach();
    }

    cout << "\nNhap so luong doc gia (m): ";
    cin >> m;
    Docgia *danhSachDocGia = new Docgia[m];
    for (int i = 0; i < m; i++)
    {
        cout << "\n--- Nhap thong tin doc gia thu " << i + 1 << " ---\n";
        danhSachDocGia[i].nhapDocGia();
    }

    cout << "\nNhap so luong phieu muon (k): ";
    cin >> k;
    Phieumuon *danhSachPhieu = new Phieumuon[k];

    for (int i = 0; i < k; i++)
    {
        cout << "\n--- Lap phieu muon thu " << i + 1 << " ---\n";
        string maDG, maS;

        cout << "Nhap ma doc gia muon sach: ";
        getline(cin >> ws, maDG);
        cout << "Nhap ma sach can muon: ";
        getline(cin >> ws, maS);

        int viTriDG = -1, viTriSach = -1;
        for (int j = 0; j < m; j++)
        {
            if (danhSachDocGia[j].getMaDocGia() == maDG)
                viTriDG = j;
        }
        for (int j = 0; j < n; j++)
        {
            if (danhSachSach[j].getMaSach() == maS)
                viTriSach = j;
        }

        if (viTriDG == -1)
        {
            cout << "Loi: Khong tim thay doc gia!\n";
            i--;
            continue;
        }
        if (viTriSach == -1)
        {
            cout << "Loi: Khong tim thay sach!\n";
            i--;
            continue;
        }
        if (danhSachSach[viTriSach].getTinhTrang() == "Da muon")
        {
            cout << "Loi: Sach nay da duoc nguoi khac muon!\n";
            i--;
            continue;
        }

        danhSachSach[viTriSach].setTinhTrang("Da muon");
        danhSachPhieu[i].lapPhieu(danhSachDocGia[viTriDG], danhSachSach[viTriSach]);
    }

    cout << "\n========== DANH SACH PHIEU MUON ==========\n";
    for (int i = 0; i < k; i++)
    {
        danhSachPhieu[i].hienThiPhieu();
    }

    delete[] danhSachSach;
    delete[] danhSachDocGia;
    delete[] danhSachPhieu;

    return 0;
}