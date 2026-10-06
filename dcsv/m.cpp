#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// ================= LỚP CHUYẾN BAY =================
class ChuyenBay
{
private:
    string maCB, noiDi, noiDen;
    double giaVeGoc;

public:
    ChuyenBay() {} // Constructor mặc định

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &is, ChuyenBay &cb)
    {
        cout << "Nhap ma chuyen bay: ";
        is >> cb.maCB;
        is.ignore(); // Xóa bộ nhớ đệm
        cout << "Nhap noi di: ";
        getline(is, cb.noiDi);
        cout << "Nhap noi den: ";
        getline(is, cb.noiDen);
        cout << "Nhap gia ve goc: ";
        is >> cb.giaVeGoc;
        return is;
    }

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &os, const ChuyenBay &cb)
    {
        os << "CB: " << cb.maCB << " (" << cb.noiDi << " -> " << cb.noiDen << "), Gia goc: " << fixed << setprecision(0) << cb.giaVeGoc;
        return os;
    }

    string getMaCB() const { return maCB; }
    double getGiaVeGoc() const { return giaVeGoc; }
};

// ================= LỚP HÀNH KHÁCH =================
class HanhKhach
{
private:
    string cccd, hoTen;
    int namSinh;

public:
    HanhKhach() {}

    // Nạp chồng toán tử nhập
    friend istream &operator>>(istream &is, HanhKhach &hk)
    {
        cout << "Nhap CCCD: ";
        is >> hk.cccd;
        is.ignore();
        cout << "Nhap ho ten: ";
        getline(is, hk.hoTen);
        cout << "Nhap nam sinh: ";
        is >> hk.namSinh;
        return is;
    }

    // Nạp chồng toán tử xuất
    friend ostream &operator<<(ostream &os, const HanhKhach &hk)
    {
        os << "Khach: " << hk.hoTen << " (CCCD: " << hk.cccd << ")";
        return os;
    }

    string getCCCD() const { return cccd; }
};

// ================= LỚP VÉ MÁY BAY =================
class VeMayBay
{
private:
    HanhKhach hanhKhach;
    ChuyenBay chuyenBay;
    string ngayBay;
    double hanhLyKyGui; // kg
public:
    VeMayBay() {}

    // Hàm lập vé (liên kết khách và chuyến bay)
    void lapVe(HanhKhach hk, ChuyenBay cb, string ngay, double hanhLy)
    {
        hanhKhach = hk;
        chuyenBay = cb;
        ngayBay = ngay;
        hanhLyKyGui = hanhLy;
    }

    double tinhTongTien() const
    {
        return chuyenBay.getGiaVeGoc() + (hanhLyKyGui * 50000);
    }

    void xuatVe() const
    {
        cout << "----------------------------------\n";
        cout << hanhKhach << endl;
        cout << chuyenBay << endl;
        cout << "Ngay bay: " << ngayBay << " | Hanh ly: " << hanhLyKyGui << " kg\n";
        cout << "=> TONG TIEN VE: " << fixed << setprecision(0) << tinhTongTien() << " VND\n";
    }

    // Nạp chồng toán tử > để so sánh tổng tiền 2 vé
    bool operator>(const VeMayBay &other) const
    {
        return this->tinhTongTien() > other.tinhTongTien();
    }

    // Nạp chồng toán tử + để cộng dồn doanh thu (double + VeMayBay)
    friend double operator+(double tong, const VeMayBay &ve)
    {
        return tong + ve.tinhTongTien();
    }
};

// ================= HÀM MAIN =================
int main()
{
    int m, n, k;

    // 1. Nhập danh sách chuyến bay
    cout << "--- NHAP DANH SACH CHUYEN BAY ---\n";
    cout << "Nhap so luong chuyen bay (n): ";
    cin >> n;
    ChuyenBay *dsCB = new ChuyenBay[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nChuyen bay thu " << i + 1 << ":\n";
        cin >> dsCB[i];
    }

    // 2. Nhập danh sách hành khách
    cout << "\n--- NHAP DANH SACH HANH KHACH ---\n";
    cout << "Nhap so luong hanh khach (m): ";
    cin >> m;
    HanhKhach *dsHK = new HanhKhach[m];
    for (int i = 0; i < m; i++)
    {
        cout << "\nHanh khach thu " << i + 1 << ":\n";
        cin >> dsHK[i];
    }

    // 3. Lập vé máy bay
    cout << "\n--- LAP VE MAY BAY ---\n";
    cout << "Nhap so luong ve can lap (k): ";
    cin >> k;
    VeMayBay *dsVe = new VeMayBay[k];

    for (int i = 0; i < k; i++)
    {
        cout << "\nLap ve thu " << i + 1 << ":\n";
        string maCBTam, cccdTam, ngay;
        double hl;

        cout << "Nhap ma Chuyen Bay: ";
        cin >> maCBTam;
        cout << "Nhap CCCD khach hang: ";
        cin >> cccdTam;
        cout << "Nhap ngay bay (dd/mm/yyyy): ";
        cin >> ngay;
        cout << "Nhap so kg hanh ly ky gui: ";
        cin >> hl;

        // Tìm chuyến bay và khách hàng trong danh sách
        ChuyenBay cbChon;
        HanhKhach hkChon;
        for (int j = 0; j < n; j++)
            if (dsCB[j].getMaCB() == maCBTam)
                cbChon = dsCB[j];
        for (int j = 0; j < m; j++)
            if (dsHK[j].getCCCD() == cccdTam)
                hkChon = dsHK[j];

        dsVe[i].lapVe(hkChon, cbChon, ngay, hl);
    }

    // 4. Sắp xếp danh sách vé theo tổng tiền giảm dần (dùng toán tử >)
    for (int i = 0; i < k - 1; i++)
    {
        for (int j = i + 1; j < k; j++)
        {
            if (dsVe[j] > dsVe[i])
            { // Đã nạp chồng toán tử >
                VeMayBay temp = dsVe[i];
                dsVe[i] = dsVe[j];
                dsVe[j] = temp;
            }
        }
    }

    // 5. In danh sách vé đã sắp xếp và tính doanh thu
    cout << "\n================ KET QUA VE DA DAT ================\n";
    double tongDoanhThu = 0;
    for (int i = 0; i < k; i++)
    {
        dsVe[i].xuatVe();
        tongDoanhThu = tongDoanhThu + dsVe[i]; // Đã nạp chồng toán tử +
    }

    cout << "\n===================================================\n";
    cout << "TONG DOANH THU TAT CA CAC VE: " << fixed << setprecision(0) << tongDoanhThu << " VND\n";

    // Giải phóng bộ nhớ
    delete[] dsCB;
    delete[] dsHK;
    delete[] dsVe;

    return 0;
}