/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:03:28 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:43:44 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*allocate_space(char *tmp);
static char	*edge_cases(unsigned long long n);
static char	set_value(int tmp);
static int	ft_remainder(unsigned long long *n, int uppercase);

char	*ft_itoa_hex(unsigned long long n, int uppercase)
{
	char	tmp[40];
	char	*res;
	int		idx;
	char	*start;

	res = edge_cases(n);
	if (res)
		return (res);
	free(res);
	idx = 0;
	while (n)
		tmp[idx++] = ft_remainder(&n, uppercase);
	tmp[idx] = '\0';
	res = allocate_space(tmp);
	if (!res)
		return (NULL);
	start = res;
	while (--idx >= 0)
		*res++ = tmp[idx];
	*res = '\0';
	return (start);
}

static char	*edge_cases(unsigned long long n)
{
	char	*res;

	if (n == 0)
	{
		res = malloc(2);
		if (!res)
			return (NULL);
		ft_strlcpy(res, "0", 2);
		return (res);
	}
	else
		return (NULL);
}

static char	*allocate_space(char *tmp)
{
	char	*result;
	size_t	len;

	len = ft_strlen(tmp);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	return (result);
}

static int	ft_remainder(unsigned long long *n, int uppercase)
{
	int	rem;
	int	tmp;

	tmp = *n % 16;
	if (tmp <= 9)
		rem = tmp + '0';
	else
	{
		rem = set_value(tmp);
		if (uppercase)
			rem -= 32;
	}
	*n = *n / 16;
	return (rem);
}

static char	set_value(int tmp)
{
	if (tmp == 10)
		return ('a');
	else if (tmp == 11)
		return ('b');
	else if (tmp == 12)
		return ('c');
	else if (tmp == 13)
		return ('d');
	else if (tmp == 14)
		return ('e');
	else
		return ('f');
}
