#include <iostream>
#include <string>
using namespace std;

// Lớp trừu tượng
class ThongBao
{
public:
    virtual void guithongbao(const string &tieude, const string &noidung) = 0;
    virtual ~ThongBao() {} // destructor ảo rất quan trọng khi dùng delete với con trỏ lớp cơ sở
};

// Phương thức Email
class Email : public ThongBao
{
    string diachi;

public:
    Email(const string &to) : diachi(to) {}
    void guithongbao(const string &tieude, const string &noidung) override
    {
        cout << "[Email] To: " << diachi << ", Tieu de: " << tieude
             << ", Noi dung: " << noidung << "\n";
    }
};

// Phương thức SMS
class SMS : public ThongBao
{
    string sdt;

public:
    SMS(const string &s) : sdt(s) {}
    void guithongbao(const string &tieude, const string &noidung) override
    {
        cout << "[SMS] To: " << sdt << ", Tieu de: " << tieude << " | Noi dung: " << noidung << "\n";
    }
};

// Push
class Push : public ThongBao
{
    string deviceId;

public:
    Push(const string &id) : deviceId(id) {}
    void guithongbao(const string &tieude, const string &noidung) override
    {

        cout << "[Push] Device: " << deviceId << ", Tieu de: " << tieude << "\n";
        cout << "Noi dung: " << noidung << "\n";
    }
};

int main()
{
    // Khai báo mảng con trỏ lớp cơ sở có kích thước 3 (thay thế cho vector)
    ThongBao *ds[3];

    // Cấp phát bộ nhớ động bằng 'new'
    ds[0] = new Email("fdjsfaf@gmail.com");
    ds[1] = new SMS("0987654321");
    ds[2] = new Push("dicjdis");

    // Duyệt mảng và gọi phương thức
    for (int i = 0; i < 3; i++)
    {
        ds[i]->guithongbao("Thong bao", "Lich thi co thay doi");
    }

    // BẮT BUỘC: Giải phóng bộ nhớ đã cấp phát bằng 'delete' để tránh memory leak
    for (int i = 0; i < 3; i++)
    {
        delete ds[i];
    }

    return 0;
}