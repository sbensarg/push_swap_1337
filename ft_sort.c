/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:45:48 by chicky            #+#    #+#             */
/*   Updated: 2021/05/30 13:49:12 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    ft_sort_3(t_pile **head_ref)
{
    if(*head_ref == NULL || (*head_ref)->suivant == NULL)
        return;
    if((*head_ref)->nbr > ((*head_ref)->suivant)->nbr &&
     ((*head_ref)->suivant)->nbr < (((*head_ref)->suivant)->suivant)->nbr
     && (((*head_ref)->suivant)->suivant)->nbr > (*head_ref)->nbr)
        ft_sa(head_ref);
    else if((*head_ref)->nbr > ((*head_ref)->suivant)->nbr &&
     ((*head_ref)->suivant)->nbr > (((*head_ref)->suivant)->suivant)->nbr
     && (((*head_ref)->suivant)->suivant)->nbr < (*head_ref)->nbr)
    {
        ft_sa(head_ref);
        ft_rra(head_ref);
    }
    else if((*head_ref)->nbr > ((*head_ref)->suivant)->nbr &&
    ((*head_ref)->suivant)->nbr < (((*head_ref)->suivant)->suivant)->nbr
    && (((*head_ref)->suivant)->suivant)->nbr < (*head_ref)->nbr)
        ft_ra(head_ref);
    else if((*head_ref)->nbr < ((*head_ref)->suivant)->nbr &&
    ((*head_ref)->suivant)->nbr > (((*head_ref)->suivant)->suivant)->nbr
    && (((*head_ref)->suivant)->suivant)->nbr > (*head_ref)->nbr)
    {
        ft_sa(head_ref);
        ft_ra(head_ref);
    }
    else if((*head_ref)->nbr < ((*head_ref)->suivant)->nbr &&
    ((*head_ref)->suivant)->nbr > (((*head_ref)->suivant)->suivant)->nbr
    && (((*head_ref)->suivant)->suivant)->nbr < (*head_ref)->nbr)
        ft_rra(head_ref);
}

int ft_find_smallest_nbr(t_pile **head_ref)
{
    int max_value;
    
    max_value = INT_MAX;
    t_pile *actuel;
    
    actuel = *head_ref;
    
    while (actuel != NULL)
    {
        if(actuel->nbr < max_value)
            max_value = actuel->nbr;
        actuel = actuel->suivant;
    } 
    return (max_value); 
}
void    ft_sort_5(t_pile **head_ref,t_pile **head_ref_b)
{
    int smallest_value;
    smallest_value = ft_find_smallest_nbr(head_ref);
    t_pile *actuel;

    actuel = *head_ref;
    while (actuel != NULL && actuel->nbr != smallest_value)
    {
        ft_ra(head_ref);
        actuel = *head_ref;
    }
    ft_pb(head_ref, head_ref_b);
    smallest_value = ft_find_smallest_nbr(head_ref);
    actuel = *head_ref;
    while (actuel != NULL && actuel->nbr != smallest_value)
    {
        ft_ra(head_ref);
        actuel = *head_ref;
    }
    ft_pb(head_ref, head_ref_b);
    ft_sort_3(head_ref);
    ft_pa(head_ref_b, head_ref);
    ft_pa(head_ref_b, head_ref);
}

void rec_pa(t_pile **head_ref,t_pile **head_ref_b)
{
    while (*head_ref_b != NULL)
    {
      ft_pa(head_ref_b, head_ref);
      rec_pa(head_ref, head_ref_b);
    }
}

int ft_sort_100(t_pile **head_ref,t_pile **head_ref_b)
{
    int smallest_value;
    smallest_value = ft_find_smallest_nbr(head_ref);
    t_pile *actuel;

    actuel = *head_ref;
    while (actuel != NULL && actuel->nbr != smallest_value)
    {
        ft_ra(head_ref);
        actuel = *head_ref;
    }
    ft_pb(head_ref, head_ref_b);
    
     while(*head_ref != NULL)
        ft_sort_100(head_ref, head_ref_b);
}