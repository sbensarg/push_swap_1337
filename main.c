/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:34:51 by chicky            #+#    #+#             */
/*   Updated: 2021/05/25 20:59:26 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    
    pile_a *a;
    pile_a *b;
    
    a = init();
    b = init();
    
    i = 0;
    if (argc >= 2)
    {
        empiler(a, argv);
        afficher_pile_a(a);
        // ft_sa(a);
        // afficher_pile_a(a);
       // ft_pb(a, b);
      //  afficher_pile_a(b);

       // afficher_pile_a(a);
        ft_ra(a);
        afficher_pile_a(a);
       // afficher_pile_a(a);
        
            // if (ft_check(ft_atoi(argv[i]), a) == 0) 
            //     afficher_pile_a(a);
            // else
            //     printf("error1\n");
    }
    return (1);  
}