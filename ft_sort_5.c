/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:29:19 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/10 15:31:15 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5(t_pile **head_ref, t_pile **head_ref_b)
{
	int		smallest_value;
	t_pile	*actuel;

	smallest_value = ft_find_smallest_nbr(head_ref);
	actuel = *head_ref;
	while (actuel != NULL && actuel->nbr != smallest_value)
	{
		ft_ra(head_ref);
		actuel = *head_ref;
	}
	ft_pb(head_ref, head_ref_b);
	smallest_value = ft_find_smallest_nbr(head_ref);
	actuel = *head_ref;
	while (actuel != NULL && actuel->nbr != smallest_value)
	{
		ft_ra(head_ref);
		actuel = *head_ref;
	}
	ft_pb(head_ref, head_ref_b);
	ft_sort_3(head_ref);
	ft_pa(head_ref_b, head_ref);
	ft_pa(head_ref_b, head_ref);
}
