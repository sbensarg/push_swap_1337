/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:39:01 by chicky            #+#    #+#             */
/*   Updated: 2021/05/30 13:47:24 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

typedef struct  s_pile {
    int             nbr;
    struct s_pile   *suivant;
}               t_pile;
int		ft_atoi(const char *str);
int    empiler(t_pile **head_ref, char **argv);
void    print_pile(t_pile *pile);
void    ft_sa(t_pile **head_ref);
void    ft_sb(t_pile **head_ref_b);
void    ft_ra(t_pile **head_ref);
void    ft_rb(t_pile **head_ref_b);
void    ft_rr(t_pile **head_ref, t_pile **head_ref_b);
void    ft_rra(t_pile **head_ref);
void    ft_rrb(t_pile **head_ref_b);
void    ft_pb(t_pile **head_ref_a, t_pile **head_ref_b);
void    ft_pa(t_pile **head_ref_b, t_pile **head_ref_a);
void    ft_ss(t_pile **head_ref, t_pile **head_ref_b);
int     ft_check(int n, t_pile **head_ref);
void    ft_sort_3(t_pile **head_ref);
int     ft_find_smallest_nbr(t_pile **head_ref);
void    ft_sort_5(t_pile **head_ref,t_pile **head_ref_b);
int     ft_sort_100(t_pile **head_ref,t_pile **head_ref_b);
void    rec_pa(t_pile **head_ref,t_pile **head_ref_b);


#endif
