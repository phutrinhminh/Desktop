#include <iostream>
#include <fstream>
#include <string> // Bổ sung thư viện string
using namespace std;

class FileDiem
{
private:
    ofstream file;

public:
    // Hàm tạo: mở file
    FileDiem(string tenFile)
    {
        // Sử dụng .c_str() để tương thích với các trình biên dịch C++ cũ
        file.open(tenFile.c_str());
        cout << "Da mo file: " << tenFile << endl;
    }

    // Ghi điểm vào file
    void ghiDiem(string tenSV, double diem)
    {
        if (file.is_open())
        {
            file << tenSV << " : " << diem << endl;
        }
    }

    // Hàm hủy: đóng file
    ~FileDiem()
    {
        if (file.is_open())
        {
            file.close();
            cout << "Da dong file." << endl;
        }
    }
};

int main()
{
    {
        FileDiem f("diem.txt"); // Mở file
        f.ghiDiem("Nguyen Van A", 8.5);
        f.ghiDiem("Tran Thi B", 9.0);
    } // 👉 Ra khỏi khối lệnh => file tự động đóng nhờ destructor

    cout << "Chuong trinh ket thuc.\n";
    return 0;
}