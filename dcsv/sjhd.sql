select MaSV,HDem,Ten from Sinh_Vien
select* from Sinh_Vien where GTinh ='Nam'
select distinct MaMH from Ket_Qua
select* from Sinh_Vien where EMail is null
select* from Sinh_Vien where MaL = 'CNTTAK14'
select* from Ket_Qua where Diem>=7 and Diem<=9
select* from Ket_Qua where Diem between 7 and 9
Select * from Ket_Qua where MaMH = 'CSDL1' or MaMH='TDC'
Select * from Ket_Qua where MaMH in ('CSDL1', 'TDC')
-- Cho danh sách gồm các thông tin: MaSV, Họ tên, năm sinh
Select MaSV 'Ma sinh vien', HDem+' '+Ten as 'Ho va ten',
Nam_sinh = YEAR(ngsinh) From Sinh_Vien
select* from Sinh_Vien where HDem like 'Le%'
select* from Sinh_Vien where HDem like '%Le%'
select top 2 * from M_Hoc
-- DS sinh viên gồm: Mã sinh viên, họ đệm, tên và tuổi
Select MaSV, HDem, Ten, YEAR(getdate())-YEAR(ngsinh) as Tuoi From Sinh_Vien
Select MaSV, HDem, Ten, DATEDIFF(YY, NgSinh,GETDATE()) as Tuoi From Sinh_Vien
select top 3 with ties * from Sinh_Vien order by MaSV asc
select top 3 with ties * from Sinh_Vien order by MaSV desc
select * from Sinh_Vien where (MaL like '%K14' OR MaL like '%K13') and year(NgSinh) ='1992'
-- Cho biet tong sinh vien co trong bang sinh vien
Select COUNT(*) as TongSV From Sinh_Vien
-- Cho biet diem trung binh cua sinh vien co ma la 2
Select AVG(diem) From Ket_Qua Where MaSV=2
-- Môn CSDLI có bao nhiêu lượt thi
Select COUNT(MaSV) From Ket_Qua where MaMH = 'TDC'
-- Co bao nhieu sinh vien thi mon TDC
Select COUNT(distinct MaSV) From Ket_Qua where MaMH = 'TDC'
select COUNT(*) from Ket_Qua 
select MaMH, COUNT(MaSV) from Ket_Qua group by MaMH
select MaL, COUNT(MaSV) from Sinh_Vien group by MaL
Select MaSV, AVG(diem) From Ket_Qua Where MaSV=2 group by MaSV
Select MaSV, AVG(diem) From Ket_Qua group by MaSV
Select MaSV, AVG(diem) From Ket_Qua group by MaSV having AVG(diem) >=8
select MaMH, count(MaSV) From Ket_Qua where kythi=1 group by MaMH having count(MaSV) >= 2
select MaMH, count(*) From Ket_Qua group by MaMH,kythi having count(*) >= 2 and kythi=1
select * from Sinh_Vien where year(NgSinh) ='1993'
select * from Sinh_Vien where MaL='CNTTBK14'
select MaSV from Ket_Qua where MaMH='CSDL1' or MaMH='CSLT1'
select * from Sinh_Vien where HDem like 'Le%'
select MaMH, MAX(diem) from Ket_Qua group by MaMH
select MaL, COUNT(MaSV) from Sinh_Vien group by MaL
select MaL, COUNT(MaSV) from Sinh_Vien group by MaL having COUNT(MaSV) < 10
select gtinh, COUNT(MaSV) from Sinh_Vien group by gtinh



