/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 15:06:27 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/10 15:28:10 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3a(t_pile **head_ref)
{
	if ((*head_ref)->nbr > ((*head_ref)->suivant)->nbr
		&& ((*head_ref)->suivant)->nbr < (((*head_ref)->suivant)->suivant)->nbr
		&& (((*head_ref)->suivant)->suivant)->nbr > (*head_ref)->nbr)
		ft_sa(head_ref);
	else if ((*head_ref)->nbr > ((*head_ref)->suivant)->nbr
		&& ((*head_ref)->suivant)->nbr > (((*head_ref)->suivant)->suivant)->nbr
		&& (((*head_ref)->suivant)->suivant)->nbr < (*head_ref)->nbr)
	{
		ft_sa(head_ref);
		ft_rra(head_ref);
	}
	else if ((*head_ref)->nbr > ((*head_ref)->suivant)->nbr
		&& ((*head_ref)->suivant)->nbr < (((*head_ref)->suivant)->suivant)->nbr
		&& (((*head_ref)->suivant)->suivant)->nbr < (*head_ref)->nbr)
		ft_ra(head_ref);
}

void	ft_sort_3b(t_pile **head_ref)
{
	if ((*head_ref)->nbr < ((*head_ref)->suivant)->nbr
		&& ((*head_ref)->suivant)->nbr > (((*head_ref)->suivant)->suivant)->nbr
		&& (((*head_ref)->suivant)->suivant)->nbr > (*head_ref)->nbr)
	{
		ft_sa(head_ref);
		ft_ra(head_ref);
	}
	else if ((*head_ref)->nbr < ((*head_ref)->suivant)->nbr
		&& ((*head_ref)->suivant)->nbr > (((*head_ref)->suivant)->suivant)->nbr
		&& (((*head_ref)->suivant)->suivant)->nbr < (*head_ref)->nbr)
		ft_rra(head_ref);
}

void	ft_sort_3(t_pile **head_ref)
{
	if (*head_ref == NULL || (*head_ref)->suivant == NULL)
		return ;
	ft_sort_3a(head_ref);
	ft_sort_3b(head_ref);
}
