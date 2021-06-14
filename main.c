/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:07:53 by chicky            #+#    #+#             */
/*   Updated: 2021/06/14 12:57:00 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_if_sorted(t_pile **head_ref)
{
	t_pile *cur;

	cur = *head_ref;

	while (cur != NULL && cur->suivant != NULL)
	{
		if ((cur->suivant)->nbr < cur->nbr)
			return (-1);
		cur = cur->suivant;
	}
	return (0);
}

void freelist(t_pile *head_ref)
{
  	t_pile *tmp;

   while (head_ref != NULL)
    {
       tmp = head_ref;
       head_ref = head_ref->suivant;
       free(tmp);
    }

}
int main(int argc, char **argv)
{
    t_pile *pile = NULL;
    t_pile *pile_b = NULL;
    int ret;
	int size;
	int f;
 
    if (argc >= 2)
    {
       if ((ret =  empiler(&pile, argv)) != 2)
       {
		   size = ft_size(pile);
			f = ft_check_if_sorted(&pile);
		   	if (f == 0)
		   		return (0);
		   if (size == 3 || size == 2)
		   		ft_sort_3(&pile);
		   else if (size == 5 || size == 4)
		   		ft_sort_5(&pile, &pile_b);
		   else if (size > 5 && size <= 100)
		   {
			   ft_sort_100_global(&pile, &pile_b);
			   rec_pa(&pile, &pile_b);
		   }
		   else if (size > 100)
		   {
			   ft_sort_500_global(&pile, &pile_b);
			   rec_pa(&pile, &pile_b);
		   }
		  // system ("leaks push_swap");
       }
        else
            printf("Error\n");
    }
    return 0;
}
