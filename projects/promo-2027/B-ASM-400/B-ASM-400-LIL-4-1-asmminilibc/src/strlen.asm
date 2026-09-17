section .text
    global strlen

strlen:
    mov rax,0
    mov rcx,0

    .loop:
        xor rdx,rdx
        cmp byte [rdi+rcx],0
        je .end
        inc rcx
        jmp .loop

    .end:
        mov rax,rcx
        ret
