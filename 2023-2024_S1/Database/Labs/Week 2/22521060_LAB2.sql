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
-- 1.Tìm những nhân viên làm việc ở phòng số 4
SELECT * FROM NHANVIEN WHERE PHG = 4
-- 2.Tìm những nhân viên có mức lương trên 30000
SELECT * FROM NHANVIEN WHERE LUONG > 30000
-- 3.Tìm các nhân viên có mức lương trên 25000 ở phòng 4 hoặc các nhân viên có mức lương trên 30000 ở phòng 5
SELECT * FROM NHANVIEN WHERE (LUONG > 25000 AND PHG = 4) OR (LUONG > 30000 AND PHG = 5)
-- 4.Cho biết họ tên đầy đủ của nhân viên ở TP HCM
SELECT HONV + ' ' + TENLOT + ' ' + TENNV AS HOVATEN FROM NHANVIEN WHERE DCHI LIKE '%HCM'
-- 5.Cho biết họ tên đầy đủ của nhân viên có họ bắt đầu bằng ký tự ‘N’
SELECT HONV + ' ' + TENLOT + ' ' + TENNV AS HOVATEN FROM NHANVIEN WHERE HONV LIKE 'N%'
-- 6.Cho biết các nhân viên sinh từ năm 1960 đến 1965
SELECT * FROM NHANVIEN WHERE YEAR(NGSINH) BETWEEN 1960 AND 1965
-- 7.Cho biết nhân viên và năm sinh của nhân viên
SELECT HONV, TENLOT, TENNV, YEAR(NGSINH) NAMSINH FROM NHANVIEN
-- 8.Cho biết nhân viên và tuổi của nhân viên 
SELECT HONV, TENLOT, TENNV, DATEDIFF(YYYY, NGSINH, GETDATE()) AS TUOI FROM NHANVIEN 
-- 9.Với mỗi phòng ban, cho biết tên phòng ban và địa điểm phòng 
SELECT TENPHG, DIADIEM FROM PHONGBAN PB, DIADIEM_PHG DDP WHERE PB.MAPHG = DDP.MAPHG
-- 10.Tìm tên những người trưởng phòng của từng phòng ban
SELECT TENNV FROM NHANVIEN NV, PHONGBAN PB WHERE NV.MANV = PB.TRPHG
-- 11.Tìm tên và địa chỉ của tất cả các nhân viên của phòng "Nghiên cứu".
SELECT TENNV, DCHI FROM NHANVIEN NV, PHONGBAN PB WHERE NV.PHG = PB.MAPHG AND PB.TENPHG = N'Nghiên cứu'
-- 12.Với mỗi đề án ở Hà Nội, cho biết tên đề án, tên phòng ban, họ tên và ngày nhận chức của trưởng phòng của phòng ban chủ trì đề án đó.
SELECT TENDA, TENPHG, HONV, TENNV, NG_NHANCHUC FROM DEAN, PHONGBAN, NHANVIEN 
WHERE DEAN.PHONG = PHONGBAN.MAPHG AND PHONGBAN.TRPHG = NHANVIEN.MANV AND DDIEM_DA = N'Hà Nội'
-- 13.Với mỗi nhân viên, cho biết tên nhân viên và tên người quản lý trực tiếp của nhân viên đó
SELECT A.TENNV, B.TENNV FROM NHANVIEN A , NHANVIEN B WHERE A.MA_NQL = B.MANV
-- 14.Tìm tên những nữ nhân viên và tên người thân của họ
SELECT TENNV, TENTN FROM NHANVIEN NV INNER JOIN  THANNHAN TN ON NV.MANV = TN.MA_NVIEN WHERE NV.PHAI = N'Nữ'
