/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:49:50 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:44:16 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_printf(const char *format, ...);
static int	parse_specifier(char specifier, va_list ap);
static void	print_regular_char(unsigned int *printed,
				unsigned int *idx, char ch);

int	ft_printf(const char *format, ...)
{
	unsigned int	idx;
	unsigned int	printed;
	va_list			arg_ptr;

	idx = 0;
	printed = 0;
	va_start(arg_ptr, format);
	while (idx < ft_strlen(format))
	{
		if (format[idx] == '%' && idx + 1 < ft_strlen(format))
		{
			if (ft_strchr(SPECIFIERS, format[idx + 1]))
			{
				printed += parse_specifier(format[idx + 1], arg_ptr);
				idx += 2;
			}
			else
				print_regular_char(&printed, &idx, format[idx]);
		}
		else
			print_regular_char(&printed, &idx, format[idx]);
	}
	va_end(arg_ptr);
	return (printed);
}

static int	parse_specifier(char specifier, va_list ap)
{
	if (specifier == '%')
		return (ft_print_percent_sign());
	else if (specifier == 'c')
		return (ft_print_char(va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_string(va_arg(ap, char *)));
	else if (specifier == 'p')
		return (ft_print_pointer(va_arg(ap, unsigned long long)));
	else if (specifier == 'd')
		return (ft_print_integer(va_arg(ap, int)));
	else if (specifier == 'i')
		return (ft_print_integer(va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(ap, unsigned int)));
	else if (specifier == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), 0));
	else if (specifier == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), 1));
	else
		return (-1);
}

static void	print_regular_char(unsigned int *printed,
					unsigned int *idx, char ch)
{
	ft_putchar_fd(ch, 1);
	(*printed)++;
	(*idx)++;
}
