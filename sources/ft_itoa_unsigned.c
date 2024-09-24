/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:29:22 by dzubkova          #+#    #+#             */
/*   Updated: 2024/09/24 17:44:12 by dzubkova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_itoa_unsigned(unsigned int n);
static char	*allocate_space(char *tmp);
static char	*edge_cases(int n);
static int	ft_remainder(unsigned int *n);

char	*ft_itoa_unsigned(unsigned int n)
{
	char	tmp[12];
	char	*res;
	int		idx;
	char	*start;

	res = edge_cases(n);
	if (res)
		return (res);
	free(res);
	idx = 0;
	while (n)
		tmp[idx++] = ft_remainder(&n);
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

static char	*edge_cases(int n)
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

static int	ft_remainder(unsigned int *n)
{
	int	rem;

	rem = (*n % 10) + '0';
	*n = *n / 10;
	return (rem);
}
