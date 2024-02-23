# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mspasic <mspasic@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 15:07:23 by mspasic           #+#    #+#              #
#    Updated: 2023/11/15 19:38:21 by mspasic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FLS = ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_memset.c ft_bzero.c ft_memcpy.c \
			ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c \
			ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_itoa.c ft_strmapi.c ft_striteri.c \
			ft_split.c
BNS_FLS = ft_lstnew_bonus.c ft_lstsize_bonus.c \
		  ft_lstlast_bonus.c ft_lstadd_front_bonus.c \
		  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		  ft_lstclear_bonus.c ft_lstiter_bonus.c \
		  ft_lstmap_bonus.c

HDR_FLS = libft.h
OBJ_FLS = $(SRC_FLS:.c=.o)
BOBJ_FLS = $(BNS_FLS:.c=.o)
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):$(OBJ_FLS)
	ar rcs $(NAME) $(OBJ_FLS)
bonus: .bonus
.bonus: $(NAME) $(BOBJ_FLS)
	ar rcs $(NAME) $(BOBJ_FLS)
	@touch .bonus
$(OBJ_FLS):
	$(CC) $(CFLAGS) -I $(HDR_FLS) -c $(@:.o=.c) -o $@

clean:
	rm -f $(OBJ_FLS) $(BOBJ_FLS)
	@rm -f .bonus
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: clean fclean all re bonus
