import re
'''
    Em da tung su dung qua thu vien 're' nhung quen cu phap 
    nen co su dung chat gpt de kiem tra cu phap
'''
costs = list(map(int, input().split()))
notifies = []
for i in range(len(costs)):
    notifies.append(input())
money = int(input())
if (sum(costs) <= money):
    print('true')
else:
    lower = r'(\d+(\.\d+)?)% lower than in-store'
    higher = r'(\d+(\.\d+)?)% higher than in-store'
    Sum = 0
    for i in range(len(costs)):
        find1 = re.search(higher, notifies[i])
        find2 = re.search(lower, notifies[i])
        if find1:
            Sum += costs[i]*(1 + float(find1.group(1))/100)
        if find2: 
            Sum += costs[i]*(1 - float(find2.group(1))/100)
    if (money >= Sum):
        print('true')
    else:
        print('false')
