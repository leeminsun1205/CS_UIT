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

--1.Cho biết số lượng đề án của công ty
SELECT COUNT(*) SLDA_CTY FROM DEAN

--2.Cho biết số lượng đề án do phòng “Nghiên cứu” chủ trì
SELECT COUNT(*) SLDA_NC 
FROM DEAN DA, PHONGBAN PB
WHERE DA.PHONG = PB.MAPHG AND TENPHG = N'Nghiên cứu'

--3.Cho biết lương trung bình của các nữ nhân viên
SELECT AVG(LUONG) LUONGTB_NU
FROM NHANVIEN
GROUP BY PHAI
HAVING PHAI = N'Nữ'

--4.Cho biết số thân nhân của nhân viên “Đinh Bá Tiến”
SELECT COUNT(*) SLTN_DBT 
FROM THANNHAN TN, NHANVIEN NV
WHERE TN.MA_NVIEN = NV.MANV AND HONV = N'Đinh' AND TENLOT = N'Bá' AND TENNV = N'Tiên'

--5.Với mỗi đề án, liệt kê tên đề án và tổng số giờ làm việc một tuần của tất cả nhân viên tham gia đề án đó.
SELECT TENDA, SUM(THOIGIAN) TONG_GLV 
FROM DEAN DA, PHANCONG PC
WHERE DA.MADA = PC.MADA
GROUP BY TENDA

--6.Với mỗi đề án, cho biết tên đề án và số nhân viên tham gia đề án.
SELECT TENDA, COUNT(MA_NVIEN) SLNV
FROM DEAN DA, PHANCONG PC
WHERE  DA.MADA = PC.MADA
GROUP BY TENDA

--7.Với mỗi nhân viên có số thân nhân lớn hơn 2, cho biết họ và tên nhân viên và số lượng thân nhân của nhân viên đó.
SELECT HONV + ' ' + TENLOT + ' ' + TENNV AS HOVATEN, COUNT(*) SLTN
FROM NHANVIEN NV LEFT JOIN THANNHAN TN
ON NV.MANV = TN.MA_NVIEN
GROUP BY HONV, TENLOT, TENNV
HAVING COUNT(TN.MA_NVIEN) > 2

--8.Với mỗi nhân viên, cho biết họ tên nhân viên và số lượng đề án mà nhân viên đó tham gia.
SELECT HONV + ' ' + TENLOT + ' ' + TENNV AS HOVATEN, COUNT(*) SLDA
FROM NHANVIEN NV, PHANCONG PC
WHERE NV.MANV = PC.MA_NVIEN
GROUP BY HONV, TENLOT, TENNV

--9.Với mỗi nhân viên, cho biết họ tên và số lượng nhân viên mà nhân viên đó quản lý trực tiếp.
SELECT NV.HONV + ' ' + NV.TENLOT + ' ' + NV.TENNV AS HOTEN, COUNT(QL.MA_NQL) SLNV_QL
FROM NHANVIEN NV LEFT JOIN NHANVIEN QL
ON NV.MANV = QL.MA_NQL
GROUP BY NV.HONV, NV.TENLOT, NV.TENNV

--10.Với mỗi phòng ban, liệt kê tên phòng ban và lương trung bình của những nhân viên làm việc cho phòng ban đó.
SELECT TENPHG, AVG(LUONG) LUONG_TB
FROM PHONGBAN PB, NHANVIEN NV
WHERE PB.MAPHG = NV.PHG
GROUP BY TENPHG

--11.Với các phòng ban có mức lương trung bình trên 40,000, liệt kê tên phòng ban và số lượng nhân viên của phòng ban đó.
SELECT TENPHG, COUNT(MANV) SLNV
FROM PHONGBAN PB, NHANVIEN NV
WHERE PB.MAPHG = NV.PHG
GROUP BY TENPHG
HAVING AVG(LUONG) > 40000

--12.Cho biết số đề án diễn ra tại từng địa điểm
SELECT B.DDIEM_DA, COUNT(A.MADA) SLDA
FROM DEAN A, DEAN B
WHERE A.MADA = B.MADA
GROUP BY B.DDIEM_DA

--13.Với mỗi đề án, cho biết tên đề án và số lượng công việc của đề án này.
SELECT TENDA, COUNT(CV.MADA) SLCV
FROM DEAN DA, CONGVIEC CV
WHERE DA.MADA = CV.MADA
GROUP BY TENDA

--14.Với mỗi công việc trong đề án có mã đề án “Dao Tao”, cho biết số lượng nhân viên được phân công
SELECT TEN_CONG_VIEC, COUNT(PC.MA_NVIEN) SLNV
FROM CONGVIEC CV, PHANCONG PC, DEAN DA
WHERE CV.MADA = PC.MADA AND PC.MADA = DA.MADA AND TENDA = 'Dao tao'
GROUP BY TEN_CONG_VIEC

--15.Với mỗi phòng ban có mức lương trung bình trên 30,000, cho biết tên phòng ban và số lượng đề án mà phòng ban đó chủ trì.
SELECT TENPHG, COUNT(DISTINCT MADA) SLDA
FROM PHONGBAN PB, DEAN DA, NHANVIEN NV
WHERE PB.MAPHG = DA.PHONG AND DA.PHONG = NV.PHG
GROUP BY TENPHG
HAVING AVG(LUONG) > 30000

--16.Với mỗi phòng ban, cho biết tên phòng ban và số lượng đề án mà phòng ban đó chủ trì yêu cầu giảm dần theo số lượng đề án.
SELECT TENPHG, COUNT(DA.MADA) SLDA
FROM PHONGBAN PB, DEAN DA
WHERE PB.MAPHG = DA.PHONG 
GROUP BY TENPHG
ORDER BY COUNT(MADA) DESC
