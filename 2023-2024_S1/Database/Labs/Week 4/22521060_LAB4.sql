Create table NHANVIEN
(
	HONV nvarchar(15),
	TENLOT nvarchar(15),
	TENNV nvarchar(15),
	MANV nvarchar(9),
	NGSINH datetime,
	DCHI nvarchar(30),
	PHAI nvarchar(3),
	LUONG float,
	MA_NQL nvarchar(9),
	PHG int,
	PRIMARY KEY (MANV)
)

Create table PHONGBAN 
(
	TENPHG nvarchar(15),
	MAPHG int,
	TRPHG nvarchar(15),
	NG_NHANCHUC datetime,
	PRIMARY KEY (MAPHG)
)

Create table DIADIEM_PHG
(
	MAPHG int,
	DIADIEM nvarchar(15),
	PRIMARY KEY (MAPHG, DIADIEM) 
)

Create table DEAN
(
	TENDA nvarchar(15),
	MADA int,
	DDIEM_DA nvarchar(15),
	PHONG int,
	PRIMARY KEY (MADA)
)

Create table CONGVIEC
(
	MADA int,
	STT int,
	TEN_CONG_VIEC nvarchar(50),
	PRIMARY KEY (MADA, STT)
)

Create table PHANCONG
(
	MA_NVIEN nvarchar(9),
	MADA int,
	STT int,
	THOIGIAN float,
	PRIMARY KEY (MA_NVIEN, MADA)
)

Create table THANNHAN
(
	MA_NVIEN nvarchar(9),
	TENTN nvarchar(15),
	PHAI nvarchar(3),
	NGSINH datetime,
	QUANHE nvarchar(15),
	PRIMARY KEY (MA_NVIEN, TENTN)
)

Insert into NHANVIEN values (N'Đinh', N'Bá', N'Tiên', '009', '1960/02/11', N'119 Cống Quỳnh, Tp HCM', 'Nam', 30000, '005', 5)
Insert into NHANVIEN values (N'Nguyễn', N'Thanh', N'Tùng', '005', '1962/08/20', N'222 Nguyễn Văn Cừ, Tp HCM', 'Nam', 40000, '006', 5)
Insert into NHANVIEN values (N'Bùi', N'Ngọc', N'Hằng', '007', '1954/03/11', N'332 Nguyễn Thái Học, Tp HCM', 'Nam', 25000, '001', 4)
Insert into NHANVIEN values (N'Lê', N'Quỳnh', N'Như', '001', '1967/02/01', N'291 Hồ Văn Huê, Tp HCM', N'Nữ', 43000, '006', 4)
Insert into NHANVIEN values (N'Nguyễn', N'Mạnh', N'Hùng', '004', '1967/03/04', N'95 Bà Rịa, Vũng Tàu', 'Nam', 38000, '005', 5)
Insert into NHANVIEN values (N'Trần', N'Thanh', N'Tâm ', '003 ', '1957/05/04', N'34 Mai Thị Lự, Tp HCM', 'Nam', 25000, '005', 5)
Insert into NHANVIEN values (N'Trần', N'Hồng', N'Quang', '008', '1967/09/01', N'80 Lê Hồng Phong, Tp HCM', 'Nam', 25000, '001', 4)
Insert into NHANVIEN values (N'Phạm', N'Văn', N'Vinh ', '006', '1965/01/01 ', N'45 Trưng Vương, Hà Nội', N'Nữ', 55000 , null, 1)

Insert into PHONGBAN values (N'Nghiên cứu', 5, '005', '1978/05/22')
Insert into PHONGBAN values (N'Điều hành', 4, '008', '1985/01/01')
Insert into PHONGBAN values (N'Quản lý', 1, '006', '1971/06/19')

Insert into DEAN values ('San pham X', 1, N'Vũng Tàu', 5)
Insert into DEAN values ('San pham Y', 2, N'Nha Trang', 5)
Insert into DEAN values ('San pham Z', 3, N'TP HCM', 5)
Insert into DEAN values ('Tin hoc hoa', 10, N'Hà Nội', 4)
Insert into DEAN values ('Cap quang ', 20, N'TP HCM', 1)
Insert into DEAN values ('Dao tao', 30, N'Hà Nội', 4)

Insert into DIADIEM_PHG values (1, 'TP HCM')
Insert into DIADIEM_PHG values (4, N'Hà Nội')
Insert into DIADIEM_PHG values (5, 'TAU')
Insert into DIADIEM_PHG values (5, 'NHA TRANG')
Insert into DIADIEM_PHG values (5, 'TP HCM')

Insert into PHANCONG values ('009', 1, 1, 32)
Insert into PHANCONG values ('009', 2, 2, 8)
Insert into PHANCONG values ('004', 3, 1, 40)
Insert into PHANCONG values ('003', 1, 2, 20.0)
Insert into PHANCONG values ('003', 2, 1, 20.0)
Insert into PHANCONG values ('008', 10, 1, 35)
Insert into PHANCONG values ('008', 30, 2, 5)
Insert into PHANCONG values ('001', 30, 1, 20)
Insert into PHANCONG values ('001', 20, 1, 15)
Insert into PHANCONG values ('006', 20, 1, 30)
Insert into PHANCONG values ('005', 3, 1, 10)
Insert into PHANCONG values ('005', 10, 2, 10)
Insert into PHANCONG values ('005', 20, 1, 10)
Insert into PHANCONG values ('007', 30, 2, 30)
Insert into PHANCONG values ('007', 10, 2, 10)

Insert into CONGVIEC values (1, 1, 'Thiet ke san pham X')
Insert into CONGVIEC values (1, 2, 'Thu nghiem san pham X')
Insert into CONGVIEC values (2, 1, 'San xuat san pham Y')
Insert into CONGVIEC values (2, 2, 'Quang cao san pham Y')
Insert into CONGVIEC values (3, 1, 'Khuyen mai san pham Z')
Insert into CONGVIEC values (10, 1, 'Tin hoc hoa nhan su tien luong')
Insert into CONGVIEC values (10, 2, 'Tin hoc hoa phong Kinh doanh')
Insert into CONGVIEC values (20, 1, 'Lap dat cap quang')
Insert into CONGVIEC values (30, 1, 'Dao tao nhan vien Marketing')
Insert into CONGVIEC values (30, 2, 'Dao tao chuyen vien vien thiet ke')

Insert into THANNHAN values ('005', N'Trinh', N'Nữ', '1976/04/05', N'Con gái')
Insert into THANNHAN values ('005', N'Khang', 'Nam', '1973/10/25', N'Con trai')
Insert into THANNHAN values ('005', N'Phương', N'Nữ', '1948/05/03', N'Vợ chồng')
Insert into THANNHAN values ('001', N'Minh', 'Nam', '1932/02/29', N'Vợ chồng')
Insert into THANNHAN values ('009', N'Tiến', 'Nam', '1978/01/01', N'Con trai')
Insert into THANNHAN values ('009', N'Châu', N'Nữ', '1978/12/30', N'Con gái')
Insert into THANNHAN values ('009', N'Phương', N'Nữ', '1957/05/05', N'Vợ chồng')

--1. Cho biết danh sách các đề án (MADA) có: nhân công với họ (HONV) là 'Dinh' hoặc, 
--có người trưởng phòng chủ trì đề án với họ (HONV) là 'Dinh'.
(SELECT MADA 
FROM PHANCONG PC, NHANVIEN NV
WHERE PC.MA_NVIEN = NV.MANV AND HONV = N'Đinh')
UNION 
(SELECT MADA 
FROM DEAN DA, PHONGBAN PB, NHANVIEN NV
WHERE DA.PHONG = PB.MAPHG AND PB.TRPHG = NV.MANV AND HONV = N'Đinh') 

--2. Danh sách những nhân viên (HONV, TENLOT, TENNV) có trên 2 thân nhân.
(SELECT HONV, TENLOT, TENNV
FROM THANNHAN, NHANVIEN
WHERE MA_NVIEN = MANV
GROUP BY HONV, TENLOT, TENNV
HAVING COUNT(MA_NVIEN) > 2)

--3. Danh sách những nhân viên (HONV, TENLOT, TENNV) không có thân nhân nào.
SELECT HONV, TENLOT, TENNV 
FROM NHANVIEN 
WHERE NOT EXISTS 
(SELECT * FROM THANNHAN
WHERE MANV = MA_NVIEN)

--4. Danh sách những trưởng phòng (HONV, TENLOT, TENNV) có tối thiểu một thân nhân.
(SELECT HONV, TENLOT, TENNV
FROM THANNHAN TN, NHANVIEN NV, PHONGBAN PB
WHERE TN.MA_NVIEN = NV.MANV AND NV.MANV = PB.TRPHG
GROUP BY HONV, TENLOT, TENNV
HAVING COUNT(MA_NVIEN) >= 1)

--5. Tìm họ tên (HONV, TENNV) của những trưởng phòng chưa có gia đình.
SELECT HONV, TENNV 
FROM NHANVIEN NV, PHONGBAN PB
WHERE NV.MANV = PB.TRPHG AND NOT EXISTS 
(SELECT * FROM THANNHAN
WHERE MANV = MA_NVIEN)

--6. Cho biết họ tên nhân viên (HONV, TENLOT, TENNV) có mức lương lớn hơn mức 
--lương của một nhân viên nào đó của phòng "Nghiên cứu"
SELECT HONV, TENLOT, TENNV 
FROM NHANVIEN
WHERE LUONG > ANY 
(SELECT LUONG 
FROM NHANVIEN, PHONGBAN
WHERE PHG = MAPHG AND TENPHG = N'Nghiên cứu')

--7. Cho biết tên phòng ban và họ tên trưởng phòng của phòng ban có đông nhân viên nhất.
SELECT TOP 1 WITH TIES TENPHG, NV2.HONV + ' ' + NV2.TENLOT + ' ' + NV2.TENNV HTEN_TRPHG
FROM NHANVIEN NV1, PHONGBAN PB, NHANVIEN NV2
WHERE NV1.PHG = PB.MAPHG AND PB.TRPHG = NV2.MANV
GROUP BY TENPHG, NV2.HONV, NV2.TENLOT, NV2.TENNV
ORDER BY COUNT(NV1.MANV) DESC

--8. Cho biết danh sách các mã đề án mà nhân viên có mã là 007 chưa làm
SELECT MADA 
FROM DEAN DA
WHERE NOT EXISTS
(SELECT * FROM PHANCONG PC
WHERE DA.MADA = PC.MADA AND MA_NVIEN = '007')

--9. Cho biết danh sách các mã đề án phòng 4 mà nhân viên có mã là 007 chưa làm
SELECT MADA 
FROM DEAN DA
WHERE PHONG = 4 AND NOT EXISTS
(SELECT * FROM PHANCONG PC
WHERE DA.MADA = PC.MADA AND MA_NVIEN = '007')

--10.Cho biết danh sách các công việc (tên công việc) trong đề án ‘Sản phẩm X’ mà nhân 
--viên có mã là 009 chưa làm.
SELECT TEN_CONG_VIEC
FROM CONGVIEC CV, DEAN DA
WHERE CV.MADA = DA.MADA AND TENDA = 'San pham X' AND NOT EXISTS
(SELECT * FROM CONGVIEC, PHANCONG PC
WHERE CONGVIEC.MADA = PC.MADA AND CONGVIEC.STT = PC.STT AND CV.TEN_CONG_VIEC = CONGVIEC.TEN_CONG_VIEC 
AND MA_NVIEN = '009')

--11.Tìm họ tên (HONV, TENLOT, TENNV) và địa chỉ (DCHI) của những nhân viên 
--làm việc cho một đề án ở ‘TP HCM’ nhưng phòng ban mà họ trực thuộc lại không 
--tọa lạc ở thành phố ‘TP HCM’
(SELECT HONV, TENLOT, TENNV, DCHI
FROM NHANVIEN NV, DEAN DA
WHERE NV.PHG = DA.PHONG AND DDIEM_DA = 'TP HCM')
EXCEPT
(SELECT HONV, TENLOT, TENNV, DCHI
FROM NHANVIEN NV, DEAN DA, DIADIEM_PHG DDP
WHERE NV.PHG = DA.PHONG AND DA.PHONG = DDP.MAPHG AND DDIEM_DA = 'TP HCM' AND DDP.DIADIEM = 'TP HCM')
