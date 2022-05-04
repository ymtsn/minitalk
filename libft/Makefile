NAME = libft.a
CC := gcc
CFLAGS := -Wall -Wextra -Werror
DEPSFLAG = -MMD -MP
INCFLAG	= -I ../include
SRCS := ft_strlen.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_putnbr_long_fd.c
OBJS	= $(addprefix ../obj/, $(SRCS:.c=.o))
DEPS 	= $(addprefix ../obj/, $(SRCS:.c=.d))

all:$(NAME)
$(NAME):$(OBJS)
	ar -rc $(NAME) $(OBJS)
../obj/%.o:%.c
	$(CC) $(CFLAGS) $(INCFLAG) $(DEPSFLAG) -o $@ -c $<
clean:
	rm -rf $(OBJS) $(DEPS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re

-include $(DEPS)
