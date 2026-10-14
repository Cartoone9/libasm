; ft_read.s

        global ft_read
        extern __errno_location

        section .text
ft_read:
        xor rax, rax                   ; this sets rax to 0, which happens to be read syscall value
        syscall
        cmp rax, 0
        jl .error
        ret
.error:
        neg rax
        push rax
        call __errno_location
        pop rdx
        mov [rax], edx
        mov rax, -1
        ret
