# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/05 08:22:05 by bsantana          #+#    #+#              #
#    Updated: 2024/03/09 16:54:33 by bsantana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable names

NAME = client
NAME_SERVER = server
NAME_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

# Flags
CC = cc
CFLAGS = -Wextra -Wall -Werror

# Librarie path

LIBFT_PATH = ./libft/
LIBFT = $(addprefix $(LIBFT_PATH), libft.a)

# Minitalk headers

INCLUDES = -I ./
HEADER_CLIENT = client.h
HEADER_SERVER = server.h
HEADER_CLIENT_BONUS = client_bonus.h
HEADER_SERVER_BONUS = server_bonus.h

# Files

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_BONUS = client_bonus.c
SRC_SERVER_BONUS = server_bonus.c

OBJS_CLIENT = ${SRC_CLIENT:%.c=%.o}
OBJS_SERVER = ${SRC_SERVER:%.c=%.o}
OBJS_CLIENT_BONUS = ${SRC_CLIENT_BONUS:%.c=%.o}
OBJS_SERVER_BONUS = ${SRC_SERVER_BONUS:%.c=%.o}

# Compiles project mandatory

all: libft $(NAME) $(NAME_SERVER)
	@echo "Use './$(NAME_SERVER)' to get the PID."
	@echo "Use './$(NAME)'<PID> <text_message> to send a message to the server."

# Compiles project bonus

bonus: libft $(NAME_BONUS) $(NAME_SERVER_BONUS)
	@echo "Use './$(NAME_SERVER_BONUS)' to get the PID."
	@echo "Use './$(NAME_BONUS)'<PID> <text_message> to send a message to the server."

# Compile LIBFT library

$(LIBFT):
	@make -C $(LIBFT_PATH)
	
# Compile .c file into .o file

%.o: %.c %.h
	@$(CC) $(CFLAGS) -o $@ -c $<

# Build the final executable - mandatory client

$(NAME): $(OBJS_CLIENT)
	@echo "Creating ./$(NAME)"
	@$(CC) $(OBJS_CLIENT) $(LIBFT) $(INCLUDES) -o $(NAME)
	@echo "Done!"

# Build the final executable - mandatory server

$(NAME_SERVER): $(OBJS_SERVER)
	@echo "Creating ./$(NAME_SERVER)"
	@$(CC) $(OBJS_SERVER) $(LIBFT) $(INCLUDES) -o $(NAME_SERVER)
	@echo "Done!"

# Build the final executable - bonus client

$(NAME_BONUS): $(OBJS_CLIENT_BONUS)
	@echo "Creating ./$(NAME_BONUS)"
	@$(CC) $(OBJS_CLIENT_BONUS) $(LIBFT) $(INCLUDES) -o $(NAME_BONUS)
	@echo "Done!"

# Build the final executable - bonus server

$(NAME_SERVER_BONUS): $(OBJS_SERVER_BONUS)
	@echo "Creating ./$(NAME_SERVER_BONUS)"
	@$(CC) $(OBJS_SERVER_BONUS) $(LIBFT) $(INCLUDES) -o $(NAME_SERVER_BONUS)
	@echo "Done!"

# Clean object files

clean: 
	@rm -rf $(OBJS_CLIENT) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER) $(OBJS_SERVER_BONUS)
	@make clean -C $(LIBFT)

# Clean everything

fclean: clean
	@make fclean -C $(LIBFT)
	@rm -rf $(NAME) $(NAME_BONUS) $(NAME_SERVER) $(NAME_SERVER_BONUS)

# Clean and rebuild everything

re: fclean all

# Targets that are not associated with files

.PHONY: all, clean, fclean, re, libft
