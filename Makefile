AS = nasm
ASFLAGS = -f elf64

CC = clang
CFLAGS = -Wall -Wextra -Werror

ASSRCS = ft_strlen.asm \
		ft_strcmp.asm \
		ft_strcpy.asm \
		ft_strdup.asm \
		ft_read.asm \
		ft_write.asm

ASOBJS = $(addsuffix .o, $(basename $(ASSRCS)))

ARFLAGS = rcs

NAME = libasm.a

all: test

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lasm

$(NAME): $(ASOBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o: %.asm
	$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(ASOBJS)

fclean: clean
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re