/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 16:43:57 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/16 19:10:52 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_scan(t_pile *head, int start, int end, int *pos)
{
	int	i;
	int	ret;

	i = 0;
	while (head && head->suivant != NULL)
	{
		if (head->nbr >= start && head->nbr <= end)
		{
			*pos = i;
			ret = head->nbr;
		}
		i++;
		head = head->suivant;
	}
	return (ret);
}

int	scan(t_pile *head, int start, int end, int *pos)
{
	t_pile	*cur;

	cur = head;
	while (cur && cur->suivant != NULL)
	{
		if (cur->nbr >= start && cur->nbr <= end)
			break ;
		cur = cur->suivant;
		*pos = *pos + 1;
	}
	return (cur->nbr);
}

int	ft_find_smallest_nbr(t_pile **head_ref)
{
	int		max_value;
	t_pile	*actuel;

	max_value = INT_MAX;
	actuel = *head_ref;
	while (actuel != NULL)
	{
		if (actuel->nbr < max_value)
			max_value = actuel->nbr;
		actuel = actuel->suivant;
	}
	return (max_value);
}

int	ft_find_biggest_nbr(t_pile **head_ref, int s)
{
	t_pile	*actuel;

	actuel = *head_ref;
	while (actuel != NULL)
	{
		if (actuel->nbr > s)
			s = actuel->nbr;
		actuel = actuel->suivant;
	}
	return (s);
}

int	pos_biggest_nbr(t_pile **head_ref, int nbr)
{
	int		pos;
	t_pile	*actuel;

	pos = 0;
	actuel = *head_ref;
	while (actuel != NULL && actuel->nbr != nbr)
	{
		actuel = actuel->suivant;
		pos++;
	}
	return (pos);
}
