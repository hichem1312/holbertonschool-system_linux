BITS 64

global asm_strlen
section .text

asm_strlen:
	push rbp
	mov rbp, rsp
	mov rax, 0


loop:
	cmp byte [rdi], 0
	je 	exit
	inc rax
	inc rdi
	jmp loop

exit:
	mov rsp, rbp
	pop rbp
	ret