#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class dichvu
{
private:
    string tendv;
    int soluongsudung;
    double dongia;

public:
    void nhap()
    {
        cout << "Nhap ten dich vu: ";
        getline(cin, tendv);
        cout << "Nhap so luong su dung: ";
        cin >> soluongsudung;
        cout << "Nhap don gia: ";
        cin >> dongia;
        cin.ignore();
    }

    double thanhtien()
    {
        return soluongsudung * dongia;
    }

    void xuat()
    {
        cout << left << setw(20) << tendv
             << setw(20) << soluongsudung
             << setw(20) << fixed << setprecision(2) << dongia
             << setw(20) << fixed << setprecision(2) << (soluongsudung * dongia) << endl;
    }
};
class hoadon
{
private:
    int n;
    string tenkh;
    string mahd;
    int songayluutru;
    dichvu *dv = new dichvu[n];
    double giaphongtrenngay;

public:
    void nhap()
    {
        cout << "Nhap ma hoa don: ";
        getline(cin, mahd);
        cout << "Nhap ten khach hang: ";
        getline(cin, tenkh);
        cout << "Nhap so ngay luu tru: ";
        cin >> songayluutru;
        cout << "Nhap gia phong tren ngay: ";
        cin >> giaphongtrenngay;
        cout << "Nhap so luong dich vu su dung: ";
        cin >> n;
        cin.ignore();
        dv = new dichvu[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap thong tin dich vu thu " << i + 1 << ":\n";
            dv[i].nhap();
        }
    }

    double tongtien()
    {
        double tong = 0;
        for (int i = 0; i < n; i++)
        {
            tong += dv[i].thanhtien();
        }
        return tong + (giaphongtrenngay * songayluutru);
    }
    void xuat()
    {
        cout << "Ma hoa don: " << mahd << endl;
        cout << "Ten khach hang: " << tenkh << endl;
        cout << "So ngay luu tru: " << songayluutru << endl;
        cout << "Gia phong tren ngay: " << fixed << setprecision(2) << giaphongtrenngay << endl;
        cout << left << setw(20) << "Ten dich vu"
             << setw(20) << "So luong su dung"
             << setw(20) << "Don gia"
             << setw(20) << "Thanh tien" << endl;
        for (int i = 0; i < n; i++)
        {
            dv[i].xuat();
        }
        cout << "Tong tien: " << fixed << setprecision(2) << tongtien() << endl;
    }
};
int main()
{
    int m;
    cout << "Nhap so luong hoa don: ";
    cin >> m;
    cin.ignore();
    hoadon *hd = new hoadon[m];
    for (int i = 0; i < m; i++)
    {
        cout << "Nhap thong tin hoa don thu " << i + 1 << ":\n";
        hd[i].nhap();
    }
    for (int i = 0; i < m; i++)
    {
        cout << "\nThong tin hoa don thu " << i + 1 << ":\n";
        hd[i].xuat();
    }
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (hd[i].tongtien() < hd[j].tongtien())
            {
                hoadon temp = hd[i];
                hd[i] = hd[j];
                hd[j] = temp;
            }
        }
    }
    cout << "\nDanh sach hoa don sau khi sap xep theo tong tien giam dan:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "\nHoa don co tong tien cao thu " << i + 1 << ":\n";
        hd[i].xuat();
    }
    delete[] hd;
    return 0;
}