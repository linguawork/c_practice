# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areggie <areggie@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/08 18:12:32 by areggie           #+#    #+#              #
#    Updated: 2022/04/26 22:11:02 by areggie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =./ft_memset.c ./ft_bzero.c ./ft_memcpy.c\
./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c\
./ft_strlen.c ./ft_strlcpy.c ./ft_atoi.c ./ft_isalpha.c\
./ft_isdigit.c ./ft_isascii.c ./ft_isprint.c\
./ft_toupper.c ./ft_tolower.c ./ft_memccpy.c\
./ft_isalnum.c ./ft_strlcat.c\
 ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c\
 ./ft_strnstr.c ./ft_calloc.c ./ft_strdup.c\
  ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c\
  ./ft_itoa.c ./ft_split.c ./ft_strmapi.c \
  ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c\
  ./ft_putnbr_fd.c ./ft_lstaddback.c ./ft_lstlast.c ./ft_lstnew.c \
  ./ft_lstsize.c ./get_next_line.c ./ft_putchar.c ./ft_putstr.c\
  ./ft_putendl.c ./get_next_line2.c ./ft_strcmp.c ./mem_free.c \
  ./my_malloc.c

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

.c.o: ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		 ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
