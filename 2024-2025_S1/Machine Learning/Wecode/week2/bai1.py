import math
n = int(input())
def is_prime(n):
    for i in range(2, math.isqrt(n)+1):
        if (n % i == 0):
            return False
    return True

count = 0
for i in range(2, n//2+1):
    if (is_prime(n - i) and is_prime(i)):
        count += 1
print(count)
