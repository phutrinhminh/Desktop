#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// =================================================================
// 1. CÁC LỚP ĐỐI TƯỢNG (Sach, Docgia)
// =================================================================
class Sach
{
private:
    string maSach;
    string tenSach;
    string tacGia;
    string theLoai;
    bool tinhTrang;

public:
    Sach() { tinhTrang = true; }

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

    string getMaSach() const { return maSach; }
    string getTenSach() const { return tenSach; }
    bool getTinhTrang() const { return tinhTrang; }
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

    string getMaDG() const { return maDG; }
    string getHoTen() const { return hoTen; }
};

// =================================================================
// 2. LỚP PHIẾU MƯỢN (Chỉ thực hiện hành động nhập)
// =================================================================
class Phieumuon
{
public:
    Docgia docGia;
    Sach sach;
    int soNgayMuon;

    void nhapPhieuMuon()
    {
        cout << "--- Nhap thong tin DOC GIA muon sach ---\n";
        this->docGia.nhapThongTin();

        cout << "--- Nhap thong tin SACH can muon ---\n";
        this->sach.nhapThongTin();

        cout << "  + Nhap so ngay muon: ";
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

// =================================================================
// 3. HÀM MAIN
// =================================================================
int main()
{
    int n, m, k;

    // Bước 1: Khởi tạo danh sách thư viện gốc
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

    // Bước 2: Xử lý phiếu mượn
    cout << "\nNhap so luong phieu muon: ";
    cin >> k;
    cin.ignore();
    Phieumuon *danhSachPM = new Phieumuon[k];

    for (int i = 0; i < k; i++)
    {
        cout << "\n=== LAP PHIEU MUON THU " << i + 1 << " ===\n";

        // 1. Cho phiếu tự nhập thông tin trước
        danhSachPM[i].nhapPhieuMuon();

        // 2. Bắt đầu quá trình tìm kiếm và liên kết ngay trong main
        int viTriDG = -1;
        int viTriSach = -1;

        // Tìm kiếm xem mã độc giả vừa nhập có trong thư viện không
        for (int j = 0; j < m; j++)
        {
            if (danhSachDG[j].getMaDG() == danhSachPM[i].docGia.getMaDG())
            {
                viTriDG = j;
                break;
            }
        }

        // Tìm kiếm xem mã sách vừa nhập có tồn tại và còn cho mượn không
        for (int j = 0; j < n; j++)
        {
            if (danhSachSach[j].getMaSach() == danhSachPM[i].sach.getMaSach() && danhSachSach[j].getTinhTrang())
            {
                viTriSach = j;
                break;
            }
        }

        // Nếu tìm thấy cả 2 thông tin hợp lệ
        if (viTriDG != -1 && viTriSach != -1)
        {
            // Ghi đè thông tin chuẩn từ kho vào phiếu mượn (liên kết độc giả và sách)
            danhSachPM[i].docGia = danhSachDG[viTriDG];
            danhSachPM[i].sach = danhSachSach[viTriSach];

            // Cập nhật sách đã bị mượn
            danhSachSach[viTriSach].setTinhTrang(false);

            cout << "  -> Lap phieu muon thanh cong!\n";
        }
        else
        {
            cout << "  -> Loi: Thong tin khong hop le hoac sach da co nguoi muon! Vui long lam lai.\n";
            i--; // Ép vòng lặp phải lùi lại để bắt người dùng nhập lại phiếu này
            continue;
        }
    }

    // Bước 3: In kết quả
    cout << "\n\n=================================================================\n";
    cout << ">>> DANH SACH PHIEU MUON <<<\n";
    cout << "-----------------------------------------------------------------\n";
    cout << left << setw(25) << "Ten doc gia"
         << setw(25) << "Ten sach"
         << setw(15) << "So ngay muon" << "\n";
    cout << "-----------------------------------------------------------------\n";
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