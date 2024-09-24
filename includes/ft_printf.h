/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:49:53 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:43:52 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

# define SPECIFIERS "cspdiuxX%"

char	*ft_itoa_hex(unsigned long long n, int uppercase);
char	*ft_itoa_unsigned(unsigned int n);
int		ft_printf(const char *format, ...);
int		ft_print_char(char ch);
int		ft_print_hex(unsigned int nb, int uppercase);
int		ft_print_integer(int nb);
int		ft_print_percent_sign(void);
int		ft_print_pointer(unsigned long long nb);
int		ft_print_string(char *s);
int		ft_print_unsigned(int nb);

#endif