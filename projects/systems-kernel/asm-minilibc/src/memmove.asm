section .text
    global memmove

memmove:
    mov rbx, rdi
    test rdx, rdx
    jz .end

    cmp rdi, rsi
    jb .frwd
    jmp .bkwd

.frwd:
    .loop:
        mov al, [rsi]
        mov [rdi], al
        dec rdx
        jz .end
        inc rsi
        inc rdi
        jmp .loop

.bkwd:
    add rsi, rdx
    add rdi, rdx
    sub rsi, 1
    sub rdi, 1

    .b_loop:
        mov al, [rsi]
        mov [rdi], al
        dec rdx
        jz .end
        dec rsi
        dec rdi
        jmp .b_loop

    .end:
        mov rax, rbx
        ret
