# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetsoan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 08:07:20 by lpetsoan          #+#    #+#              #
#    Updated: 2019/07/22 14:21:30 by lpetsoan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
      ft_bzero.c \
      ft_isalnum.c \
      ft_isalpha.c \
      ft_isascii.c \
      ft_isdigit.c \
      ft_isprint.c \
      ft_itoa.c \
      ft_memalloc.c \
      ft_memccpy.c \
      ft_memchr.c \
      ft_memcmp.c \
      ft_memcpy.c \
      ft_memdel.c \
      ft_memmove.c \
      ft_memset.c \
      ft_putchar.c \
      ft_putchar_fd.c \
      ft_putendl.c \
      ft_putendl_fd.c \
      ft_putnbr.c \
      ft_putnbr_fd.c \
      ft_putstr.c \
      ft_putstr_fd.c \
      ft_strcat.c \
      ft_strchr.c \
      ft_strclr.c \
      ft_strcmp.c \
      ft_strcpy.c \
      ft_strdel.c \
      ft_strdup.c \
      ft_strequ.c \
      ft_striter.c \
      ft_striteri.c \
      ft_strjoin.c \
      ft_strlcat.c \
      ft_strlen.c \
      ft_strmap.c \
      ft_strmapi.c \
      ft_strncat.c \
      ft_strncmp.c \
      ft_strncpy.c \
      ft_strnequ.c \
      ft_strnew.c \
      ft_strnstr.c \
      ft_strrchr.c \
      ft_strsplit.c \
      ft_strstr.c \
      ft_strsub.c \
      ft_strtrim.c \
      ft_tolower.c \
      ft_toupper.c \
	  ft_wordlen.c\
	  ft_wordcount.c\
	  ft_removeend.c\
	  ft_digitlen.c\
	  ft_baseconv.c\
	  ft_strrev.c\
	  ft_ifalloc.c\
	  ft_strndup.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
