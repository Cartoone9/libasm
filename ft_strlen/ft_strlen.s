; ft_strlen.s

        global ft_strlen

        section .text
ft_strlen:
        xor rcx, rcx
.loop:
        movzx rdx, byte [rdi + rcx]
        cmp dl, 0
        jz .done
        inc rcx
        jmp .loop
.done:
        mov rax, rcx
        ret
