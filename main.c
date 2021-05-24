/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:34:51 by chicky            #+#    #+#             */
/*   Updated: 2021/05/25 00:51:11 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int i;
    pile_a *a;
    
    a = init();
    
    i = 0;
    if (argc >= 2)
    {
       while (argv[i])
       {
           empiler(a, ft_atoi(argv[i]));
           i++;
       }  
         afficher_pile_a(a); 
    }
    else
        printf("error\n");     
}