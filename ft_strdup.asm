section .text
  extern malloc
  extern ft_strlen
  extern ft_strcpy
  global ft_strdup

ft_strdup:
  push rdi              ; save rdi
  call ft_strlen
  inc rax               ; include null terminator
  mov rdi, rax
  call malloc wrt ..plt ; wrt ..plt is needed for position-independent code
  test rax, rax
  jz .malloc_failed     ; malloc returns NULL on failure
  pop rdi               ; restore rdi
  mov rsi, rdi
  mov rdi, rax
  call ft_strcpy        ; copy from rsi to rdi
  ret

.malloc_failed
  pop rdi               ; restore rdi
  xor rax, rax          ; return NULL
  ret
