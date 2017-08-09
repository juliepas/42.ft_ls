# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpascal <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:15 by jpascal           #+#    #+#              #
#    Updated: 2017/05/22 19:18:27 by jpascal          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC_NAME =	ft_ls.c \
			ft_pars_ls.c \
			ft_ls_l.c \
			ft_ls_r.c \
			ft_space_l.c \
			ft_periph_l.c \
			ft_date_l.c \
			ft_pick_files.c \
			ft_rights_l.c \
			ft_sort.c \
			ft_g_o.c

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft.a

LIB_PATH =  libft/
OBJ_PATH =  obj/
CC = gcc
W_FLAGS = -Werror -Wall -Wextra -g
I_FLAGS = -I includes
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@$(CC) $(W_FLAGS) -c $(SRC) $(I_FLAGS)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@mv $(OBJ_NAME) $(OBJ_PATH)
	@$(CC) $(W_FLAGS) -o $(NAME) $(OBJ) $(LIB)

clean:
	@make clean -C $(LIB_PATH)
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true


fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -f $(LIB) $(NAME) 

re: fclean all
