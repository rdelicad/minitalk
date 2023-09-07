


# --- Colors ---

BOLD      := \033[1m
BLACK     := \033[30;1m
RED       := \033[31;1m
GREEN     := \033[32;1m
YELLOW    := \033[33;1m
BLUE      := \033[34;1m
MAGENTA   := \033[35;1m
CYAN      := \033[36;1m
WHITE     := \033[37;1m
RESET     := \033[0m

NAME_C		:= client
NAME_S  	:= server

CC			:= gcc

CFLAGS		:= -g -Wall -Wextra -Werror

# --- Library ---

LIB			:= ar rcs

LIBFT_DIR	:= ./libft
LIBFT_PATH	:= %(LIBFT_DIR)/libft.a

# --- Files ---

SRCS		:= client.c server.c 

OBJS		:= $(addprefix obj/,$(SRCS:.c=.o))

# --- Rules ---

$

$(OBJS)		:= obj/%.o : src/%.c 
	@$(CC) $(CFLAGS) -c $< -o $@

