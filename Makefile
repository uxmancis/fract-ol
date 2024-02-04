# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 11:00:21 by uxmancis          #+#    #+#              #
#    Updated: 2024/02/03 16:41:49 by uxmancis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
#lo de "-Imlx -c $< -o $@" es por la indicación de 42 Docs sobre cómo compilar la MinilibX
#https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

# Source files and object files
SRC = ft_fractol.c utils.c mandelbrot.c event_handler.c generate_colour.c render.c utils_str2double.c #probatxuek.c 
OBJ = $(SRC:.c=.o)

# Executable name
NAME = fractol

# Make all rule
all: $(NAME)

# Build the executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -o $(NAME) $(OBJ) minilib/libmlx.a
#lo de "-Lmlx -lmlx -framework OpenGL -framework AppKit" es por la indicación de 42 Docs sobre cómo compilar la MinilibX
#https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ)

# Clean everything, including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all clean fclean re