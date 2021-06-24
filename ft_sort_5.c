/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:29:19 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/19 12:27:12 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(t_pile *actuel)
{
	int	i;

	i = 0;
	while (actuel)
	{
		actuel = actuel->suivant;
		i++;
	}
	return (i);
}

void	ft_sort_5a(t_pile **head_ref, t_pile **head_ref_b)
{
	int		smallest_value;
	t_pile	*actuel;

	smallest_value = ft_find_smallest_nbr(head_ref);
	actuel = *head_ref;
	while (actuel != NULL && actuel->nbr != smallest_value)
	{
		ft_ra(head_ref, 1);
		actuel = *head_ref;
	}
	ft_pb(head_ref, head_ref_b, 1);
}

void	ft_sort_5(t_pile **head_ref, t_pile **head_ref_b)
{
	int		size;

	size = ft_size(*head_ref);
	ft_sort_5a(head_ref, head_ref_b);
	if (size != 4)
		ft_sort_5a(head_ref, head_ref_b);
	ft_sort_3(head_ref);
	ft_pa(head_ref_b, head_ref, 1);
	if (size != 4)
		ft_pa(head_ref_b, head_ref, 1);
}
