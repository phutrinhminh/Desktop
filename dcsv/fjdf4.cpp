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
    string tinhTrang;

public:
    void nhapSach()
    {
        cout << "  + Nhap ma sach: ";
        getline(cin >> ws, maSach);
        cout << "  + Nhap ten sach: ";
        getline(cin >> ws, tenSach);
        cout << "  + Nhap tac gia: ";
        getline(cin >> ws, tacGia);
        cout << "  + Nhap the loai: ";
        getline(cin >> ws, theLoai);
        tinhTrang = "Con";
    }

    void hienThiSach() const
    {
        cout << left << setw(10) << maSach
             << setw(20) << tenSach
             << setw(20) << tacGia
             << setw(15) << theLoai
             << setw(15) << tinhTrang << "\n";
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
        cout << "  + Nhap ma doc gia: ";
        getline(cin >> ws, maDocGia);
        cout << "  + Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "  + Nhap ma sinh vien: ";
        getline(cin >> ws, maSV);
    }

    void hienThiDocGia() const
    {
        cout << left << setw(10) << maDocGia
             << setw(25) << hoTen
             << setw(15) << maSV << "\n";
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
        cout << "  + Nhap so ngay muon: ";
        cin >> soNgayMuon;
    }

    void hienThiPhieu(int stt)
    {
        cout << "\n========================================================================================\n";
        cout << "PHIEU MUON SO: " << stt << " | SO NGAY MUON: " << soNgayMuon << " ngay\n";
        cout << "----------------------------------------------------------------------------------------\n";
        cout << ">>> THONG TIN DOC GIA <<<\n";
        cout << left << setw(10) << "Ma DG"
             << setw(25) << "Ho ten"
             << setw(15) << "Ma SV" << "\n";
        docGia.hienThiDocGia();

        cout << "\n>>> THONG TIN SACH <<<\n";
        cout << left << setw(10) << "Ma sach"
             << setw(20) << "Ten sach"
             << setw(20) << "Tac gia"
             << setw(15) << "The loai"
             << setw(15) << "Tinh trang" << "\n";
        sachDuocMuon.hienThiSach();
        cout << "========================================================================================\n";
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
        cout << "\n=== LAP PHIEU MUON THU " << i + 1 << " ===\n";
        string maDG, maS;

        cout << "  + Nhap ma doc gia muon sach: ";
        getline(cin >> ws, maDG);
        cout << "  + Nhap ma sach can muon: ";
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
            cout << "  -> Loi: Khong tim thay doc gia!\n";
            i--;
            continue;
        }
        if (viTriSach == -1)
        {
            cout << "  -> Loi: Khong tim thay sach!\n";
            i--;
            continue;
        }
        if (danhSachSach[viTriSach].getTinhTrang() == "Da muon")
        {
            cout << "  -> Loi: Sach nay da duoc nguoi khac muon!\n";
            i--;
            continue;
        }

        danhSachSach[viTriSach].setTinhTrang("Da muon");
        danhSachPhieu[i].lapPhieu(danhSachDocGia[viTriDG], danhSachSach[viTriSach]);
    }

    cout << "\n\n>>> BANG LIET KE DANH SACH PHIEU MUON CHI TIET <<<";
    for (int i = 0; i < k; i++)
    {
        danhSachPhieu[i].hienThiPhieu(i + 1);
    }

    delete[] danhSachSach;
    delete[] danhSachDocGia;
    delete[] danhSachPhieu;

    return 0;
}