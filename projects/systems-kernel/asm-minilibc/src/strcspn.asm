section .text
global strcspn

strcspn:
    mov rdx, rdi

    .loop:
        mov al, byte [rdi]
        test al, al
        jz .end
        mov rcx, rsi

    .is_valid:
        cmp byte [rcx], 0
        jz .ko
        cmp al, byte [rcx]
        je .end
        inc rcx
        jmp .is_valid

    .ko:
        inc rdi
        jmp .loop

    .end:
        sub rdi, rdx
        mov rax, rdi
        ret
