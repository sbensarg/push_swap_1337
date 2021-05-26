/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:16:37 by chicky            #+#    #+#             */
/*   Updated: 2021/05/26 13:29:40 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


pile_a *init()
{
    pile_a *pile;
    pile = malloc(sizeof(pile_a));
    pile->premier = malloc(sizeof(element_a));
    pile->premier->suivant = NULL;
    return(pile);
}

int empiler(pile_a *pile, char **argv)
{
    element_a   *tmp;
    element_a   *nouveau;
    int         i;
    int         arg;
    
    i = 1;
    if (pile == NULL)
        exit(EXIT_FAILURE);
    nouveau = pile->premier;
    while (argv[i])
    {
        arg = ft_atoi(argv[i]);
        // if (ft_check(arg, pile))
        //     return(printf("Error\n"));
        nouveau->nbr = arg;
        nouveau->suivant = malloc(sizeof(element_a));
        nouveau->suivant->suivant = NULL;
        nouveau = nouveau->suivant;
        i++;
    } 
    return (0);
}

int ft_check(int n, pile_a *pile)
{
    if (pile == NULL)
        exit (EXIT_FAILURE);
    element_a *actuel = pile->premier;
    while (actuel != NULL)
    {
        if (actuel->nbr == n)
            return (1);
        actuel = actuel->suivant;
    }
    return (0);
}

void afficher_pile_a(pile_a *pile)
{
    if (pile == NULL)
        exit(EXIT_FAILURE);
        
    element_a *actuel = pile->premier;
    while (actuel->suivant != NULL)
    {
        printf("%d\n", actuel->nbr);
        actuel = actuel->suivant;
    }
    printf("\n"); 
}

void ft_sa(pile_a *pile)
{
    if (pile == NULL)
        exit(EXIT_FAILURE);
    
    element_a *actuel;
    int tmp;
    
    actuel = pile->premier;

    tmp = actuel->nbr;
    actuel->nbr = (actuel->suivant)->nbr;
    (actuel->suivant)->nbr = tmp;
}

void ft_sb(pile_a *pile_b)
{
    if (pile_b == NULL)
        exit(EXIT_FAILURE);
    
    element_a *actuel;
    int tmp;
    
    actuel = pile_b->premier;

    tmp = actuel->nbr;
    actuel->nbr = (actuel->suivant)->nbr;
    (actuel->suivant)->nbr = tmp;
}
void ft_ss(pile_a *pile, pile_a *pile_b)
{
    ft_sa(pile);
    ft_sb(pile_b);
}

void ft_pb(pile_a *pile, pile_a *pile_b)
{
    if (pile == NULL || pile_b == NULL)
        exit(EXIT_FAILURE);

    element_a  *tmp;
    element_a  *tmp2;

    tmp = pile_b->premier;
    tmp2 = pile->premier->suivant;
    pile_b->premier = pile->premier;
    pile_b->premier->suivant = tmp;
    pile->premier = tmp2;
}

void ft_ra(pile_a *pile)
{
    if (pile == NULL)
        exit(EXIT_FAILURE);

        element_a *first;
        element_a *last;
    
    
        first = pile->premier;
        last = pile->premier;

        while (last->suivant != NULL)
        {
            last = last->suivant;      
        }
        pile->premier = pile->premier->suivant;
        first->suivant = NULL;
        last->nbr = first->nbr;
        last->suivant = first;
}

void ft_rra(pile_a *pile)
{
    if (pile == NULL)
        exit(EXIT_FAILURE);

        element_a *seclast;
        element_a *last;
    
    
        seclast = NULL;
        last = pile->premier;

        while (last->suivant != NULL)
        {
            seclast = last;
            last = last->suivant;      
        }

        seclast->suivant = NULL;
        last->suivant = pile->premier; 
        last->nbr = seclast->nbr;
        pile->premier= last; 
}
      
   
    
    