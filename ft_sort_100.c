/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:31:47 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/17 13:40:59 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_tab_from_list(t_pile **head_ref)
{
	int		*tab;
	t_pile	*actuel;
	int		j;

	actuel = *head_ref;
	j = 0;
	tab = malloc((ft_size(actuel) + 1) * sizeof(int));
	if (tab == NULL)
		return (NULL);
	while (actuel != NULL)
	{
		tab[j] = actuel->nbr;
		j++;
		actuel = actuel->suivant;
	}
	tab[j] = '\0';
	return (tab);
}

int	ft_find_end_of_interval(t_pile **head_ref, int i, int size)
{
	int		*tab;
	int		temp;
	int		j;
	int		ret;

	j = 0;
	tab = fill_tab_from_list(head_ref);
	while (j < size - 1)
	{
		if (tab[j] > tab[j + 1])
		{
			temp = tab[j];
			tab[j] = tab[j + 1];
			tab[j + 1] = temp;
			j = -1;
		}
		j++;
	}
	ret = tab[i - 1];
	free (tab);
	return (ret);
}

void	ft_sort_100_inter(t_pile **head_ref, t_pile **head_ref_b, int interval)
{
	int		j;
	t_data	data;

	j = 0;
	data.start = ft_find_smallest_nbr(head_ref);
	data.end = ft_find_end_of_interval(head_ref, interval, ft_size(*head_ref));
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

void	ft_sort_100_global(t_pile **head_ref, t_pile **head_ref_b)
{
	int		j;
	t_data	data;

	j = 0;
	data.size = ft_size(*head_ref);
	data.interval = data.size / 5;
	while (j < 4)
	{
		ft_sort_100_inter(head_ref, head_ref_b, data.interval);
		j++;
	}
	ft_sort_100_inter(head_ref, head_ref_b, ft_size(*head_ref));
}

void	rec_pa(t_pile **head_ref, t_pile **head_ref_b)
{
	int		biggest_nbr;
	int		s;
	int		pos1;

	while (ft_size(*head_ref_b) > 0)
	{
		s = ft_find_smallest_nbr(head_ref_b);
		biggest_nbr = ft_find_biggest_nbr(head_ref_b, s);
		pos1 = pos_biggest_nbr(head_ref_b, biggest_nbr);
		if (pos1 <= ft_size(*head_ref_b) / 2)
			while ((*head_ref_b)->nbr != biggest_nbr)
				ft_rb(head_ref_b, 1);
		else
			while ((*head_ref_b)->nbr != biggest_nbr)
				ft_rrb(head_ref_b, 1);
		ft_pa(head_ref_b, head_ref, 1);
	}
}
