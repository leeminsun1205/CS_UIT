arr = []
for i in range(4):
    arr.append(list(map(int, input().split())))
move = None
while(True):
    move = input() 
    if move != '':
        break

def del_zero(row):
    return [i for i in row if i != 0]

def process_L(arr):
    new_arr = []
    for row in arr:
        new_row = del_zero(row)
        if (len(row)!=0):
            for i in range(len(new_row)-1):
                if new_row[i] == new_row[i+1]:
                    new_row[i] *= 2
                    new_row[i+1] = 0
            new_row = del_zero(new_row)
            row = new_row + [0] * (4 - len(new_row))   
            new_arr.append(row)   
    return new_arr
def process_R(arr):
    new_arr = []
    for row in arr:
        new_row = del_zero(row)
        if (len(row)!=0):
            for i in range(len(new_row)-1, 0, -1):
                if new_row[i] == new_row[i-1]:
                    new_row[i] *= 2
                    new_row[i-1] = 0
            new_row = del_zero(new_row)
            row = [0] * (4 - len(new_row)) + new_row      
            new_arr.append(row)      
    return new_arr
def trans_arr(arr):
    return [[row[i] for row in arr] for i in range(len(arr[0]))]
            
def process_U(arr):
    temp = trans_arr(arr)
    return trans_arr(process_L(temp))
def process_D(arr):
    temp = trans_arr(arr)
    return trans_arr(process_R(temp))
new_arr = None
if move == 'L':
    new_arr = process_L(arr)
elif move == 'R':
    new_arr = process_R(arr)
elif move == 'U':
    new_arr = process_U(arr)
elif move == 'D':
    new_arr = process_D(arr)
for i in new_arr:
    print(" ".join(map(str, i)))
            
