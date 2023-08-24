.data
_prompt: .asciiz "Enter an integer:"
_ret: .asciiz "\n"
.globl main
.text
read:
  li $v0, 4
  la $a0, _prompt
  syscall
  li $v0, 5
  syscall
  jr $ra

write:
  li $v0, 1
  syscall
  li $v0, 4
  la $a0, _ret
  syscall
  move $v0, $0
  jr $ra

fact:
  move $gp, $sp
  addi $sp, $sp, -4
    #allocate -4($gp) for t6
  addi $sp, $sp, -4
    #allocate -8($gp) for t5
  addi $sp, $sp, -4
    #allocate -12($gp) for t3
  lw $t0, 8($gp)
  li $t1, 1
  beq $t0, $t1, label0
  j label1
label0:
  lw $t2, 8($gp)
  move $v0, $t2
  jr $ra
  j label2
label1:
  lw $t3, -4($gp)
  lw $t4, 8($gp)
  addi $t3, $t4, -1
  sw $t3, -4($gp)
  lw $t5, -8($gp)
  addi $sp, $sp, -72
  sw $t0, 0($sp)
  sw $t1, 4($sp)
  sw $t2, 8($sp)
  sw $t3, 12($sp)
  sw $t4, 16($sp)
  sw $t5, 20($sp)
  sw $t6, 24($sp)
  sw $t7, 28($sp)
  sw $s0, 32($sp)
  sw $s1, 36($sp)
  sw $s2, 40($sp)
  sw $s3, 44($sp)
  sw $s4, 48($sp)
  sw $s5, 52($sp)
  sw $s6, 56($sp)
  sw $s7, 60($sp)
  sw $t8, 64($sp)
  sw $t9, 68($sp)
  addi $sp, $sp, -4
  lw $t6, -4($gp)
  sw $t6, 0($sp)
  addi $sp, $sp, -8
  sw $ra, 0($sp)
  sw $gp, 4($sp)
  jal fact
  move $sp, $gp
  lw $ra, 0($sp)
  lw $gp, 4($sp)
  addi $sp, $sp, 12
  lw $t0, 0($sp)
  lw $t1, 4($sp)
  lw $t2, 8($sp)
  lw $t3, 12($sp)
  lw $t4, 16($sp)
  lw $t5, 20($sp)
  lw $t6, 24($sp)
  lw $t7, 28($sp)
  lw $s0, 32($sp)
  lw $s1, 36($sp)
  lw $s2, 40($sp)
  lw $s3, 44($sp)
  lw $s4, 48($sp)
  lw $s5, 52($sp)
  lw $s6, 56($sp)
  lw $s7, 60($sp)
  lw $t8, 64($sp)
  lw $t9, 68($sp)
  addi $sp, $sp, 72
  move $t5, $v0
  sw $t5, -8($gp)
  lw $t7, -12($gp)
  lw $s0, 8($gp)
  lw $s1, -8($gp)
  mul $t7, $s0, $s1
  sw $t7, -12($gp)
  lw $s2, -12($gp)
  move $v0, $s2
  jr $ra
label2:

main:
  move $gp, $sp
  addi $sp, $sp, -4
    #allocate -4($gp) for t9
  addi $sp, $sp, -4
    #allocate -8($gp) for m
  addi $sp, $sp, -4
    #allocate -12($gp) for t13
  addi $sp, $sp, -4
    #allocate -16($gp) for result
  addi $sp, $sp, -4
    #allocate -20($gp) for result
  addi $sp, $sp, -4
  sw $ra, 0($sp)
  jal read
  lw $ra, 0($sp)
  addi $sp, $sp, 4
  lw $t0, -4($gp)
  move $t0, $v0
  sw $t0, -4($gp)
  lw $t1, -8($gp)
  lw $t2, -4($gp)
  move $t1, $t2
  sw $t1, -8($gp)
  lw $t3, -8($gp)
  li $t4, 1
  bgt $t3, $t4, label3
  j label4
label3:
  lw $t5, -12($gp)
  addi $sp, $sp, -72
  sw $t0, 0($sp)
  sw $t1, 4($sp)
  sw $t2, 8($sp)
  sw $t3, 12($sp)
  sw $t4, 16($sp)
  sw $t5, 20($sp)
  sw $t6, 24($sp)
  sw $t7, 28($sp)
  sw $s0, 32($sp)
  sw $s1, 36($sp)
  sw $s2, 40($sp)
  sw $s3, 44($sp)
  sw $s4, 48($sp)
  sw $s5, 52($sp)
  sw $s6, 56($sp)
  sw $s7, 60($sp)
  sw $t8, 64($sp)
  sw $t9, 68($sp)
  addi $sp, $sp, -4
  lw $t6, -8($gp)
  sw $t6, 0($sp)
  addi $sp, $sp, -8
  sw $ra, 0($sp)
  sw $gp, 4($sp)
  jal fact
  move $sp, $gp
  lw $ra, 0($sp)
  lw $gp, 4($sp)
  addi $sp, $sp, 12
  lw $t0, 0($sp)
  lw $t1, 4($sp)
  lw $t2, 8($sp)
  lw $t3, 12($sp)
  lw $t4, 16($sp)
  lw $t5, 20($sp)
  lw $t6, 24($sp)
  lw $t7, 28($sp)
  lw $s0, 32($sp)
  lw $s1, 36($sp)
  lw $s2, 40($sp)
  lw $s3, 44($sp)
  lw $s4, 48($sp)
  lw $s5, 52($sp)
  lw $s6, 56($sp)
  lw $s7, 60($sp)
  lw $t8, 64($sp)
  lw $t9, 68($sp)
  addi $sp, $sp, 72
  move $t5, $v0
  sw $t5, -12($gp)
  lw $t7, -16($gp)
  lw $s0, -12($gp)
  move $t7, $s0
  sw $t7, -16($gp)
  j label5
label4:
  lw $s1, -16($gp)
  li $s1, 1
  sw $s1, -16($gp)
label5:
  lw $s2, -16($gp)
  addi $sp, $sp, -8
  sw $a0, 0($sp)
  sw $ra, 4($sp)
  move $a0, $s2
  jal write
  lw $a0, 0($sp)
  lw $ra, 4($sp)
  addi $sp, $sp, 8
  move $v0, $0
  jr $ra
