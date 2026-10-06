section .text
    global strchr

strchr:
    xor rax, rax
    dec rdi

.loop:
    inc rdi
    cmp [rdi], sil
    je .end
    cmp byte [rdi], 0
    jne .loop

.empty:
    ret

.end:
    mov rax, rdi 
    ret
