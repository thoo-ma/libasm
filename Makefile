ASM = nasm
CC = gcc
ASM_FLAGS = -f elf64
CC_FLAGS = -c -Wall

ASM_FILES = ft_strlen.asm ft_strcmp.asm ft_strcpy.asm ft_strdup.asm ft_read.asm
ASM_OBJS = $(ASM_FILES:.asm=.o)
C_OBJ = main.o
LIBRARY = libft.a

NAME = a.out

all: $(NAME)

$(NAME): $(LIBRARY) $(C_OBJ)
	$(CC) -o $(NAME) $(C_OBJ) $(LIBRARY)

$(LIBRARY): $(ASM_OBJS)
	ar rcs $(LIBRARY) $(ASM_OBJS)

%.o: %.asm
	$(ASM) $(ASM_FLAGS) -o $@ $<

$(C_OBJ): main.c
	$(CC) $(CC_FLAGS) main.c

clean:
	rm -f $(LIBRARY) $(ASM_OBJS) $(C_OBJ)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean
