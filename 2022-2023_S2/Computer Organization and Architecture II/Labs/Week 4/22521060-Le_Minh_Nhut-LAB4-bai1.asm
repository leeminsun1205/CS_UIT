#if (i==j)
# f= g+h;
#else
# f=g-h;
# V?i giá trij c?a i, j, f, g, h l?n l??t ch?a trong các thanh ghi $s0, $s1, $s2, $t0, $t1
	addi $s0, $0, 8
	addi $s1, $0, 9
	addi $t0, $0, 6
	addi $t1, $0, 5
	bne $s0, $s1, ELSE
IF:
	add $s2, $t0, $t1 # f = g + h;
	j EXIT
ELSE:
	sub $s2, $t0, $t1 # f = g - h;
EXIT:
