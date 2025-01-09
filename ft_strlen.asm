section .text
  global ft_strlen

ft_strlen:
  push  rcx             ; save rcx
  xor   rcx, rcx        ; init rcx

.loop:
  cmp   byte [rdi], 0
  jz    .exit
  inc   rcx
  inc   rdi
  jmp   .loop

.exit:
  mov   rax, rcx
  pop   rcx             ; restore rcx
  ret