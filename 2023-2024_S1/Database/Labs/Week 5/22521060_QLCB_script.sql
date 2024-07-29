create database QLCB
use QLCB


--Tao bang
create table KHACHHANG
(
	MAKH	nvarchar(15) not null,
	TEN		nvarchar(15),
	DCHI	nvarchar(50),
	DTHOAI	nvarchar(12)
)
create table NHANVIEN
(
	MANV	nvarchar(15) not null,
	TEN		nvarchar(15),
	DCHI	nvarchar(50),
	DTHOAI	nvarchar(12),
	LUONG	float,
	LOAINV	bit
)
create table LOAIMB
(
	MALOAI	nvarchar(15) not null,
	HANGSX	nvarchar(15)
)
create table MAYBAY
(
	SOHIEU	int not null,
	MALOAI	nvarchar(15) not null
)
create table CHUYENBAY
(
	MACB	nvarchar(4) not null,
	SBDI	varchar(3),
	SBDEN	varchar(3),
	GIODI	datetime,
	GIODEN	datetime
)
create table LICHBAY
(
	NGAYDI	datetime not null,
	MACB	nvarchar(4) not null,
	SOHIEU	int,
	MALOAI	nvarchar(15)
)
create table DATCHO
(	
	MAKH	nvarchar(15) not null,
	NGAYDI	datetime not null,
	MACB	nvarchar(4) not null
)
create table KHANANG
(
	MANV	nvarchar(15) not null,
	MALOAI	nvarchar(15) not null
)
create table PHANCONG
(
	MANV	nvarchar(15) not null,
	NGAYDI	datetime not null,
	MACB	nvarchar(4) not null
)

--tao khoa chinh
alter table KHACHHANG
add constraint PK_MAKH primary key (MAKH)

alter table NHANVIEN
add constraint PK_MANV primary key (MANV)

alter table LOAIMB
add constraint PK_MALOAI primary key (MALOAI)

alter table MAYBAY
add constraint PK_SOHIEU_MALOAI primary key (SOHIEU,MALOAI)

alter table CHUYENBAY
add constraint PK_MACB primary key (MACB)

alter table LICHBAY
add constraint PK_NGAYDI_MACB primary key (NGAYDI,MACB)

alter table DATCHO
add constraint PK_MAKH_NGAYDI_MACB primary key (MAKH,NGAYDI,MACB)

alter table KHANANG
add constraint PK_MANV_MALOAI primary key (MANV,MALOAI)

alter table PHANCONG
add constraint PK_MANV_NGAYDI_MACB primary key (MANV,NGAYDI,MACB)

--tao khoa ngoai
alter table MAYBAY
add constraint FK_MALOAI foreign key (MALOAI) references LOAIMB(MALOAI)

alter table LICHBAY
add constraint FK_SOHIEU_MALOAI foreign key (SOHIEU,MALOAI) references MAYBAY(SOHIEU,MALOAI)

alter table LICHBAY
add constraint FK_MACB foreign key (MACB) references CHUYENBAY(MACB)

alter table DATCHO
add constraint FK_MAKH foreign key (MAKH) references KHACHHANG(MAKH)

alter table DATCHO
add constraint FK_NGAYDI_MACB foreign key (NGAYDI,MACB) references LICHBAY(NGAYDI,MACB)

alter table KHANANG
add constraint FK_MANV foreign key (MANV) references NHANVIEN(MANV)

alter table KHANANG
add constraint FK_MALOAI_KHANANG foreign key (MALOAI) references LOAIMB(MALOAI)

alter table PHANCONG
add constraint FK_MANV_PHANCONG foreign key (MANV) references NHANVIEN(MANV)

alter table PHANCONG
add constraint FK_NGAYDI_MACB_PHANCONG foreign key (NGAYDI,MACB) references LICHBAY(NGAYDI,MACB)


--du lieu
-- bang KHACHHANG
insert into KHACHHANG
values ('0009','Nga','223 Nguyen Trai','8932320')
insert into KHACHHANG
values ('0101','Anh','567 Tran Phu','8826729')
insert into KHACHHANG
values ('0045','Thu','285 Le Loi','8932203')
insert into KHACHHANG
values ('0012','Ha','435 Quang Trung','8933232')
insert into KHACHHANG
values ('0238','Hung','456 Pasteur','9812101')
insert into KHACHHANG
values ('0397','Thanh','234 Le Van Si','8952943')
insert into KHACHHANG
values ('0582','Mai','789 Nguyen Du',null)
insert into KHACHHANG
values ('0934','Minh','678 Le Lai',null)
insert into KHACHHANG
values ('0091','Hai','345 Hung Vuong','8893223')
insert into KHACHHANG
values ('0314','Phuong','395 Vo Van Tan','8232320')
insert into KHACHHANG
values ('0613','Vu','348 CMT8','8343232')
insert into KHACHHANG
values ('0586','Son','123 Bach Dang','8556223')
insert into KHACHHANG
values ('0422','Tien','75 Nguyen Thong','8332222')
go

--bang NHANVIEN
insert into NHANVIEN
values ('1006','Chi','12/6 Nguyen Kiem','8120012',150000,0)
insert into NHANVIEN
values ('1005','Giao','65 Nguyen Thai Son','8324467',500000,0)
insert into NHANVIEN
values ('1001','Huong','8 Dien Bien Phu','8330733',500000,1)
insert into NHANVIEN
values ('1002','Phong','1 Ly Thuong Kiet','8308117',450000,1)
insert into NHANVIEN
values ('1004','Phuong','351 Lac Long Quan','8308155',250000,0)
insert into NHANVIEN
values ('1003','Quang','78 Truong Dinh','8324461',350000,1)
insert into NHANVIEN
values ('1007','Tam','36 Nguyen Van Cu','8458188',500000,0)
go

--bang LOAIMB
insert into LOAIMB
values ('A310','Airbus')
insert into LOAIMB
values ('A320','Airbus')
insert into LOAIMB
values ('A330','Airbus')
insert into LOAIMB
values ('A340','Airbus')
insert into LOAIMB
values ('B727','Boeing')
insert into LOAIMB
values ('B747','Boeing')
insert into LOAIMB
values ('B757','Boeing')
insert into LOAIMB
values ('DC10','MD')
insert into LOAIMB
values ('DC9','MD')
go

--bang MAYBAY
insert into MAYBAY
values (10,'B747')
insert into MAYBAY
values (11,'B727')
insert into MAYBAY
values (13,'B727')
insert into MAYBAY
values (13,'B747')
insert into MAYBAY
values (21,'DC10')
insert into MAYBAY
values (21,'DC9')
insert into MAYBAY
values (22,'B757')
insert into MAYBAY
values (22,'DC9')
insert into MAYBAY
values (23,'DC9')
insert into MAYBAY
values (24,'DC9')
insert into MAYBAY
values (70,'A310')
insert into MAYBAY
values (80,'A310')
insert into MAYBAY
values (93,'B757')
go

--bang CHUYENBAY
insert into CHUYENBAY
values ('100','SLC','BOS','08:00','17:50')
insert into CHUYENBAY
values ('112','DCA','DEN','14:00','18:07')
insert into CHUYENBAY
values ('121','STL','SLC','07:00','09:13')
insert into CHUYENBAY
values ('122','STL','YYV','08:30','10:19')
insert into CHUYENBAY
values ('206','DFW','STL','09:00','11:40')
insert into CHUYENBAY
values ('330','JFK','YYV','16:00','18:53')
insert into CHUYENBAY
values ('334','ORD','MIA','12:00','14:14')
insert into CHUYENBAY
values ('335','MIA','ORD','15:00','17:14')
insert into CHUYENBAY
values ('336','ORD','MIA','18:00','20:14')
insert into CHUYENBAY
values ('337','MIA','ORD','20:30','23:53')
insert into CHUYENBAY
values ('394','DFW','MIA','19:00','21:30')
insert into CHUYENBAY
values ('395','MIA','DFW','21:00','23:43')
insert into CHUYENBAY
values ('449','CDG','DEN','10:00','19:29')
insert into CHUYENBAY
values ('930','YYV','DCA','13:00','16:10')
insert into CHUYENBAY
values ('931','DCA','YYV','17:00','18:10')
insert into CHUYENBAY
values ('932','DCA','YYV','18:00','19:10')
insert into CHUYENBAY
values ('991','BOS','ORD','17:00','18:22')
go

--bang LICHBAY
insert into LICHBAY
values ('11/1/2000','100',80,'A310')
insert into LICHBAY
values ('11/1/2000','112',21,'DC10')
insert into LICHBAY
values ('11/1/2000','206',22,'DC9')
insert into LICHBAY
values ('11/1/2000','334',10,'B747')
insert into LICHBAY
values ('11/1/2000','395',23,'DC9')
insert into LICHBAY
values ('11/1/2000','991',22,'B757')
insert into LICHBAY
values ('11/1/2000','337',10,'B747')
insert into LICHBAY
values ('10/31/2000','100',11,'B727')
insert into LICHBAY
values ('10/31/2000','112',11,'B727')
insert into LICHBAY
values ('10/31/2000','206',13,'B727')
insert into LICHBAY
values ('10/31/2000','334',10,'B747')
insert into LICHBAY
values ('10/31/2000','335',10,'B747')
insert into LICHBAY
values ('10/31/2000','337',24,'DC9')
insert into LICHBAY
values ('10/31/2000','449',70,'A310')
go

--bang DATCHO
insert into DATCHO
values ('0009','11/1/2000','100')
insert into DATCHO
values ('0009','10/31/2000','449')
insert into DATCHO
values ('0045','11/1/2000','991')
insert into DATCHO
values ('0012','10/31/2000','206')
insert into DATCHO
values ('0238','10/31/2000','334')
insert into DATCHO
values ('0582','11/1/2000','991')
insert into DATCHO
values ('0091','11/1/2000','100')
insert into DATCHO
values ('0314','10/31/2000','449')
insert into DATCHO
values ('0613','11/1/2000','100')
insert into DATCHO
values ('0586','11/1/2000','991')
insert into DATCHO
values ('0586','10/31/2000','100')
insert into DATCHO
values ('0422','10/31/2000','449')
go

--bang KHANANG
insert into KHANANG
values ('1001','B727')
insert into KHANANG
values ('1001','B747')
insert into KHANANG
values ('1001','DC10')
insert into KHANANG
values ('1001','A310')
insert into KHANANG
values ('1002','A320')
insert into KHANANG
values ('1002','A340')
insert into KHANANG
values ('1002','B757')
insert into KHANANG
values ('1002','DC9')
insert into KHANANG
values ('1003','A310')
insert into KHANANG
values ('1003','DC9')
go

--bang PHANCONG
insert into PHANCONG
values ('1001','11/1/2000','100')
insert into PHANCONG
values ('1001','10/31/2000','100')
insert into PHANCONG
values ('1002','11/1/2000','100')
insert into PHANCONG
values ('1002','10/31/2000','100')
insert into PHANCONG
values ('1003','10/31/2000','100')
insert into PHANCONG
values ('1003','10/31/2000','337')
insert into PHANCONG
values ('1004','10/31/2000','100')
insert into PHANCONG
values ('1004','10/31/2000','337')
insert into PHANCONG
values ('1005','10/31/2000','337')
insert into PHANCONG
values ('1006','11/1/2000','991')
insert into PHANCONG
values ('1006','10/31/2000','337')
insert into PHANCONG
values ('1007','11/1/2000','112')
insert into PHANCONG
values ('1007','11/1/2000','991')
insert into PHANCONG
values ('1007','10/31/2000','206')
go

--Truy vấn đơn giản
--1. Cho biết mã số, tên phi công, địa chỉ, điện thoại của các phi công đã từng lái máy bay loại B747.
SELECT NV.MANV, NV.TEN, NV.DCHI, NV.DTHOAI
FROM NHANVIEN NV, PHANCONG PC, LICHBAY LB
WHERE NV.MANV = PC.MANV AND PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI AND NV.LOAINV = 1 AND LB.MALOAI = 'B747' 

--2. Cho biết mã số và ngày đi của các chuyến bay xuất phát từ sân bay DCA trong 
--khoảng thời gian từ 14 giờ đến 18 giờ.
SELECT CB.MACB, LB.NGAYDI
FROM CHUYENBAY CB, LICHBAY LB
WHERE CB.MACB = LB.MACB AND (CB.GIODI BETWEEN '14:00' AND '18:00') AND CB.SBDI = 'DCA'

--3. Cho biết tên những nhân viên được phân công trên chuyến bay có mã số 100 xuất 
--phát tại sân bay SLC. Các dòng dữ liệu xuất ra không được phép trùng lắp.
SELECT DISTINCT NV.TEN
FROM NHANVIEN NV, PHANCONG PC, CHUYENBAY CB
WHERE NV.MANV = PC.MANV AND PC.MACB = CB.MACB AND CB.MACB = '100' AND CB.SBDI = 'SLC'

--4. Cho biết mã loại và số hiệu máy bay đã từng xuất phát tại sân bay MIA. Các dòng 
--dữ liệu xuất ra không được phép trùng lắp.
SELECT DISTINCT LB.MALOAI, LB.SOHIEU
FROM CHUYENBAY CB, LICHBAY LB
WHERE CB.MACB = LB.MACB AND CB.SBDI = 'MIA'

--5. Cho biết mã chuyến bay, ngày đi, cùng với tên, địa chỉ, điện thoại của tất cả các 
--hành khách đi trên chuyến bay đó. Sắp xếp theo thứ tự tăng dần của mã chuyến 
--bay và theo ngày đi giảm dần.
SELECT DC.MACB, DC.NGAYDI, KH.TEN, KH.DCHI, KH.DTHOAI
FROM DATCHO DC,KHACHHANG KH
WHERE DC.MAKH = KH.MAKH
ORDER BY DC.MACB ASC, DC.NGAYDI DESC

--6. Cho biết mã chuyến bay, ngày đi, cùng với tên, địa chỉ, điện thoại của tất cả những 
--nhân viên được phân công trong chuyến bay đó. Sắp xếp theo thứ tự tăng dần của 
--mã chuyến bay và theo ngày đi giảm dần.
SELECT PC.MACB, PC.NGAYDI, NV.TEN, NV.DCHI, NV.DTHOAI
FROM PHANCONG PC, NHANVIEN NV
WHERE PC.MANV = NV.MANV 
ORDER BY PC.MACB ASC, PC.NGAYDI DESC

--7. Cho biết mã chuyến bay, ngày đi, mã số và tên của những phi công được phân 
--công vào chuyến bay hạ cánh xuống sân bay ORD.
SELECT PC.MACB, PC.NGAYDI, NV.MANV, NV.TEN
FROM NHANVIEN NV, PHANCONG PC, CHUYENBAY CB
WHERE NV.MANV = PC.MANV AND PC.MACB = CB.MACB AND NV.LOAINV = 1 AND CB.SBDEN = 'ORD'

--8. Cho biết các chuyến bay (mã số chuyến bay, ngày đi và tên của phi công) trong đó 
--phi công có mã 1001 được phân công lái.
SELECT PC.MACB, PC.NGAYDI, NV.TEN TEN_PC_1001
FROM PHANCONG PC, NHANVIEN NV
WHERE PC.MANV = NV.MANV AND NV.LOAINV = 1 AND NV.MANV = '1001'

--9. Cho biết thông tin (mã chuyến bay, sân bay đi, giờ đi, giờ đến, ngày đi) của 
--những chuyến bay hạ cánh xuống DEN. Các chuyến bay được liệt kê theo ngày đi 
--giảm dần và sân bay xuất phát (SBDI) tăng dần.
SELECT CB.MACB, CB.SBDI, CB.GIODI, CB.GIODEN, LB.NGAYDI
FROM CHUYENBAY CB, LICHBAY LB
WHERE CB.MACB = LB.MACB AND CB.SBDEN = 'DEN' 
ORDER BY LB.NGAYDI DESC, CB.SBDI ASC

--10.Với mỗi phi công, cho biết hãng sản xuất và mã loại máy bay mà phi công này có 
--khả năng bay được. Xuất ra tên phi công, hãng sản xuất và mã loại máy bay.
SELECT NV.TEN, LMB.HANGSX, KN.MALOAI
FROM NHANVIEN NV, KHANANG KN, LOAIMB LMB
WHERE NV.MANV = KN.MANV AND KN.MALOAI = LMB.MALOAI

--11.Cho biết mã phi công, tên phi công đã lái máy bay trong chuyến bay mã số 100 
--vào ngày 11/01/2000.
SELECT NV.MANV, NV.TEN 
FROM NHANVIEN NV, PHANCONG PC
WHERE NV.MANV = PC.MANV AND PC.MACB = '100' AND PC.NGAYDI = '11/01/2000' AND NV.LOAINV = 1

--12.Cho biết mã chuyến bay, mã nhân viên, tên nhân viên được phân công vào chuyến 
--bay xuất phát ngày 10/31/2000 tại sân bay MIA vào lúc 20:30
SELECT PC.MACB, NV.MANV, NV.TEN
FROM NHANVIEN NV, PHANCONG PC, CHUYENBAY CB
WHERE NV.MANV = PC.MANV AND PC.MACB = CB.MACB AND PC.NGAYDI = '10/31/2000' 
	  AND CB.SBDI = 'MIA' AND CB.GIODI = '20:30'

--13.Cho biết thông tin về chuyến bay (mã chuyến bay, số hiệu, mã loại, hãng sản xuất) 
--mà phi công “Quang” đã lái.
SELECT LB.MACB, LB.SOHIEU, LMB.MALOAI, LMB.HANGSX
FROM LOAIMB LMB, LICHBAY LB, PHANCONG PC, NHANVIEN NV
WHERE LMB.MALOAI = LB.MALOAI AND LB.MACB = PC.MACB AND LB.NGAYDI = PC.NGAYDI AND LB.NGAYDI = PC.NGAYDI
	  AND PC.MANV = NV.MANV AND NV.LOAINV = 1 AND NV.TEN = 'Quang'

--14.Cho biết tên khách hàng đã đi chuyến bay trên máy bay của hãng “Boeing”
SELECT DISTINCT KH.TEN
FROM KHACHHANG KH, DATCHO DC, LICHBAY LB, LOAIMB LMB
WHERE KH.MAKH = DC.MAKH AND DC.MACB = LB.MACB AND DC.NGAYDI = LB.NGAYDI AND LB.MALOAI =  LMB.MALOAI AND HANGSX = 'Boeing'

--15.Cho biết mã các chuyến bay chỉ bay với máy bay số hiệu 10 và mã loại B747
SELECT DISTINCT LB.MACB
FROM LICHBAY LB
WHERE LB.SOHIEU = 10 AND LB.MALOAI = 'B747'

--GOM NHÓM + HÀM
--1. Với mỗi sân bay (SBDEN), cho biết số lượng chuyến bay hạ cánh xuống sân 
--bay đó. Kết quả được sắp xếp theo thứ tự tăng dần của sân bay đến.
SELECT CB.SBDEN, COUNT(*) SLCB_HC
FROM CHUYENBAY CB
GROUP BY CB.SBDEN 
ORDER BY CB.SBDEN

--2. Với mỗi sân bay (SBDI), cho biết số lượng chuyến bay xuất phát từ sân bay đó, 
--sắp xếp theo thứ tự tăng dần của sân bay xuất phát.
SELECT CB.SBDI, COUNT(*) SLCB_XP
FROM CHUYENBAY CB
GROUP BY CB.SBDI 
ORDER BY CB.SBDI 

--3. Với mỗi sân bay (SBDI), cho biết số lượng chuyến bay xuất phát theo từng 
--ngày. Xuất ra mã sân bay đi, ngày và số lượng.
SELECT CB.SBDI, LB.NGAYDI, COUNT(*) SL
FROM LICHBAY LB, CHUYENBAY CB
WHERE LB.MACB = CB.MACB
GROUP BY CB.SBDI, LB.NGAYDI

--4. Với mỗi sân bay (SBDEN), cho biết số lượng chuyến bay hạ cánh theo từng 
--ngày. Xuất ra mã sân bay đến, ngày và số lượng.
SELECT CB.SBDEN, LB.NGAYDI, COUNT(*) SL
FROM LICHBAY LB, CHUYENBAY CB
WHERE LB.MACB = CB.MACB
GROUP BY CB.SBDEN, LB.NGAYDI

--5. Với mỗi lịch bay, cho biết mã chuyến bay, ngày đi cùng với số lượng nhân viên 
--không phải là phi công của chuyến bay đó.
SELECT PC.MACB, PC.NGAYDI, COUNT(PC.MANV) SLNV
FROM NHANVIEN NV, PHANCONG PC
WHERE NV.MANV = PC.MANV AND NV.LOAINV = 0
GROUP BY PC.MACB, PC.NGAYDI

--6. Số lượng chuyến bay xuất phát từ sân bay MIA vào ngày 11/01/2000.
SELECT COUNT(*) SLCB
FROM CHUYENBAY CB, LICHBAY LB
WHERE CB.MACB = LB.MACB AND CB.SBDI = 'MIA' AND LB.NGAYDI = '11/01/2000'

--7. Với mỗi chuyến bay, cho biết mã chuyến bay, ngày đi, số lượng nhân viên 
--được phân công trên chuyến bay đó, sắp theo thứ tự giảm dần của số lượng.
SELECT PC.MACB, PC.NGAYDI, COUNT(PC.MANV) SL
FROM PHANCONG PC
GROUP BY PC.MACB, PC.NGAYDI
ORDER BY SL DESC

--8. Với mỗi chuyến bay, cho biết mã chuyến bay, ngày đi, cùng với số lượng hành 
--khách đã đặt chỗ của chuyến bay đó, sắp theo thứ tự giảm dần của số lượng.
SELECT DC.MACB, DC.NGAYDI, COUNT(MAKH) SLHK
FROM DATCHO DC
GROUP BY DC.MACB, DC.NGAYDI
ORDER BY SLHK DESC

--9. Với mỗi chuyến bay, cho biết mã chuyến bay, ngày đi, tổng lương của phi hành 
--đoàn (các nhân viên được phân công trong chuyến bay), sắp xếp theo thứ tự
--tăng dần của tổng lương.
SELECT PC.MACB, PC.NGAYDI, SUM(NV.LUONG) TONGLUONG
FROM PHANCONG PC, NHANVIEN NV
WHERE PC.MANV = NV.MANV
GROUP BY PC.MACB, PC.NGAYDI
ORDER BY TONGLUONG

--10.Cho biết lương trung bình của các nhân viên không phải là phi công.
SELECT NV.MANV, NV.TEN, AVG(LUONG) LUONGTB
FROM NHANVIEN NV
WHERE LOAINV = 0
GROUP BY NV.MANV, NV.TEN

--11.Cho biết mức lương trung bình của các phi công.
SELECT NV.MANV, NV.TEN, AVG(LUONG) LUONGTB
FROM NHANVIEN NV
WHERE LOAINV = 1
GROUP BY NV.MANV, NV.TEN

--12.Với mỗi loại máy bay, cho biết số lượng chuyến bay đã bay trên loại máy bay 
--đó hạ cánh xuống sân bay ORD. Xuất ra mã loại máy bay, số lượng chuyến bay.
SELECT LMB.MALOAI, COUNT(*) SL
FROM LOAIMB LMB, LICHBAY LB, CHUYENBAY CB
WHERE LMB.MALOAI = LB.MALOAI AND LB.MACB = CB.MACB AND CB.SBDEN = 'ORD'
GROUP BY LMB.MALOAI

--13.Cho biết sân bay (SBDI) và số lượng chuyến bay có nhiều hơn 2 chuyến bay 
--xuất phát trong khoảng 10 giờ đến 22 giờ.
SELECT CB.SBDI, COUNT(CB.MACB) SLCB
FROM CHUYENBAY CB
WHERE CB.GIODI BETWEEN '10:00' AND '22:00'
GROUP BY CB.SBDI
HAVING COUNT(CB.MACB) > 2

--14.Cho biết tên phi công được phân công vào ít nhất 2 chuyến bay trong cùng một ngày.
SELECT DISTINCT A.TEN 
FROM(
	SELECT DISTINCT NV.TEN, NGAYDI
	FROM NHANVIEN NV, PHANCONG PC
	WHERE NV.MANV = PC.MANV AND LOAINV = 1 
	GROUP BY NV.TEN, NGAYDI
	HAVING COUNT(NV.TEN) >= 2
) A

--15.Cho biết mã chuyến bay và ngày đi của những chuyến bay có ít hơn 3 hành khách đặt chỗ.
--TH liệt kê tất cả các chuyến bay
SELECT CB.MACB, DC.NGAYDI
FROM CHUYENBAY CB LEFT JOIN DATCHO DC
ON CB.MACB = DC.MACB
GROUP BY CB.MACB, DC.NGAYDI
HAVING COUNT(MAKH) < 3

--TH chỉ liệt kế các chuyến bay được đặt 
SELECT CB.MACB, DC.NGAYDI
FROM CHUYENBAY CB INNER JOIN DATCHO DC
ON CB.MACB = DC.MACB
GROUP BY CB.MACB, DC.NGAYDI
HAVING COUNT(MAKH) < 3

--16.Cho biết số hiệu máy bay và loại máy bay mà phi công có mã 1001 được phân công lái trên 2 lần.
SELECT SOHIEU, LB.MALOAI
FROM NHANVIEN NV, PHANCONG PC, LICHBAY LB
WHERE NV.MANV = PC.MANV AND PC.MACB = LB.MACB AND PC.NGAYDI = LB.NGAYDI AND NV.MANV = '1001' AND LOAINV = 1
GROUP BY SOHIEU, LB.MALOAI
HAVING COUNT(*) > 2

--17.Với mỗi hãng sản xuất, cho biết số lượng loại máy bay mà hãng đó đã sản xuất. 
--Xuất ra hãng sản xuất và số lượng.
SELECT HANGSX, COUNT(SOHIEU) SLMB
FROM LOAIMB LMB, MAYBAY MB
WHERE LMB.MALOAI = MB.MALOAI
GROUP BY HANGSX

--TRUY VẤN LỒNG + HÀM
--18.Cho biết hãng sản xuất, mã loại và số hiệu của máy bay đã được sử dụng nhiều nhất.
SELECT TOP 1 WITH TIES HANGSX, SOHIEU
FROM LICHBAY LB, LOAIMB LMB
WHERE LB.MALOAI = LMB.MALOAI
GROUP BY HANGSX, SOHIEU
ORDER BY COUNT(*) DESC

--19.Cho biết tên nhân viên được phân công đi nhiều chuyến bay nhất.
SELECT TOP 1 WITH TIES TEN
FROM NHANVIEN NV, PHANCONG PC
WHERE NV.MANV = PC.MANV
GROUP BY TEN
ORDER BY COUNT(*) DESC 

--20.Cho biết thông tin của phi công (tên, địa chỉ, điện thoại) lái nhiều chuyến bay nhất.
--C1:
SELECT TOP 1 WITH TIES NV.TEN, NV.DCHI, NV.DTHOAI
FROM NHANVIEN NV, PHANCONG PC
WHERE NV.MANV = PC.MANV AND LOAINV = 1
GROUP BY TEN, DCHI, DTHOAI
ORDER BY COUNT(*) DESC
--C2:
SELECT NV.TEN, NV.DCHI, NV.DTHOAI
FROM NHANVIEN NV, PHANCONG PC
WHERE PC.MANV = NV.MANV AND NV.LOAINV = 1
GROUP BY NV.TEN, NV.DCHI, NV.DTHOAI
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM PHANCONG PC, NHANVIEN NV
	WHERE PC.MANV = NV.MANV AND NV.LOAINV = 1
	GROUP BY PC.MANV
)    
--21.Cho biết sân bay (SBDEN) và số lượng chuyến bay của sân bay có ít chuyến 
--bay đáp xuống nhất. 
SELECT CB.SBDEN, COUNT(*) SLCB
FROM CHUYENBAY CB
GROUP BY CB.SBDEN
HAVING COUNT(*) <= ALL(
	SELECT COUNT(*)
	FROM CHUYENBAY CB
	GROUP BY CB.SBDEN
)
--22.Cho biết sân bay (SBDI) và số lượng chuyến bay của sân bay có nhiều chuyến 
--bay xuất phát nhất.
SELECT CB.SBDI, COUNT(*) SLCB
FROM CHUYENBAY CB
GROUP BY CB.SBDI
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM CHUYENBAY CB
	GROUP BY CB.SBDI
)

--23.Cho biết tên, địa chỉ, và điện thoại của khách hàng đã đi trên nhiều chuyến bay nhất.
SELECT KH.TEN, KH.DCHI, KH.DTHOAI
FROM KHACHHANG KH, DATCHO DC
WHERE KH.MAKH = DC.MAKH
GROUP BY KH.TEN, KH.DCHI, KH.DTHOAI
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM KHACHHANG KH, DATCHO DC
	WHERE KH.MAKH = DC.MAKH
	GROUP BY KH.MAKH
)
--24.Cho biết mã số, tên và lương của các phi công có khả năng lái nhiều loại máy bay nhất.
SELECT NV.MANV, NV.TEN, NV.LUONG
FROM NHANVIEN NV, KHANANG KN
WHERE NV.MANV = KN.MANV
GROUP BY NV.MANV, NV.TEN, NV.LUONG
HAVING COUNT(*) >= ALL(
	SELECT COUNT(*)
	FROM NHANVIEN NV, KHANANG KN
	WHERE NV.MANV = KN.MANV
	GROUP BY NV.MANV
)
--25.Cho biết thông tin (mã nhân viên, tên, lương) của nhân viên có mức lương cao nhất.
SELECT NV.MANV, NV.TEN, NV.LUONG
FROM NHANVIEN NV
WHERE LUONG >= ALL(
	SELECT NV.LUONG 
	FROM NHANVIEN NV
)
--26.Cho biết tên, địa chỉ của các nhân viên có lương cao nhất trong phi hành đoàn 
--(các nhân viên được phân công trong một chuyến bay) mà người đó tham gia.
SELECT NV.TEN, NV.DCHI
FROM NHANVIEN NV
WHERE EXISTS(
	SELECT *
	FROM PHANCONG PC,  NHANVIEN NV1
	WHERE NV1.MANV = PC.MANV
	GROUP BY PC.MACB, PC.NGAYDI
	HAVING NV.LUONG IN(
		SELECT MAX(NV1.LUONG) 
		FROM PHANCONG PC,  NHANVIEN NV1
		WHERE NV1.MANV = PC.MANV
		GROUP BY MACB, NGAYDI
	)
)
--27.Cho biết mã chuyến bay, giờ đi và giờ đến của chuyến bay bay sớm nhất trong ngày.
SELECT CB.MACB, LB.NGAYDI, CB.GIODI, CB.GIODEN
 FROM LICHBAY LB, CHUYENBAY CB
 WHERE LB.MACB = CB.MACB AND EXISTS(
	SELECT*
	FROM LICHBAY LB1, CHUYENBAY CB1
	WHERE LB1.MACB = CB1.MACB AND LB.NGAYDI = LB1.NGAYDI
	GROUP BY LB1.NGAYDI
	HAVING CB.GIODI = MIN(CB1.GIODI)
)

--28.Cho biết mã chuyến bay có thời gian bay dài nhất. Xuất ra mã chuyến bay và 
--thời gian bay (tính bằng phút).
SELECT TOP 1 WITH TIES CB.MACB, DATEDIFF(MI, GIODI, GIODEN) THOIGIANBAY_PHUT
FROM CHUYENBAY CB
ORDER BY THOIGIANBAY_PHUT DESC

--29.Cho biết mã chuyến bay có thời gian bay ít nhất. Xuất ra mã chuyến bay và thời gian bay.
SELECT TOP 1 WITH TIES CB.MACB, DATEDIFF(MI, GIODI, GIODEN) THOIGIANBAY_PHUT
FROM CHUYENBAY CB
ORDER BY THOIGIANBAY_PHUT ASC

--30.Cho biết mã chuyến bay và ngày đi của những chuyến bay bay trên loại máy bay B747 nhiều nhất.
SELECT LB.MACB, LB.NGAYDI
FROM LICHBAY LB
WHERE EXISTS(
	SELECT *
	FROM LICHBAY LB1
	WHERE LB1.MACB = LB.MACB AND LB1.MALOAI = 'B747'
	GROUP BY MACB
	HAVING COUNT(LB1.NGAYDI) >= ALL(
		SELECT COUNT(LB2.NGAYDI)
		FROM LICHBAY LB2
		WHERE LB2.MALOAI = 'B747'
		GROUP BY MACB
	)
)

--31.Với mỗi chuyến bay có trên 3 hành khách, cho biết mã chuyến bay và số lượng 
--nhân viên trên chuyến bay đó. Xuất ra mã chuyến bay và số lượng nhân viên.
SELECT PC.MACB, COUNT(DISTINCT MANV) SLNV, COUNT(DISTINCT DC.MAKH) SLNV
FROM DATCHO DC, PHANCONG PC, LICHBAY LB
WHERE PC.MACB = DC.MACB AND DC.NGAYDI = PC.NGAYDI AND PC.NGAYDI = LB.NGAYDI AND PC.MACB = LB.MACB
GROUP BY PC.MACB, LB.NGAYDI
HAVING COUNT(DISTINCT DC.MAKH) > 3

--32.Với mỗi loại nhân viên có tổng lương trên 600000, cho biết số lượng nhân viên 
--trong từng loại nhân viên đó. Xuất ra loại nhân viên, và số lượng nhân viên tương ứng.
SELECT NV.LOAINV, COUNT(NV.MANV) SLNV
FROM NHANVIEN NV
GROUP BY NV.LOAINV
HAVING SUM(NV.LUONG) > 600000

--33.Với mỗi chuyến bay có trên 3 nhân viên, cho biết mã chuyến bay và số lượng 
--khách hàng đã đặt chỗ trên chuyến bay đó.
SELECT LB.MACB, COUNT(DISTINCT DC.MAKH) SOLUONGKHACH
FROM DATCHO DC, PHANCONG PC, LICHBAY LB
WHERE DC.MACB = LB.MACB AND DC.NGAYDI = LB.NGAYDI AND PC.NGAYDI = LB.NGAYDI AND PC.MACB = LB.MACB
GROUP BY LB.MACB, LB.NGAYDI
HAVING COUNT(DISTINCT PC.MANV) > 3

--34.Với mỗi loại máy bay có nhiều hơn một chiếc, cho biết số lượng chuyến bay đã 
--được bố trí bay bằng loại máy bay đó. Xuất ra mã loại và số lượng.
SELECT LB.MALOAI, COUNT(*) SOLUONGCHUYENBAY
FROM LICHBAY LB
WHERE LB.MALOAI IN (
	SELECT MALOAI
	FROM MAYBAY MB
	GROUP BY MALOAI
	HAVING COUNT(*) > 1
)
GROUP BY LB.MALOAI
