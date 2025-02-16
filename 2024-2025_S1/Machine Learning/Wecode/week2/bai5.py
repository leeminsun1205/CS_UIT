import re, sys
syntax = r'([0-9A-F]{2}-){5}[0-9A-F]{2}'
while(1):
    s = sys.stdin.readline().strip()
    # print(s)
    if s == '.': break
    if len(s) != 17:
        print('false')
    else:
        if re.search(syntax, s):
            print('true')
        else:
            print('false')
        