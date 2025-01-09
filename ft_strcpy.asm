section .text
    global ft_strcpy

ft_strcpy:
  cmp byte [rdi], 0
  je .exit
  mov rsi, [rdi]
  inc rdi
  inc rsi
  jmp ft_strcpy

.exit:
  mov byte [rsi], 0
  mov rax, rdi
  ret
