/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:07:53 by chicky            #+#    #+#             */
/*   Updated: 2021/06/11 19:17:57 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_pile *pile = NULL;
    t_pile *pile_b = NULL;
    int ret;
    int first_nbr_from_top;
    int first_nbr_from_bottom;
    int pos1;
    int pos2;
	int size;

    
    int pos;
 
    if (argc >= 2)
    {
       if ((ret =  empiler(&pile, argv)) != 2)
       {
		   size = ft_size(pile);
		   if (size == 3)
		   		ft_sort_3(&pile);
		   else if (size == 5)
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
       }
        else
            printf("Error\n");
    }
    return 0;
}
