/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:39:01 by chicky            #+#    #+#             */
/*   Updated: 2021/05/25 00:47:39 by chicky           ###   ########.fr       */
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
void    empiler(pile_a *pile, int nv_nbr);
void    afficher_pile_a(pile_a *pile);
int     ft_atoi(const char *str);



#endif
