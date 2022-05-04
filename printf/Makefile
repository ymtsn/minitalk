NAME = libftprintf.a
LIBFT_NAME = ../libft/libft.a
LIBFT_DIR = ../libft
SRC_DIR	= .
OBJ_DIR = ../obj

CC = gcc
CFLAGS = -Werror -Wall -Wextra
INCFLAG	= -I ../include
DEPSFLAG = -MMD -MP

PRINTF_SRC 					= ft_printf.c ft_fmt_csper.c ft_fmt_diuxXp.c ft_printf_utils.c
PRINTF_OBJ					= $(PRINTF_SRC:.c=.o)
PRINTF_SRC_FULLNAME			= $(addprefix ./, $(PRINTF_SRC))
PRINTF_OBJ_FULLNAME			= $(addprefix ../obj/, $(PRINTF_SRC:.c=.o))
PRINTF_DPS_FULLNAME			= $(addprefix ../obj/, $(PRINTF_SRC:.c=.d))

OBJS = $(PRINTF_OBJ_FULLNAME)
DEPS = $(PRINTF_DPS_FULLNAME)

all:make-libft $(NAME)

$(NAME):$(LIBFT_NAME) $(OBJS)
	cp $(LIBFT_NAME) $(NAME)
	ar -rc $(NAME) $(OBJS)

$(LIBFT_NAME):make-libft

make-libft:
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o:%.c
	$(CC) $(CFLAGS) $(INCFLAG) $(DEPSFLAG) -o $@ -c $<

clean:
	rm -rf $(PRINTF_OBJ_FULLNAME)
	rm -rf $(PRINTF_DPS_FULLNAME)
	rm -rf $(LIBFT_NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:clean
	rm -rf $(NAME)

re :fclean all

.PHONY: all clean fclean re bonus make-libft

-include $(DEPS)
