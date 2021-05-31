/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 17:07:53 by chicky            #+#    #+#             */
/*   Updated: 2021/05/30 23:20:37 by chicky           ###   ########.fr       */
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
            // printf("\n");
             ft_sort_3(&pile);
            //  print_pile(pile_b);
            //   printf("\n");
            // rec_pa(&pile, &pile_b);
          // ret = ft_find_smallest_nbr(&pile);
             print_pile(pile);
           
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