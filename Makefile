# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/18 17:28:04 by dzubkova          #+#    #+#              #
#    Updated: 2024/09/24 17:43:26 by dzubkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PFX = sources/

SRCS = \
		$(PFX)ft_itoa_hex.c $(PFX)ft_printf.c $(PFX)ft_itoa_unsigned.c \
		$(PFX)printf_char_utils.c $(PFX)printf_numbers_utils.c

OFILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a
MAKE = make

all: $(NAME)

$(NAME): $(OFILES)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OFILES)

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OFILES)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re