-- 1. Xóa database TestDB_ChayThu nếu đã tồn tại (để bạn có thể bôi đen chạy lại bao nhiêu lần tùy thích)
USE [master]
GO
IF EXISTS (SELECT name FROM sys.databases WHERE name = N'TestDB_ChayThu')
BEGIN
    ALTER DATABASE TestDB_ChayThu SET SINGLE_USER WITH ROLLBACK IMMEDIATE;
    DROP DATABASE TestDB_ChayThu;
END
GO

-- 2. Tạo một cơ sở dữ liệu nháp
CREATE DATABASE TestDB_ChayThu;
GO

-- 3. Chọn sử dụng Database vừa tạo
USE TestDB_ChayThu;
GO

-- 4. Tạo một bảng đơn giản tên là "BanBe"
CREATE TABLE BanBe (
    ID int IDENTITY(1,1) PRIMARY KEY,
    HoTen nvarchar(50),
    Tuoi int,
    QueQuan nvarchar(50)
);
GO

-- 5. Thêm 3 dòng dữ liệu mẫu vào bảng
INSERT INTO BanBe (HoTen, Tuoi, QueQuan) 
VALUES 
(N'Nguyễn Văn A', 22, N'Hà Nội'),
(N'Trần Thị B', 20, N'Hải Phòng'),
(N'Lê Văn C', 25, N'Đà Nẵng');
GO

-- 6. Truy vấn hiển thị dữ liệu ra màn hình
SELECT * FROM BanBe;
GO