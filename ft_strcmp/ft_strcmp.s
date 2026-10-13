; ft_strcmp.s

        global ft_strcmp

        section .text
ft_strcmp:
        xor rcx, rcx
.loop:
        movzx r8, byte [rdi + rcx]
        movzx rdx, byte [rsi + rcx]
        cmp r8b, dl
        jnz .diff
        cmp r8b, 0
        jz .match
        inc rcx
        jmp .loop
.diff:
        sub r8, rdx
        mov rax, r8
        ret
.match:
        xor rax, rax
        ret
