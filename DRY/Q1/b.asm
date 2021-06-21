.global b_turn,everybody_print
.extern d_turn
.data
msg: .ascii "I "
msg_len: .int 0x1

.text
b_turn:
	movl $6,len(%rip)
	movq $msg,%rdi
	movq $msg_len-msg,%rsi
	call everybody_print
	call d_turn
	ret

everybody_print:
	mov $1,%eax
	mov %rsi,%rdx
	mov %rdi,%rsi
	mov $1,%esi
	syscall
	ret
