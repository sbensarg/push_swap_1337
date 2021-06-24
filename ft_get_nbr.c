/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:47:10 by chicky            #+#    #+#             */
/*   Updated: 2021/06/19 12:27:27 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_int(long a, int s)
{
	long	ret;

	ret = a * s;
	if (ret > INT_MAX || ret < INT_MIN)
		return (-1);
	return (0);
}

static int	max_int(long a, int s)
{
	if (a > 9223372036854775807)
	{
		if (s == -1)
			return (0);
		else if (s == 1)
			return (-1);
	}
	return (1);
}

int	check_digit(const char *str, int *i)
{
	int	j;
	int	flag;

	j = *i;
	flag = 0;
	while (str[j])
	{
		if (!(str[j] >= 48 && str[j] <= 57))
			return (-1);
		j++;
	}
	return (0);
}

int	skip(int *i, const char *str)
{
	int	s;

	s = 1;
	while ((str[*i] >= 8 && str[*i] <= 13) || str[*i] == 32)
		i++;
	if ((str[*i] == '+' || str[*i] == '-') && str[*i + 1] != 0)
	{
		if (str[*i] == '-')
			s = -1;
		*i = *i + 1;
	}
	return (s);
}

int	ft_atoi(const char *str, int *check)
{
	int		i;
	long	a;
	int		s;
	int		f;

	i = 0;
	a = 0;
	s = skip(&i, str);
	f = check_digit(str, &i);
	if (f == -1)
		*check = -1;
	while (str[i] >= 48 && str[i] <= 57)
	{	
		a = a * 10 + str[i++] - 48;
		max_int(a, s);
	}
	f = check_max_int(a, s);
	if (f == -1)
		*check = -1;
	return (a * s);
}
