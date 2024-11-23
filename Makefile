# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/23 18:30:58 by chuezeri          #+#    #+#              #
#    Updated: 2024/11/23 19:37:18 by chuezeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME            := libftprintf.a
TARGET          := test_runner

# Directories


LIBFT_PATH		:= ./libft
LIBFT			:= $(LIBFT_PATH)/libft.a
SRC_DIR         := src
OBJ_DIR         := obj
TEST_DIR        := test
TEST_OBJ_DIR    := test/obj

# Source files
SRCS            := ft_printf.c

OBJS		:= $(SRCS:%.c=%.o)

BONUS		:=
BONUS_OBJS	:= $(BONUS:%.c=%.o)


CRITERION	:= ${HOME}/sgoinfre/linuxbrew/.linuxbrew/Cellar/criterion/2.4.2_1/include

# Include paths
INCLUDES		:= -I $(LIBFT_PATH)


# Compiler and flags
CC              := cc
CFLAGS          := -Wall -Wextra -Werror $(INCLUDES)
DEBUG           := -g -fsanitize=leak
# LDFLAGS			:= -L${HOME}/sgoinfre/linuxbrew/.linuxbrew/Cellar/criterion/2.4.2_1/lib -lcriterion
LDFLAGS			:=



# Library archiving flags
LIBFLAGS        := ar rcs

# Clean command
RM              := rm -f

# Default target (build library)
all: $(NAME)

# Run tests
test: $(TARGET)
	./$(TARGET)

# Rule to build the static library
$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(LIBFLAGS) $(NAME) $(OBJS)

$(LIBFT): 
	make -C $(LIBFT_PATH) all
# Rule to compile the library source files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# For testing
$(TARGET): $(TEST_OBJS) $(OBJS)
	$(CC) $(TEST_OBJS) $(OBJS) -o $(TARGET) $(NAME) $(LDFLAGS)

# bonus
bonus:	$(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Clean rule (remove object files)
clean:
	$(RM) *.o

# Full clean (remove object files and static library)
fclean: clean
	$(RM) $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: clean fclean re
