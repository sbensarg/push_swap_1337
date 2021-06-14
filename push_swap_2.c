/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:29:06 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/14 13:33:45 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_pile **head_ref, t_pile **head_ref_b, int flag)
{
	if (*head_ref == NULL || (*head_ref)->suivant == NULL)
		return ;
	if (*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
		return ;
	ft_rra(head_ref, 0);
	ft_rrb(head_ref_b, 0);
	if (flag == 1)
		write(1, "rrr\n", 3);
}

int	ft_check(int n, t_pile *actuel)
{
	if (actuel == NULL || actuel->suivant == NULL)
		return (0);
	while (actuel->suivant != NULL)
	{
		if (actuel->nbr == n)
			return (1);
		actuel = actuel->suivant;
	}
	return (0);
}
int	first_node(t_pile **head_ref, t_pile *new_node, int *i, char **argv)
{
	int		new_nbr;
	if (*head_ref == NULL)
	{
		new_node = malloc(sizeof(t_pile));
		if (!new_node)
			return (1);
		*head_ref = new_node;
		new_node->suivant = NULL;
	}
	else
	{
		new_node->suivant = malloc(sizeof(t_pile));
		if (!new_node->suivant)
			return (1);
		new_node = new_node->suivant;
		new_node->suivant = NULL;
	}
	new_nbr = ft_atoi(argv[*i]);
	if (ft_check(new_nbr, *head_ref))
		return (2);
	new_node->nbr = new_nbr;
	return (0);
}
int	empiler(t_pile **head_ref, char **argv)
{
	t_pile	*new_node;
	int		new_nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (*head_ref == NULL)
		{
			new_node = malloc(sizeof(t_pile));
			if (!new_node)
				return (1);
			*head_ref = new_node;
			new_node->suivant = NULL;
			
		}
		else
		{
			new_node->suivant = malloc(sizeof(t_pile));
			if (!new_node->suivant)
				return (1);
			new_node = new_node->suivant;
			new_node->suivant = NULL;
		}
		new_nbr = ft_atoi(argv[i]);
		if (ft_check(new_nbr, *head_ref))
			return (2);
		new_node->nbr = new_nbr;
		// first_node(head_ref, new_node, &i, argv);
		i++;
	}
	return (0);
}

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
