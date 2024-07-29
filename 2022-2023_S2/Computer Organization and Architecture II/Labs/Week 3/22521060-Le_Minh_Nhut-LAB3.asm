.data
    name: .space 32       
    id: .space 4         
    string1: .asciiz "Moi ban nhap ho va ten sinh vien: "
    string2: .asciiz "Moi ban nhap ma so sinh vien: "
    newline: .asciiz "\n"
    output1: .asciiz "Ho va ten: "
    output2: .asciiz "Ma so sinh vien: "

.text
main:
    li $v0, 4
    la $a0, string1
    syscall

    li $v0, 8
    la $a0, name
    li $a1, 32
    syscall

    li $v0, 4
    la $a0, string2
    syscall

    li $v0, 5
    syscall
    move $t0, $v0

    li $v0, 4
    la $a0, newline
    syscall
    la $a0, output1
    syscall
    la $a0, name
    syscall
    la $a0, output2
    syscall
    move $a0, $t0
    li $v0, 1
    syscall

    li $v0, 10
    syscall
