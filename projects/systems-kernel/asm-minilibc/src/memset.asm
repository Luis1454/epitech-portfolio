section .text
    global memset

memset:
    test rdx, rdx
    jz .end

    .loop:
        mov byte [rdi + rdx - 1], sil
        dec rdx
        jnz .loop

    .end:
        mov rax, rdi
        ret
