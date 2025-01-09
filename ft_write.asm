section .text
  global ft_write

ft_write:
  mov eax, 1
  syscall
  test rax, rax
  jge .no_error
  mov rax, -1

.no_error:
  ret