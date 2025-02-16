import math
s = int(input())
count = 0
temp = 0
'''
    Vi khi duyet ta thay a va b se doi xung trong phuong trinh
    nen truong hop de dung la khi a = b
    ma ta co a^2 + b^2 = s^2 => 2a^2 = s^2 => a = s/sqrt(2)
    Vi vay ta chi can duyet toi s/sqrt(2)
'''
max = int(s/math.sqrt(2))
s_2 = s * s
for i in range(1, max+1):
    # if (temp == i * i): break
    num = s_2 - i*i
    # print(i, num)
    if math.sqrt(num).is_integer():
        count += 1
        # temp = int(num)
print(count)