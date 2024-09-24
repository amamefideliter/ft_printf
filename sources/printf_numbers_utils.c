/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_numbers_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:19:22 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:44:25 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_hex(unsigned int nb, int uppercase)
{
	char			*string;
	unsigned int	len;

	string = ft_itoa_hex(nb, uppercase);
	ft_putstr_fd(string, 1);
	len = ft_strlen(string);
	free(string);
	return (len);
}

int	ft_print_integer(int nb)
{
	char			*string;
	unsigned int	len;

	string = ft_itoa(nb);
	len = ft_strlen(string);
	ft_putstr_fd(string, 1);
	free(string);
	return (len);
}

int	ft_print_unsigned(int nb)
{
	char			*string;
	unsigned int	len;

	string = ft_itoa_unsigned(nb);
	ft_putstr_fd(string, 1);
	len = ft_strlen(string);
	free (string);
	return (len);
}

int	ft_print_pointer(unsigned long long nb)
{
	char			*string;
	unsigned int	len;

	if (nb == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	string = ft_itoa_hex(nb, 0);
	len = ft_strlen(string);
	ft_putstr_fd(string, 1);
	free (string);
	return (len + 2);
}
