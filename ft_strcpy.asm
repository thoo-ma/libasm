section .text
  global ft_strcpy

ft_strcpy:
  mov rax, rdi        ; save destination pointer
.copy:
  mov dl, [rsi]
  mov [rdi], dl
  inc rsi
  inc rdi
  test dl, dl         ; check for null terminator
  jnz .copy
  mov rax, rax        ; return destination pointer
  ret
