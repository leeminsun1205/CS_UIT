array = []
for i in range(3):
    array.append(list(map(int, input().split())))
n = int(input())
numbers = []
for i in range(n):
    numbers.append(int(input()))

checkRow = 0
for i in range(3):
    sum = 0
    for j in range(3):
        for k in range(n):
            if (array[i][j]==numbers[k]):
                sum += 1
            if(sum == 3): 
                checkRow = 1
                break
checkCol = 0
for i in range(3):
    sum = 0
    for j in range(3):
        for k in range(n):
            if (array[j][i]==numbers[k]):
                sum += 1
            if(sum == 3): 
                checkCol = 1
                break
                
checkDiag = 0
Diag = [[array[0][0], array[1][1], array[2][2]], [array[0][2], array[1][1], array[2][0]]]
for i in range(2):
    sum = 0
    for j in range(3):
        for k in range(n):
            if (Diag[i][j]==numbers[k]):
                sum+=1
            if(sum==3):
                checkDiag = 1
                break
if (checkRow or checkCol or checkDiag):
    print('Yes')
else:
    print('No')


