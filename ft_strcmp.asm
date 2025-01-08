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
  ; xor rax, rax    ; set rax to zero
  mov rax, [rsi]
  sub rax, [rdi]
  ; mov rax, al
  ; sub rax, bl
  ret