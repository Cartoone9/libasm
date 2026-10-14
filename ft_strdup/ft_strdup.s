; ft_strdup.s

        global ft_strdup
        extern ft_strlen
        extern ft_strcpy
        extern malloc

        section .text
ft_strdup:
        push rbx
        mov rbx, rdi                   ; save the src ptr
        call ft_strlen                 ; len of src
        inc rax                        ; rax is len + 1 to account for the null byte

        mov rdi, rax                   ; first arg must be len + 1
        call malloc
        cmp rax, 0                     ; check for null
        je .done                       ; in that case ret

        mov rdi, rax                   ; first arg must be dest ptr
        mov rsi, rbx                   ; sec arg must be src ptr
        call ft_strcpy
.done:
        pop rbx
        ret
