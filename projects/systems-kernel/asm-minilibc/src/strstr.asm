section .text
global strstr

strstr:
    mov rcx, rsi
    mov rdx, rdi

    mov al, [rcx]
    test al, al
    jz .ok
    jmp .check

.check:
    mov al, [rdx]
    test al, al
    jz .ko
    mov rdi, rdx
    mov rsi, rcx

.loop:
    mov al, [rdi]
    mov bl, [rsi]
    test al, al
    jz .break
    test bl, bl
    jz .ok
    cmp al, bl
    jne .sub_loop
    inc rdi
    inc rsi
    jmp .loop

.sub_loop:
    inc rdx
    jmp .check

.break:
    test bl, bl
    jnz .sub_loop

.ok:
    mov rax, rdx
    jmp .end

.ko:
    xor rax, rax

.end:
    ret
