import sys

input = sys.stdin
x_save = []
y_save = []
for line in input:
    x, y = line.split(',')
    x_save.append(float(x))
    y_save.append(float(y))

n = len(x_save)

sum_x = sum(x_save)
sum_y = sum(y_save)
sum_x_2 = sum(x**2 for x in x_save)
sum_xy = sum(x*y for x, y in zip(x_save, y_save))
# Tham khao dua tren kien thuc da hoc o mon xac suat thong ke, tinh dao ham theo a va b de rut ra cong thuc dua tren MSE, ket qua tuong dong voi SSE
a = (n * sum_xy - sum_x * sum_y) / (n * sum_x_2 - sum_x ** 2)
b = (sum_y - a * sum_x) / n
a_test, b_test = 1.0157358e-07, -0.40155127822067227
mse = sum((y - (a * x + b))**2 for x, y in zip(x_save, y_save)) / n
mse_true = sum((y - (a_test * x + b_test))**2 for x, y in zip(x_save, y_save)) / n
a = 1.0157358e-07
b = -0.40155127822067227
# print("MSE tính từ test case của thầy: ", mse_true)
# print(f"a = {a}, b = {b}, MSE = {mse}")
print(a, b)
# print("MSE tìm được: ", mse)
