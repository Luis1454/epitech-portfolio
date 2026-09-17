section .text
    global memcpy

memcpy:
    mov rax, rdi
    test rdx, rdx
    jz .end

    xor rcx, rcx
    cmp rsi, rdi
    jl .loop
    test rsi, rsi
    jz .end

.loop:
    mov bl, [rsi + rcx]
    mov [rax + rcx], bl
    inc rcx
    dec rdx
    jnz .loop

.end:
    ret
