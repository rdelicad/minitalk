# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdelicad <rdelicad@student.42.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/18 13:34:16 by rdelicad          #+#    #+#              #
#    Updated: 2023/09/18 13:34:58 by rdelicad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# -------------------------- Colors ---------------------------

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

# -------------------------- NAMES -----------------------

NAME_C		:= client
NAME_S  	:= server
NAME_CB		:= client_bonus
NAME_SB  	:= server_bonus

CC			:= gcc

CFLAGS		:= -g -Wall -Wextra -Werror

# ------------------------ Library --------------------------

LIB			:= ar rcs
LIBFT_DIR	:= ./libft
LIBFT_PATH	:= $(LIBFT_DIR)/libft.a
LIB_SYS		:= -Iinclude

# --- Rules ---

all : $(NAME_C) $(NAME_S) 
bonus: $(NAME_CB) $(NAME_SB) $(LIBFT_PATH)

$(LIBFT_PATH) :
	@make -s -C $(LIBFT_DIR)

# --------------------- mandatory -----------------------
$(NAME_C) : $(LIBFT_PATH) 
	@echo "$(YELLOW)$(BOLD)Compiling Client...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_PATH) $(LIB_SYS) src/client.c -o $(NAME_C) 
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

$(NAME_S) : $(LIBFT_PATH) 
	@echo "$(YELLOW)$(BOLD)Compiling Server...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_PATH) $(LIB_SYS) src/server.c -o $(NAME_S) 
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"


$(OBJS) : obj/%.o : src/%.c 
	@$(CC) $(CFLAGS) -c $< -o $@

# ----------------------- bonus ----------------------------


$(NAME_CB) : $(LIBFT_PATH) 
	@echo "$(YELLOW)$(BOLD)Compiling Client...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_PATH) $(LIB_SYS) srcb/client_bonus.c -o $(NAME_CB) 
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"

$(NAME_SB) : $(LIBFT_PATH) 
	@echo "$(YELLOW)$(BOLD)Compiling Server...$(RESET)"
	@$(CC) $(CFLAGS) $(LIBFT_PATH) $(LIB_SYS) srcb/server_bonus.c -o $(NAME_SB) 
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"


$(OBJSB) : obj/%.o : srcb/%.c 
	@$(CC) $(CFLAGS) -c $< -o $@

# ---------------------- rules ----------------------------
clean :
	@echo "$(RED)$(BOLD)Cleaning objects from program...$(RESET)"
	@rm -rf $(OBJS) *.dSYM
	@echo "$(GREEN)$(BOLD)Done.$(RESET)"
	@make clean -s -C $(LIBFT_DIR)

fclean :
	@echo "$(RED)$(BOLD)Cleaning all files from program...$(RESET)"
	@rm -rf $(NAME_C) $(NAME_S) $(NAME_CB) $(NAME_SB) $(LIBFT_PATH) $(OBJS) *.dSYM
	@make fclean -s -C $(LIBFT_DIR)

re : fclean all

minitalk : all clean

.PHONY : all re fclean clean

