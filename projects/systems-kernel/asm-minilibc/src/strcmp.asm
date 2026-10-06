section .text
global strcmp

strcmp:
    .loop:
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

    .end:
        sub eax, ebx
        ret
