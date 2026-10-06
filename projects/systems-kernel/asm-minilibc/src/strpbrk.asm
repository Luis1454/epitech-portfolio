section .text
global strpbrk

strpbrk:
    mov rcx, rsi

    .check:
        mov al, [rdi]
        test al, al
        jz .ko
        mov rsi, rcx

    .loop:
        mov bl, [rsi]
        test bl, bl
        jz .sub_loop
        cmp al, bl
        je .ok
        inc rsi
        jmp .loop

    .sub_loop:
        inc rdi
        jmp .check

    .ok:
        mov rax, rdi
        ret

    .ko:
        xor rax, rax
        ret
