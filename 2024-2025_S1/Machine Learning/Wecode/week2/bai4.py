# import time
import math
from decimal import Decimal, getcontext
#em có tham khảo chat gpt về thư viện decimal
# start_time = time.time()
getcontext().prec = 15001
n = Decimal(input())
thres = 15000
store = []
total = n

def rev(number):
    decimal = number
    rev_str = str(decimal)[::-1]
    rev_decimal = Decimal(rev_str)
    return rev_decimal


for i in range(0, 10001):
    if i == 0:
        if total == rev(total):
            print('NO')
            print(n)
            break
        if len(str(total)) > thres:
            print('YES')
            print(i, total, sep = ' ')
            break
    else:
        total += rev(total)
        store.append(total)
        if total == rev(total):
            print('NO')
            for i in store:
                print(i)
            break
        if len(str(total)) > thres:
            print('YES')
            print(i, total, sep = ' ')
            break
else:
    print('YES')
    print(10001, total+rev(total), sep = ' ')
# print(len(str(total)))
# end_time = time.time()
# print(end_time-start_time)