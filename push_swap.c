/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:57:03 by chicky            #+#    #+#             */
/*   Updated: 2021/06/11 17:03:00 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pile **head_ref, int flag)
{
	t_pile	*first;
	t_pile	*last;

	first = *head_ref;
	last = *head_ref;
	if (*head_ref == NULL || (*head_ref)->suivant == NULL)
		return ;
	while (last->suivant != NULL)
		last = last->suivant;
	*head_ref = first->suivant;
	first->suivant = NULL;
	last->suivant = first;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rr(t_pile **head_ref, t_pile **head_ref_b)
{
	ft_ra(head_ref, 1);
	ft_rb(head_ref_b, 1);
	write(1, "rr\n", 3);
}

void	ft_rra(t_pile **head_ref, int flag)
{
	t_pile	*sec_last;
	t_pile	*last;

	sec_last = *head_ref;
	last = *head_ref;
	if (*head_ref == NULL || (*head_ref)->suivant == NULL)
		return ;
	while (last->suivant != NULL)
	{
		sec_last = last;
		last = last->suivant;
	}
	sec_last->suivant = NULL;
	last->suivant = *head_ref;
	*head_ref = last;
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	ft_sa(t_pile **head_ref, int flag)
{
	t_pile	*actuel;
	int		tmp;

	actuel = *head_ref;
	tmp = actuel->nbr;
	actuel->nbr = (actuel->suivant)->nbr;
	(actuel->suivant)->nbr = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_pa(t_pile **head_ref_b, t_pile **head_ref_a, int flag)
{
	t_pile	*b;
	t_pile	*a;

	b = (*head_ref_b)->suivant;
	a = *head_ref_a;
	*head_ref_a = *head_ref_b;
	(*head_ref_a)->suivant = a;
	(*head_ref_b) = b;
	if (flag == 1)
		write(1, "pa\n", 3);
}
