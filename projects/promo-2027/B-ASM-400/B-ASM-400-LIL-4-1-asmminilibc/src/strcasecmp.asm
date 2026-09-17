section .text
global strcasecmp

strcasecmp:
    .loop:
        xor eax, eax
        xor ebx, ebx
        mov al, [rdi]
        mov bl, [rsi]
        cmp al, 65
        jl .check
        cmp al, 90
        jg .check
        add al, 32

    .check:
        cmp bl, 65
        jl .validate
        cmp bl, 90
        jg .validate
        add bl, 32

    .validate:
        cmp al, bl
        jne .end
        test al, al
        jz .end
        inc rdi
        inc rsi 
        jmp .loop

    .end:
        sub eax, ebx
        ret
