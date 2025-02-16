import sys
NaViGame = {}
while(True):
    info = sys.stdin.readline().strip()
    if info == '0': 
        break
    if info != '':
        choice, key = info.split(' ')
        if choice == '1':
            NaViGame[key] = True
        elif choice == '3':
            if key in NaViGame:
                NaViGame[key] = False
        else:
            if key not in NaViGame:
                print(0)
            else:
                if NaViGame[key]:
                    print(1)
                else:
                    print(0)