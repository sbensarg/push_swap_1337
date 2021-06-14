/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:47:10 by chicky            #+#    #+#             */
/*   Updated: 2021/06/14 11:45:03 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_max_int(long a, int s)
{
	long ret;
	ret = a * s;
	if (ret > INT_MAX)
	{
		write(2, "Error\n", 7);
		exit (0);
	}
	else if (ret < INT_MIN)
	{
		write(2, "Error\n", 7);
		exit (0);
	}	
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

int			ft_atoi(const char *str)
{
	int		i;
	long	a;
	int		s;
	int		j;

	i = 0;
	a = 0;
	s = 1;
	j = 0;
	
	while ((str[i] >= 8 && str[i] <= 13) || str[i] == 32)
	{
		if (str[i] == 27)
			return (0);
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	j = i;
	while (str[j])
	{
		if (!(str[j] >= 48 && str[j] <= 57))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		j++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{	
		a = a * 10 + str[i++] - 48;
		max_int(a, s);
	}
	check_max_int(a, s);
	return (a * s);
}