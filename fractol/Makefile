# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 11:34:02 by mspasic           #+#    #+#              #
#    Updated: 2024/02/21 18:49:21 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE_FILES = 	main.c fractol.c utils.c colouring.c

OBJECT_FILES = $(SOURCE_FILES:.c=.o)

HEADER = fractol.h

NAME = fractol.a

CC = cc

CFLAGS = -Wall -Werror -Wextra -I./MLX42/include -I./Libft
# path to the include directory where the headers are

LDFLAGS = -L "Users/mspasic/.brew/opt/glfw/lib/" -L/Libft
# the linker flags

LIB = -lglfw -llibft.a
# specifies the libraries to link with

DEPS = ./Libft/libft.h

LIBMLX42 = ./MLX42/build/libmlx42.a

LIBLIBFT = ./Libft/libft.a


all: $(NAME)

$(NAME):$(OBJECT_FILES)
	$(CC) $(NAME) $(OBJECT_FILES) $(LIB) $(LDFLAGS) -I $(HEADER)

$(OBJECT_FILES): $(SOURCE_FILES) $(DEPS) $(LIBLIBFT)
	$(CC) $(CFLAGS) -c $(@:.o=.c) -o $@

$(LIBLIBFT):
	$(MAKE) -C Libft

clean:
	rm -f $(OBJECT_FILES)
	$(MAKE) -C Libft

fclean: clean
	rm -f $(NAME) 
	$(MAKE) -C Libft

re: fclean all

.PHONY: clean fclean all re
