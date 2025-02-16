#Su dung backtracking da tung hoc o mon Phan tich va thiet ke thuat toan
def check_valid(sub):
    if sub:
        valid = int(sub)
        if 0 <= valid <= 255:
            if len(sub) == 2 and sub[0] == '0' or len(sub) == 3 and (sub[0] == '0' or sub[0] == '0' and sub[1] == '0'):
                return False
            return True
    return False

def IP_process(i, part, wrong_IP, solution):
    for j in range(i + 1, len(wrong_IP) + 1):
        sub = wrong_IP[i:j]
        if len(sub) <= 3:
            if check_valid(sub):
                if part <= 3:
                    solution.append(sub + ".")
                else:
                    solution.append(sub)
                if part == 4 and j == len(wrong_IP):
                    print(''.join(solution))
                else:
                    IP_process(j, part + 1, wrong_IP, solution)
                solution.pop()

wrong_IP = input()
if len(wrong_IP) <= 12:
    solution = []
    IP_process(0, 1, wrong_IP, solution)