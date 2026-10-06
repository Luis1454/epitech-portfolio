section .text
global strncmp

strncmp:
    test rdx, rdx
    jz .empty

    .loop:
        dec rdx
        jz .end
        xor eax, eax
        xor ebx, ebx
        mov al, byte [rdi]
        mov bl, byte [rsi]
        cmp al, bl
        jne .end
        test al, al
        jz .end
        inc rdi
        inc rsi
        jmp .loop

    .empty:
        xor eax, eax
        ret

    .end:
        sub eax, ebx
        ret
