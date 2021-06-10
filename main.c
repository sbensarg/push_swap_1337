/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:07:53 by chicky            #+#    #+#             */
/*   Updated: 2021/06/10 15:35:52 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int agrc, char **argv)
{
    t_pile *pile = NULL;
    t_pile *pile_b = NULL;
    int ret;
    int first_nbr_from_top;
    int first_nbr_from_bottom;
    int pos1;
    int pos2;
    
    int pos;
 
    if (agrc >= 2)
    {

       if ((ret =  empiler(&pile, argv)) != 2)
       {
      
      //  first_nbr_from_top = scan(pile, 1, 2, &pos1);
      //   first_nbr_from_bottom = reverse_scan(pile, 1, 2, &pos2);
      //   printf("top %d == %d pos\n", first_nbr_from_top, pos1);
      //   printf("bottom %d == %d pos\n", first_nbr_from_bottom, pos2);
            //ft_sort_100(&pile, &pile_b);
          ft_sort_100_global(&pile, &pile_b);
           rec_pa(&pile, &pile_b);

          // ft_sort_3(&pile);
          // ft_sort_500(&pile, &pile_b);
          // rec_pa(&pile, &pile_b);
         

  
          
              //print_pile(pile);
            // printf("---------------\n");
            // print_pile(pile);
       }
        else
            printf("Error\n");
    }
   
    
  
    return 0;
}
