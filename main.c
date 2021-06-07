/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:07:53 by chicky            #+#    #+#             */
/*   Updated: 2021/06/07 13:24:18 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int agrc, char **argv)
{
    t_pile *pile = NULL;
    t_pile *pile_b = NULL;
    int ret;
    int pos;
 
    if (agrc >= 2)
    {

       if ((ret =  empiler(&pile, argv)) != 2)
       {
      
            //ft_sort_100(&pile, &pile_b);
            ft_sort_100_global(&pile, &pile_b);
            rec_pa(&pile, &pile_b);
          // ft_sort_500(&pile, &pile_b);
          // rec_pa(&pile, &pile_b);
          
              print_pile(pile);
            // printf("---------------\n");
            // print_pile(pile_b);
       }
        else
            printf("Error\n");
    }
   
    
  
    return 0;
}
