/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:29:19 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/14 13:27:42 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5(t_pile **head_ref, t_pile **head_ref_b)
{
	int		smallest_value;
	t_pile	*actuel;
	int size;
	
	size = ft_size(*head_ref);
	smallest_value = ft_find_smallest_nbr(head_ref);
	actuel = *head_ref;
	while (actuel != NULL && actuel->nbr != smallest_value)
	{
		ft_ra(head_ref, 1);
		actuel = *head_ref;
	}
	ft_pb(head_ref, head_ref_b, 1);
	if (size != 4)
	{
		smallest_value = ft_find_smallest_nbr(head_ref);
		actuel = *head_ref;
		while (actuel != NULL && actuel->nbr != smallest_value)
		{
			ft_ra(head_ref, 1);
			actuel = *head_ref;
		}
		ft_pb(head_ref, head_ref_b, 1);
	}
	ft_sort_3(head_ref);
	ft_pa(head_ref_b, head_ref, 1);
	if (size != 4)
		ft_pa(head_ref_b, head_ref, 1);
}
