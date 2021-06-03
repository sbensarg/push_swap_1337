/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:07:53 by chicky            #+#    #+#             */
/*   Updated: 2021/06/03 19:36:55 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int agrc, char **argv)
{
    t_pile *pile = NULL;
    t_pile *pile_b = NULL;
    int ret;
 
    if (agrc >= 2)
    {

       if ((ret =  empiler(&pile, argv)) != 2)
       {
            // print_pile(pile);
             //printf("\n");
            ft_sort_100(&pile, &pile_b, agrc - 1);
         //  ft_sort_100_b(&pile, agrc - 1);
           // ft_sort_100_b(&pile , agrc - 1);
           // reverse_print(pile);
             //reverse_print(pile);
            // ft_sort_3(&pile);
            //  print_pile(pile_b);
              // printf("\n");
           rec_pa(&pile, &pile_b);
          // ret = ft_find_smallest_nbr(&pile);
             print_pile(pile);
           //    printf("\n");
            // print_pile(pile_b);
       }
        else
            printf("Error\n");
            
        // printf("\n");
        // ft_pb(&pile, &pile_b);
        // ft_pb(&pile, &pile_b);
        // ft_pb(&pile, &pile_b);
        // ft_rrb(&pile_b);
        // printf("\n");
        // print_pile(pile_b);
        // printf("\n");
        // print_pile(pile);
        // printf("\n");
        // // ft_sb(&pile_b);
        // print_pile(pile_b);
        // printf("\n");
        // print_pile(pile_b);
        
    }
   
    
  
    return 0;
}


//9 15 8 45 7 

//7 9 15 8 45

//45 7 9 