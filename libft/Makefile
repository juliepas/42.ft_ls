# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:15 by jpascal           #+#    #+#              #
#    Updated: 2016/11/24 00:55:48 by jpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = srcs /

SRC_NAME = ft_atoi.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isdigit.c \
		   ft_isprint.c \
		   ft_putchar.c \
		   ft_putendl.c \
		   ft_putstr.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdup.c \
		   ft_strequ.c \
		   ft_strlen.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnequ.c \
		   ft_strrchr.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strnew.c \
		   ft_putnbr.c \
		   ft_putchar_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \
		   ft_putnbr_fd.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_memalloc.c \
		   ft_memdel.c \
		   ft_strdel.c \
		   ft_strstr.c \
		   ft_strnstr.c \
		   ft_strsub.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_strlcat.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memccpy.c \
		   ft_memmove.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_itoa.c \
		   ft_strsplit.c \
		   ft_lstnew.c \
		   ft_lstdelone.c \
		   ft_lstdel.c \
		   ft_lstadd.c \
		   ft_lstiter.c \
		   ft_lstmap.c \
		   ft_count_words.c \
		   ft_swap.c \
		   ft_nbrlen.c \
		   ft_puttab.c \
		   ft_puttab_fd.c \
		   ft_strchrint.c \
		   ft_strjoinchar.c \
		   ft_putnbrendl.c \
		   ft_strjoinfree.c \

OBJ_PATH = obj

CPPFLAGS = -I ./includes \

NAME = libft.a

CFLAGS = -Werror -Wall -Wextra -g

OBJ_NAME = $(SRC_NAME:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ_NAME)
	@ar rc $(NAME) $(OBJ_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@gcc $(CFLAGS) $(CPPLAGS) -o $(OBJ_NAME) -c $(SRC_NAME)

clean:
	@rm -fv $(OBJ_NAME)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@rm -fv $(NAME)

re: fclean all
