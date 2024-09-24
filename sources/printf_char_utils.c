/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:09:54 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:44:23 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_percent_sign(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_print_char(char ch)
{
	write(1, &ch, 1);
	return (1);
}

int	ft_print_string(char *s)
{
	unsigned int	len;

	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}
