/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:30:28 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/11 17:03:15 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_pile **head_ref_b, int flag)
{
	t_pile	*first;
	t_pile	*last;

	first = *head_ref_b;
	last = *head_ref_b;
	if (*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
		return ;
	while (last->suivant != NULL)
		last = last->suivant;
	*head_ref_b = first->suivant;
	first->suivant = NULL;
	last->suivant = first;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rrb(t_pile **head_ref_b, int flag)
{
	t_pile	*sec_last;
	t_pile	*last;

	sec_last = *head_ref_b;
	last = *head_ref_b;
	if (*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
		return ;
	while (last->suivant != NULL)
	{
		sec_last = last;
		last = last->suivant;
	}
	sec_last->suivant = NULL;
	last->suivant = *head_ref_b;
	*head_ref_b = last;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	ft_sb(t_pile **head_ref_b)
{
	t_pile	*actuel;
	int		tmp;

	actuel = *head_ref_b;
	if (*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
		return ;
	tmp = actuel->nbr;
	actuel->nbr = (actuel->suivant)->nbr;
	(actuel->suivant)->nbr = tmp;
	write(1, "sb\n", 3);
}

void	ft_pb(t_pile **head_ref_a, t_pile **head_ref_b, int flag)
{
	t_pile	*a;
	t_pile	*b;

	a = (*head_ref_a)->suivant;
	b = *head_ref_b;
	*head_ref_b = *head_ref_a;
	(*head_ref_b)->suivant = b;
	(*head_ref_a) = a;
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	ft_ss(t_pile **head_ref, t_pile **head_ref_b)
{
	ft_sa(head_ref, 1);
	ft_sb(head_ref_b);
	write(1, "ss\n", 3);
}
