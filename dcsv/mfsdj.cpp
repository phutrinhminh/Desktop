#include <iostream>
#include <string>
using namespace std;
class chuyenbay
{
private:
    string macb;
    string diemdi;
    string diemden;
    int giavegoc;

public:
    friend istream &operator>>(istream &in, chuyenbay &cb)
    {
        cout << "Nhap ma chuyen bay: ";
        in >> cb.macb;
        in.ignore();
        cout << "Nhap diem di: ";
        getline(in, cb.diemdi);
        cout << "Nhap diem den: ";
        getline(in, cb.diemden);
        cout << "Nhap gia ve goc: ";
        in >> cb.giavegoc;
        in.ignore();
        return in;
    }
    friend ostream &operator<<(ostream &out, const chuyenbay &cb)
    {
        out << "Ma chuyen bay: " << cb.macb << endl;
        out << "Diem di: " << cb.diemdi << endl;
        out << "Diem den: " << cb.diemden << endl;
        out << "Gia ve goc: " << cb.giavegoc << endl;
        return out;
    }
};
class hanhkhach
{
private:
    string cccd;
    string hoten;
    int namsinh;

public:
    friend istream &operator>>(istream &in, hanhkhach &hk)
    {
        cout << "Nhap CCCD: ";
        in >> hk.cccd;
        in.ignore();
        cout << "Nhap ho ten: ";
        getline(in, hk.hoten);
        cout << "Nhap nam sinh: ";
        in >> hk.namsinh;
        in.ignore();
        return in;
    }
    friend ostream &operator<<(ostream &out, const hanhkhach &hk)
    {
        out << "CCCD: " << hk.cccd << endl;
        out << "Ho ten: " << hk.hoten << endl;
        out << "Nam sinh: " << hk.namsinh << endl;
        return out;
    }
};
class ve
{
private:
    hanhkhach hk;
    chuyenbay cb;
    int ngaybay;
    double kghanhly;

public:
    void lapve(hanhkhach hk, chuyenbay cb)
    {
        this->hk = hk;
        this->cb = cb;
        cout << "Nhap ngay bay: ";
        cin >> ngaybay;
        cout << "Nhap khoi luong hanh ly (kg): ";
        cin >> kghanhly;
    }
   
   
   
};
int main()
{
    int n, m, k;
    cout << "Nhap so luong chuyen bay: ";
    cin >> n;
    chuyenbay *dsCB = new chuyenbay[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin chuyen bay thu " << i + 1 << ":\n";
        cin >> dsCB[i];
    }
    cout << "\nNhap so luong hanh khach: ";
    cin >> m;
    hanhkhach *dsHK = new hanhkhach[m];
    for (int i = 0; i < m; i++)
    {
        cout << "\nNhap thong tin hanh khach thu " << i + 1 << ":\n";
        cin >> dsHK[i];
    }
    cout << "\nNhap so luong ve: ";
    cin >> k;
    ve *dsVe = new ve[k];
    for (int i = 0; i < k; i++)
    {
        cout << "\nLap ve thu " << i + 1 << ":\n";
        string macbTam, cccdTam;
        cout << "Nhap ma chuyen bay: ";
        cin >> macbTam;
        cout << "Nhap CCCD hanh khach: ";
        cin >> cccdTam;
        // Tim chuyen bay va hanh khach trong danh sach
        chuyenbay cbChon;
        hanhkhach hkChon;
        
        dsVe[i].lapve(hkChon, cbChon);
    }
    cout << "\nDanh sach ve truoc khi sap xep:\n";
    for (int i = 0; i < k; i++)
    {
        cout << "\nVe thu " << i + 1 << ":\n";
        
       
    }
    
    
  
    delete[] dsCB;
    delete[] dsHK;
    delete[] dsVe;
};