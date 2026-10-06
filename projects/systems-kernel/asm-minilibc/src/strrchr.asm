section .text
    global strrchr

strrchr:
    mov rcx, rdi
    mov al, sil

    .reach_end:
        cmp byte [rcx], 0
        jz .skip
        inc rcx
        jmp .reach_end

    .skip:
        cmp byte [rcx], al
        jz .ok
        dec rcx
        cmp rdi, rcx
        ja .ko
        jmp .skip

    .ok:
        mov rax, rcx
        ret

    .ko:
        xor rax, rax
        ret
