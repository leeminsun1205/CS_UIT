import sys
# import math
'''
    Em va ban Tang Nhat co trao doi y tuong voi nhau, bang cac bien phap do luong va tinh toan thay duoc rang f(x) la 1 phuong trinh bac 3 thi cho MSE kha tot.
    Tui em da su dung thu vien numpy de giai thu he so thi ket qua MSE la tot hon so voi ham ma thay cung cap o output.
    Tuy nhien viec thuc hien lai kha la kho khan cho nen em da tham khao 1 so cach giai, phuong phap tu nhieu nguon cung nhu chat gpt 
    thi cuoi cung em chon cach giai he phuong trinh tuyen tinh bang ma tran nghich dao de tim cac he so a, b, c, d cua phuong trinh f(x)=a*x**3 + b*x**2 + c*x + d.
'''
input = sys.stdin
x_save = []
y_save = []
for line in input:
    x, y = line.split(',')
    x_save.append(float(x))
    y_save.append(float(y))

n = len(x_save)
'''
    Nguon tham khao cach tinh det cua ma tran 4x4:
    https://stackoverflow.com/questions/63766815/determinate-of-a-singular-4x4-matrix-is-non-zero-using-numpy-det
'''
def det(A): 
    if (len(A) == 2):
        return (A[0][0]*A[1][1] - A[0][1]*A[1][0])
    elif (len(A) == 3):
        a= A[0][0]* (A[1][1]* A[2][2] - A[2][1]* A[1][2]) 
        b= A[0][1]* (A[1][0]* A[2][2] - A[2][0]*A[1][2]) 
        c= A[0][2]* (A[1][0]* A[2][1] - A[2][0]*A[1][1])                     
        return(a-b+c)     
    elif (len(A) == 4):
        a1, a2, a3, a4 = 0, 0, 0, 0
        a1= A[0][0]* (A[1][1]* (A[2][2]* A[3][3] - A[3][2]* A[2][3]) - A[1][2]* (A[2][1]* A[3][3] - A[3][1]*A[2][3])+  A[1][3]* (A[2][1]* A[3][2] - A[3][1]*A[2][2]))
        a2= A[0][1]* (A[1][0]* (A[2][2]* A[3][3] - A[3][2]* A[2][3]) - A[1][2]* (A[2][0]* A[3][3] - A[3][0]*A[2][3])+ A[1][3]* (A[2][0]* A[3][2] - A[3][0]*A[2][2])) 
        a3= A[0][2]* (A[1][0]* (A[2][1]* A[3][3] - A[3][1]* A[2][3]) - A[1][1]* (A[2][0]* A[3][3] - A[3][0]*A[2][3])+  A[1][3]* (A[2][0]* A[3][1] - A[3][0]*A[2][1])) 
        a4= A[0][3]* (A[1][0]* (A[2][1]* A[3][2] - A[3][1]* A[2][2]) - A[1][1]* (A[2][0]* A[3][2] - A[3][0]*A[2][2])+  A[1][2]* (A[2][0]* A[3][1] - A[3][0]*A[2][1]))
    return a1-a2+a3-a4   
#Tinh ma tran chuyen vi
def trans(matrix):
    return [[matrix[j][i] for j in range(4)] for i in range(4)]
#Tham khao chat gpt cach tim ma tran dai so phu tro
def cof(A):
    cof_A = [[0, 0, 0, 0] for _ in range(4)]
    for i in range(4):
        for j in range(4):
            minor = [[A[x][y] for y in range(4) if y != j] for x in range(4) if x != i]
            cof_A[i][j] = det(minor)
            if (i + j) % 2 != 0:
                cof_A[i][j] = -cof_A[i][j]
    return cof_A
#Tinh ma tran nghich dao
def inv(A):
    det_A = det(A)
    cof_A = cof(A)
    A_star = trans(cof_A)
    return [[A_star[i][j] / det_A for j in range(4)] for i in range(4)]
#Nhan 2 ma tran
def dot(A, B):
    return [sum(A[i][j] * B[j] for j in range(4)) for i in range(4)]

A = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 0]]
B = [0, 0, 0, 0]
'''
    Cac gia tri nay co duoc khi lay dao ham theo a, b, c, d va dat Da, Db, Dc, Dd = 0 (voi Dx la dao ham theo bien x)
    Sau khi nhan vao va chuyen ve se xuat hien 2 ma tran A va B 
    Dung phuong phap giai he phuong trinh tuyen tinh tu A va B de tim ra a, b, c, d
    Thay co the tham khao them trong sach nay: "Linear Algebra and Its Applications"-Gilbert Strang
'''
for i in range(n):
    x_i = x_save[i]
    y_i = y_save[i]

    A[0][0] += x_i**8
    A[0][1] += x_i**6
    A[0][2] += x_i**5
    A[0][3] += x_i**4

    A[1][0] += x_i**6
    A[1][1] += x_i**4
    A[1][2] += x_i**3
    A[1][3] += x_i**2

    A[2][0] += x_i**5
    A[2][1] += x_i**3
    A[2][2] += x_i**2
    A[2][3] += x_i

    A[3][0] += x_i**4
    A[3][1] += x_i**2
    A[3][2] += x_i
    A[3][3] += 1

    B[0] += y_i*x_i**4
    B[1] += y_i*x_i**2
    B[2] += y_i*x_i
    B[3] += y_i

a, b, c, d = dot(inv(A), B)

# a_0 = 1.6497423039747624e-07
# b_0 = -2.4504033093402677
# c_0 = 58.90213573241223

print(f"{a}*x**4 + {b}*x**2+ {c}*x + {d}")
'''
    Mot cach don gian hon la dung thu vien np.polyfit() tá»« numpy, nhung do thoi gian thay set khong du de import duoc thu vien va em chon giai quyet bang cach o tren,
    nen mong thay thong cam kha la kho giai nen can nhieu nguon de tham khao
'''
# print(f"given_MSE: {sum((y - (a_0 * x + b_0 * math.log2(x) + c_0))**2 for x, y in zip(x_save, y_save)) / n}")
# print(f"MSE: {sum((y - (a * x ** 4 + b * x ** 2 + c * x + d))**2 for x, y in zip(x_save, y_save)) / n}")