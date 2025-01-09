section .text
  global ft_strcmp

ft_strcmp:
  mov al, byte [rdi]
  mov bl, byte [rsi]
  test al, al
  jz .exit        ; if al is zero, exit
  test bl, bl
  jz .exit        ; if bl is zero, exit
  cmp al, bl
  jne .exit       ; if al equals bl, exit
  inc rdi
  inc rsi
  jmp ft_strcmp

.exit:
  cmp al, bl
  je .equal
  jl .less
  jg .greater

.equal:
  xor rax, rax    ; set rax to 0
  ret

.less:
  mov rax, -1     ; set rax to -1
  ret

.greater:
  mov rax, 1      ; set rax to 1
  ret