import math
a = list(map(int, input().split()))
b = list(map(int, input().split()))
xA, yA, xB, yB = a[0], a[1], b[0], b[1]

''' 
    Em tham khao kien thuc ve phep quay o day
    #https://vuihoc.vn/tin/thpt-phep-quay-624.html
    
'''

#Phep quay tam B goc 90 do cung chieu kim dong ho
c1 = [xB - (yB - yA), yB + (xB - xA)]
xC1, yC1 = c1
#Phep quay tam A goc 90 do nguoc chieu kim dong ho
d1 = [xA - (yB - yA), yA + (xB - xA)]
xD1, yD1 = d1
#Phep quay tam B goc 90 do nguoc chieu kim dong ho
c2 = [xB + (yB - yA), yB - (xB - xA)]
xC2, yC2 = c2
#Phép quay tam A goc 90 do cung chieu kim dong ho
d2 = [xA + (yB - yA), yA - (xB - xA)]
xD2, yD2 = d2


print('(', xA, ', ', yA, ')', end = ' ', sep ='')
print('(', xD1, ', ', yD1, ')', end = ' ', sep ='')
print('(', xC1, ', ', yC1, ')', end = ' ', sep ='')
print('(', xB, ', ', yB, ')', end = '\n', sep ='')
print('(', xA, ', ', yA, ')', end = ' ', sep ='')
print('(', xB, ', ', yB, ')', end = ' ', sep ='')
print('(', xC2, ', ', yC2, ')', end = ' ', sep ='')
print('(', xD2, ', ', yD2, ')', end = '\n', sep ='')

