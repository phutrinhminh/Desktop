select * from Sinh_Vien where year(ngsinh)=1992
select * from Sinh_Vien where  mal = 'CNTTBK14'
select distinct * from ket_qua where Mamh='CSDL1' or Mamh='TDC'
select * from sinh_vien where hdem like 'Le%'
select mamh, max(diem) from ket_qua group by mamh
select mal,count(*) from sinh_vien group by mal having count(*) <10
select mal,count(*) from sinh_vien group by mal
select * from lop
select * from ket_qua where diem = (select max(diem) from ket_qua group by mamh) 
select top 1 with ties * from ket_qua GROUP BY mamh order by diem desc

select * from ket_qua where mamh = 'CSDL1'
select masv , hdem,ten,tenl,tenkhoa from sinh_vien
select * from ket_qua where masv=2
select masv,diem from ket_qua where diem is null
select masv,diem from ket_qua where diem is not null 
select COUNT(*) from ket_qua where mamh='CSDL1'
select COUNT(distinct masv), mamh from ket_qua group by mamh   
select COUNT(*), mamh from ket_qua group by mamh   

select masv,avg(diem) from ket_qua group by masv