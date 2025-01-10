section .text
  global ft_read

ft_read:
  mov eax, 0
  syscall
  test rax, rax
  jge .no_error
  mov rax, -1

.no_error:
  ret