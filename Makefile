AS = nasm
ASFLAGS = -f elf64

CC = clang
CFLAGS = -Wall -Wextra -Werror

ASSRCS = ft_strlen.s \
		ft_strcmp.s \
		ft_strcpy.s \
		ft_strdup.s \
		ft_read.s \
		ft_write.s

ASOBJS = $(addsuffix .o, $(basename $(ASSRCS)))

ARFLAGS = rcs

NAME = libasm.a

all: test

test: $(NAME) main.c
	$(CC) $(CFLAGS) main.c -L. -lasm

$(NAME): $(ASOBJS)
	$(AR) $(ARFLAGS) $(NAME) $^

%.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(NAME) $(ASOBJS)

fclean: clean
	$(RM) a.out

re: fclean all

.PHONY: all clean fclean re