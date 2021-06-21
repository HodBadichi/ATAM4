.global a_1, _start,msg ,msg_len
.extern b_turn

.data
a_1: .int 0x4
msg: .ascii "i`m excited to see what will be printed\n"
msg_len: .quad msg_len - msg

.text
_start:
	movq $msg, %rdi
	movq (msg_len), %rsi
	call my_print
	call b_turn
	mov %rax,%rdi
	mov $60,%rax
	syscall
my_print:
	mov $1,%eax
	mov %rsi,%rdx
	mov %rdi,%rsi
	syscall
	ret
