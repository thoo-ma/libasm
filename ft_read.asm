section .text
  global ft_read

ft_read:
  ; parameters
  ; rdi - file descriptor (int fd)
  ; rsi - buffer (void *buf)
  ; rdx - count (size_t count)
  mov eax, 0      ; syscall number for read is 0
  syscall
  test rax, rax
  jge .no_error   ; if rax >= 0, no error occurred
  mov rax, -1     ; return -1 if error occurred

.no_error:
  ret