/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:39:01 by chicky            #+#    #+#             */
/*   Updated: 2021/05/26 12:46:39 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct element_a element_a;
struct element_a
{
    int     nbr;
    element_a  *suivant;
    
};

typedef struct pile_a pile_a;
struct pile_a
{
    element_a *premier;
};

pile_a  *init();
int    empiler(pile_a *pile, char **argv);
void    afficher_pile_a(pile_a *pile);
int     ft_atoi(const char *str);
int     ft_check(int n, pile_a *pile);
void    ft_sa(pile_a *pile);
void    ft_pb(pile_a *pile, pile_a *pile_b);
void    ft_ra(pile_a *pile);
void    ft_rra(pile_a *pile);



#endif
