SERVER_NAME = server
CLIENT_NAME = client
NAME = target
LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a
PRINTF_DIR = ./printf
PRINTF_NAME = $(PRINTF_DIR)/libftprintf.a
MINITALK_SRC_DIR	= ./src
MINITALK_BONUS_SRC_DIR	= ./bonus_src
OBJ_DIR = ./obj

CC = gcc
CFLAGS = -Werror -Wall -Wextra $(DFLAGS)
DFLAGS =
INCFLAG	= -I ./include
DEPSFLAG = -MMD -MP -MF
LIBRALY = $(PRINTF_NAME)

CLIENT_MAN 					= ft_client.c ft_client_utils.c ft_client_utils2.c
SERVER_MAN 					= ft_server.c ft_server_utils.c
CLIENT_MAN_FULLNAME			= $(addprefix ./src/, $(CLIENT_MAN))
SERVER_MAN_FULLNAME			= $(addprefix ./src/, $(SERVER_MAN))
CLIENT_MAN_DEPS_FULLNAME	= $(addprefix ./obj/, $(CLIENT_MAN:.c=.d))
SERVER_MAN_DEPS_FULLNAME	= $(addprefix ./obj/, $(SERVER_MAN:.c=.d))

CLIENT_BONUS 				= ft_client_bonus.c ft_client_utils_bonus.c ft_client_utils2_bonus.c
SERVER_BONUS 				= ft_server_bonus.c ft_server_utils_bonus.c
CLIENT_BONUS_FULLNAME		= $(addprefix ./bonus_src/, $(CLIENT_BONUS))
SERVER_BONUS_FULLNAME		= $(addprefix ./bonus_src/, $(SERVER_BONUS))
CLIENT_BONUS_DEPS_FULLNAME	= $(addprefix ./obj/, $(CLIENT_BONUS:.c=.d))
SERVER_BONUS_DEPS_FULLNAME	= $(addprefix ./obj/, $(SERVER_BONUS:.c=.d))

MINITALK_BONUS =

ifdef MINITALK_BONUS
	CLIENT_SRCS = $(CLIENT_BONUS_FULLNAME)
	SERVER_SRCS = $(SERVER_BONUS_FULLNAME)
	C_DEPS = $(DEPSFLAG)./obj/ft_client_bonus.d $(DEPSFLAG)./obj/ft_client_utils_bonus.d $(DEPSFLAG)./obj/ft_client_utils2_bonus.d
	S_DEPS = $(DEPSFLAG)./obj/ft_server_bonus.d $(DEPSFLAG)./obj/ft_server_utils_bonus.d
else
	CLIENT_SRCS = $(CLIENT_MAN_FULLNAME)
	SERVER_SRCS = $(SERVER_MAN_FULLNAME)
	C_DEPS = $(DEPSFLAG)./obj/ft_client.d $(DEPSFLAG)./obj/ft_client_utils.d $(DEPSFLAG)./obj/ft_client_utils2.d
	S_DEPS = $(DEPSFLAG)./obj/ft_server.d $(DEPSFLAG)./obj/ft_server_utils.d
endif

all:make-objdir make-printf $(NAME)

$(NAME):$(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME):$(CLIENT_SRCS) $(LIBFT_NAME) $(PRINTF_NAME)
	$(CC) $(CFLAGS) $(INCFLAG) $(C_DEPS) $(LIBRALY) -o $(CLIENT_NAME) $(CLIENT_SRCS)

$(SERVER_NAME):$(SERVER_SRCS) $(LIBFT_NAME) $(PRINTF_NAME)
	$(CC) $(CFLAGS) $(INCFLAG) $(S_DEPS) $(LIBRALY) -o $(SERVER_NAME) $(SERVER_SRCS)

make-objdir:
	if [ ! -d $(OBJ_DIR) ]; then mkdir -p $(OBJ_DIR); fi
make-printf:
	$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -rf $(CLIENT_MAN_DEPS_FULLNAME)
	rm -rf $(SERVER_MAN_DEPS_FULLNAME)
	rm -rf $(CLIENT_BONUS_DEPS_FULLNAME)
	rm -rf $(SERVER_BONUS_DEPS_FULLNAME)
	$(MAKE) -C $(PRINTF_DIR) fclean
fclean:clean
	rm -rf $(CLIENT_NAME) $(SERVER_NAME)

bonus:
	make MINITALK_BONUS="true"

debug:
	make DFLAGS="-g -fsanitize=integer -fsanitize=address"
debug-bonus:
	make MINITALK_BONUS="true" DFLAGS="-g -fsanitize=integer -fsanitize=address"

re :fclean all

.PHONY: all clean fclean re bonus make-objdir make-printf debug debug-bonus

-include $(C_DEPS) $(S_DEPS)
