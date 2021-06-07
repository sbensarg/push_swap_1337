/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:39:01 by chicky            #+#    #+#             */
/*   Updated: 2021/06/07 18:32:10 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>

typedef struct  s_pile {
    int             nbr;
    struct s_pile   *suivant;
}               t_pile;
int		ft_atoi(const char *str);
int     empiler(t_pile **head_ref, char **argv);
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
int     ft_check(int n, t_pile *actuel);
void    ft_sort_3(t_pile **head_ref);
int ft_find_smallest_nbr(t_pile **head_ref, int *pos);
void    ft_sort_5(t_pile **head_ref,t_pile **head_ref_b);
int ft_sort_100(t_pile **head_ref,t_pile **head_ref_b);
void rec_pa(t_pile **head_ref,t_pile **head_ref_b);
void    reverse_print(t_pile *head);
int     ft_size(t_pile *actuel);
int ft_sort_100_b(t_pile **head_ref, int  argc);
int ft_find_biggest_nbr(t_pile **head_ref, int *pos);
int ft_sort_500(t_pile **head_ref,t_pile **head_ref_b);
void ft_sort_100_global(t_pile **head_ref,t_pile **head_ref_b);
int ft_find_end_of_interval(t_pile **head_ref , int i);



#endif
