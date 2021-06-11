/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_500.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:45:48 by chicky            #+#    #+#             */
/*   Updated: 2021/06/11 17:01:51 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_500_inter(t_pile **head_ref, t_pile **head_ref_b, int interval)
{
	int		j;
	t_data	data;

	j = 0;
	data.start = ft_find_smallest_nbr(head_ref);
	data.end = ft_find_end_of_interval(head_ref, interval);
	while (j < interval)
	{
		data.pos1 = 0;
		data.pos2 = 0;
		data.top = scan(*head_ref, data.start, data.end, &data.pos1);
		data.bottom = reverse_scan(*head_ref, data.start, data.end, &data.pos2);
		if (data.pos1 <= ft_size(*head_ref) - data.pos2)
			while (data.top != (*head_ref)->nbr)
				ft_ra(head_ref, 1);
		else
			while (data.bottom != (*head_ref)->nbr)
				ft_rra(head_ref, 1);
		if ((*head_ref)->nbr >= data.start && (*head_ref)->nbr <= data.end)
			ft_pb(head_ref, head_ref_b, 1);
		j++;
	}
}

void	ft_sort_500_global(t_pile **head_ref, t_pile **head_ref_b)
{
	int		s;
	int		j;
	t_data	data;

	j = 0;
	s = ft_find_smallest_nbr(head_ref);
	data.size = ft_size(*head_ref);
	data.interval = data.size / 11;
	while (j < 10)
	{
		ft_sort_500_inter(head_ref, head_ref_b, data.interval);
		j++;
	}
	ft_sort_500_inter(head_ref, head_ref_b, ft_size(*head_ref));
}