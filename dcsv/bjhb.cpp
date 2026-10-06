#include <iostream>
#include <string>
using namespace std;

class ChuyenBay {
private:
    string maCB, noiDi, noiDen;
    long long giaVeGoc;
public:
    void nhapThongTin() {
        cout << "Ma CB: "; cin >> maCB;
        cin.ignore();
        cout << "Noi di: "; getline(cin, noiDi);
        cout << "Noi den: "; getline(cin, noiDen);
        cout << "Gia ve goc: "; cin >> giaVeGoc;
    }
    void xuatThongTin() const {
        cout << "CB: " << maCB << " (" << noiDi << " -> " << noiDen << ") - Gia goc: " << giaVeGoc << "\n";
    }
    string getMaCB() const { return maCB; }
    long long getGiaVeGoc() const { return giaVeGoc; }
};

class HanhKhach {
private:
    string cccd, hoTen;
    int namSinh;
public:
    void nhapThongTin() {
        cout << "CCCD: "; cin >> cccd;
        cin.ignore();
        cout << "Ho ten: "; getline(cin, hoTen);
        cout << "Nam sinh: "; cin >> namSinh;
    }
    void xuatThongTin() const {
        cout << "Khach: " << hoTen << " (CCCD: " << cccd << ")\n";
    }
    string getCCCD() const { return cccd; }
};

class VeMayBay {
private:
    HanhKhach hk;
    ChuyenBay cb;
    string ngayBay;
    int hanhLyKyGui;
public:
    void lapVe(HanhKhach h, ChuyenBay c, string ngay, int hl) {
        hk = h; cb = c; ngayBay = ngay; hanhLyKyGui = hl;
    }
    long long tinhTongTien() const {
        return cb.getGiaVeGoc() + (hanhLyKyGui * 50000);
    }
    void xuatVe() const {
        hk.xuatThongTin();
        cb.xuatThongTin();
        cout << "Ngay bay: " << ngayBay << " | Hanh ly: " << hanhLyKyGui << " kg\n";
        cout << "=> TONG TIEN VE: " << tinhTongTien() << " VND\n--------------------\n";
    }
};

int main() {
    int n, m, k;
    cout << "Nhap so Chuyen bay (n): "; cin >> n;
    ChuyenBay* dsCB = new ChuyenBay[n];
    for (int i = 0; i < n; i++) dsCB[i].nhapThongTin();

    cout << "Nhap so Hanh khach (m): "; cin >> m;
    HanhKhach* dsHK = new HanhKhach[m];
    for (int i = 0; i < m; i++) dsHK[i].nhapThongTin();

    cout << "Nhap so Ve can lap (k): "; cin >> k;
    VeMayBay* dsVe = new VeMayBay[k];
    for (int i = 0; i < k; i++) {
        string maCBTam, cccdTam, ngay; int hl;
        cout << "\nVe " << i + 1 << "\nNhap Ma CB: "; cin >> maCBTam;
        cout << "Nhap CCCD Khach: "; cin >> cccdTam;
        cout << "Nhap ngay bay: "; cin >> ngay;
        cout << "Nhap kg hanh ly: "; cin >> hl;

        ChuyenBay cbChon; HanhKhach hkChon;
        for (int j = 0; j < n; j++) if (dsCB[j].getMaCB() == maCBTam) cbChon = dsCB[j];
        for (int j = 0; j < m; j++) if (dsHK[j].getCCCD() == cccdTam) hkChon = dsHK[j];
        dsVe[i].lapVe(hkChon, cbChon, ngay, hl);
    }

    for (int i = 0; i < k - 1; i++) {
        for (int j = i + 1; j < k; j++) {
            if (dsVe[j].tinhTongTien() > dsVe[i].tinhTongTien()) {
                VeMayBay temp = dsVe[i]; dsVe[i] = dsVe[j]; dsVe[j] = temp;
            }
        }
    }

    long long tongDoanhThu = 0;
    cout << "\n=== DANH SACH VE (Giam dan theo tong tien) ===\n";
    for (int i = 0; i < k; i++) {
        dsVe[i].xuatVe();
        tongDoanhThu += dsVe[i].tinhTongTien();
    }
    cout << "TONG DOANH THU: " << tongDoanhThu << " VND\n";
    delete[] dsCB; delete[] dsHK; delete[] dsVe;
    return 0;
}