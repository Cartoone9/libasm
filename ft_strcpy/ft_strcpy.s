; ft_strcpy.s

        global ft_strcpy

        section .text
ft_strcpy:
        xor rcx, rcx
.loop:
        movzx rdx, byte [rsi + rcx]
        mov [rdi + rcx], dl
        cmp dl, 0
        jz .done
        inc rcx
        jmp .loop
.done:
        mov rax, rdi
        ret
