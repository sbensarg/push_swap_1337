/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:29:06 by sbensarg          #+#    #+#             */
/*   Updated: 2021/06/18 19:47:02 by sbensarg         ###   ########.fr       */
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

int	ft_check(int n, t_pile *actuel, int *check)
{
	if (actuel == NULL || actuel->suivant == NULL)
		return (0);
	while (actuel->suivant != NULL)
	{
		if (actuel->nbr == n)
		{
			*check = -2;
			return (1);
		}
		actuel = actuel->suivant;
	}
	return (0);
}

t_pile	*alloc_pile(void)
{
	t_pile	*ret;

	ret = malloc(sizeof(t_pile));
	if (ret == NULL)
		return (NULL);
	ret->suivant = NULL;
	return (ret);
}

int	fct(t_pile **head_ref, int *i, char **argv)
{
	int		nbr;
	int		check;
	int		j;

	j = *i;
	nbr = ft_atoi(argv[j], &check);
	ft_check(nbr, *head_ref, &check);
	if (check == -1 || check == -2)
	{
		freelist(*head_ref);
		write(2, "Error\n", 6);
		exit(0);
	}
	return (nbr);
}

int	empiler(t_pile **head_ref, char **argv)
{
	t_pile	*new_node;
	int		i;
	int		nbr;

	i = 0;
	while (argv[++i])
	{
		if (*head_ref == NULL)
		{
			new_node = alloc_pile();
			if (!new_node)
				return (1);
			*head_ref = new_node;
		}
		else
		{
			new_node->suivant = alloc_pile();
			if (!new_node->suivant)
				return (1);
			new_node = new_node->suivant;
		}
		nbr = fct(head_ref, &i, argv);
		new_node->nbr = nbr;
	}
	return (0);
}
