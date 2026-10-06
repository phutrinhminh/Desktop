#include <iostream>
#include <string>

using namespace std;

class SinhVien
{
private:
    string hoTen;
    int tuoi;
    float diemTB;

public:
    void nhap()
    {
        cout << "Nhap ho ten: ";
        getline(cin >> ws, hoTen);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }

    bool operator==(const SinhVien &sv) const
    {
        return this->diemTB == sv.diemTB;
    }

    bool operator!=(const SinhVien &sv) const
    {
        return this->diemTB != sv.diemTB;
    }
};

int main()
{
    SinhVien sv1, sv2;

    cout << "--- NHAP THONG TIN SINH VIEN 1 ---\n";
    sv1.nhap();

    cout << "\n--- NHAP THONG TIN SINH VIEN 2 ---\n";
    sv2.nhap();

    cout << "\n--- KET QUA SO SANH ---\n";
    if (sv1 == sv2)
    {
        cout << "Hai sinh vien co diem trung binh bang nhau." << endl;
    }
    else if (sv1 != sv2)
    {
        cout << "Hai sinh vien co diem trung binh khac nhau." << endl;
    }

    return 0;
}