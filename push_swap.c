/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:57:03 by chicky            #+#    #+#             */
/*   Updated: 2021/06/10 18:05:02 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_pile **head_ref)
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
	write(1, "ra\n", 3);
}

void	ft_rr(t_pile **head_ref, t_pile **head_ref_b)
{
	ft_ra(head_ref);
	ft_rb(head_ref_b);
	write(1, "rr\n", 3);
}

void	ft_rra(t_pile **head_ref)
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
	write(1, "rra\n", 4);
}

void	ft_sa(t_pile **head_ref)
{
	t_pile	*actuel;
	int		tmp;

	actuel = *head_ref;
	tmp = actuel->nbr;
	actuel->nbr = (actuel->suivant)->nbr;
	(actuel->suivant)->nbr = tmp;
	write(1, "sa\n", 3);
}

void	ft_pa(t_pile **head_ref_b, t_pile **head_ref_a)
{
	t_pile	*b;
	t_pile	*a;

	b = (*head_ref_b)->suivant;
	a = *head_ref_a;
	*head_ref_a = *head_ref_b;
	(*head_ref_a)->suivant = a;
	(*head_ref_b) = b;
	write(1, "pa\n", 3);
}
