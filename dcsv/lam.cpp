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
};
class Phieumuon
{
private:
    Docgia docGia;
    Sach sachDuocMuon;
    int soNgayMuon;

public:
    void lapPhieu(Docgia dg, Sach s)
    {
        docGia = dg;
        sachDuocMuon = s;
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