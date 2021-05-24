/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:16:37 by chicky            #+#    #+#             */
/*   Updated: 2021/05/25 00:34:28 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


pile_a *init()
{
    pile_a *pile = malloc(sizeof(*pile));
    pile->premier = NULL;
    
}
void empiler(pile_a *pile, int nv_nbr)
{
    element_a *nouveau = malloc(sizeof(*nouveau));
    if (pile == NULL || nouveau == NULL)
        exit(EXIT_FAILURE);

    nouveau-> nbr = nv_nbr;
    nouveau->suivant = pile->premier;
    pile->premier = nouveau;
}

void afficher_pile_a(pile_a *pile)
{
    if (pile == NULL)
        exit(EXIT_FAILURE);
        
    element_a *actuel = pile->premier;
    while (actuel != NULL)
    {
        printf("%d\n", actuel->nbr);
        actuel = actuel->suivant;
    }
    printf("\n");
    
    
}