/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chicky <chicky@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:57:03 by chicky            #+#    #+#             */
/*   Updated: 2021/05/29 21:43:41 by chicky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check(int n, t_pile **head_ref)
{
     if(*head_ref == NULL || (*head_ref)->suivant == NULL)
        return (0);
    t_pile *actuel;
    actuel = *head_ref;
    while (actuel != NULL)
    {
        if (actuel->nbr == n)
            return (1);
        actuel = actuel->suivant;
    }
    return (0);
}

int empiler(t_pile **head_ref, char **argv)
{
    t_pile *new_node;
    int new_nbr;
    int i;
    
    i = 1;
    while (argv[i])
    {
        if (*head_ref == NULL)
        {
            new_node = malloc(sizeof(t_pile));
            *head_ref = new_node;
        }
        else
        {
            new_node->suivant = malloc(sizeof(t_pile));
            new_node = new_node->suivant;
        }
        new_nbr = ft_atoi(argv[i]);
          if (ft_check(new_nbr, head_ref))
            return(2);
        new_node->nbr = new_nbr;
        i++;
    }
}

void print_pile(t_pile *pile)
{
    while (pile != NULL)
    {
        printf("%d ", pile->nbr);
        pile = pile->suivant;
    }
}

void ft_ra(t_pile **head_ref)
{
    if(*head_ref == NULL || (*head_ref)->suivant == NULL)
        return;

    t_pile *first;
    t_pile *last;
    
    first = *head_ref;
    last = *head_ref;

    while (last->suivant != NULL)
    {
        last = last->suivant;
    }
    
    *head_ref = first->suivant;
    first->suivant = NULL;
    last->suivant = first;
    printf("ra\n");
}

void ft_rb(t_pile **head_ref_b)
{
    if(*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
        return;

    t_pile *first;
    t_pile *last;
    
    first = *head_ref_b;
    last = *head_ref_b;

    while (last->suivant != NULL)
    {
        last = last->suivant;
    }
    
    *head_ref_b = first->suivant;
    first->suivant = NULL;
    last->suivant = first;
     printf("rb\n");
}
void ft_rr(t_pile **head_ref, t_pile **head_ref_b)
{
    ft_ra(head_ref);
    ft_rb(head_ref_b);
     printf("rr\n");
}



void ft_rrb(t_pile **head_ref_b)
{
    if(*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
        return;
    t_pile *sec_last;
    t_pile *last;
    
    sec_last = *head_ref_b;
    last = *head_ref_b;
    
    while (last->suivant != NULL)
    {
        sec_last = last;
        last = last->suivant;
    }
    
    sec_last->suivant = NULL;
    last->suivant = *head_ref_b;
    *head_ref_b = last;
     printf("rrb\n");
        
}
void ft_rra(t_pile **head_ref)
{
    if(*head_ref == NULL || (*head_ref)->suivant == NULL)
        return;
    t_pile *sec_last;
    t_pile *last;
    
    sec_last = *head_ref;
    last = *head_ref;
    
    while (last->suivant != NULL)
    {
        sec_last = last;
        last = last->suivant;
    }
    
    sec_last->suivant = NULL;
    last->suivant = *head_ref;
    *head_ref = last;
    printf("rra\n");
        
}

void ft_rrr(t_pile **head_ref, t_pile **head_ref_b)
{
    ft_rra(head_ref);
    ft_rrb(head_ref_b);
}

void ft_sa(t_pile **head_ref)
{
    if(*head_ref == NULL || (*head_ref)->suivant == NULL)
        return;
    t_pile *actuel;
    int tmp;
    
    actuel = *head_ref;
    
    tmp = actuel->nbr;
    actuel->nbr = (actuel->suivant)->nbr;
    (actuel->suivant)->nbr = tmp;
     printf("sa\n");
}


void ft_sb(t_pile **head_ref_b)
{
    if(*head_ref_b == NULL || (*head_ref_b)->suivant == NULL)
        return;
    t_pile *actuel;
    int tmp;
    
    actuel = *head_ref_b;
    
    tmp = actuel->nbr;
    actuel->nbr = (actuel->suivant)->nbr;
    (actuel->suivant)->nbr = tmp;
     printf("sb\n");
}

void ft_ss(t_pile **head_ref, t_pile **head_ref_b)
{
    ft_sa(head_ref);
    ft_sb(head_ref_b);
     printf("ss\n");
}

void ft_pb(t_pile **head_ref_a, t_pile **head_ref_b)
{
    t_pile *a;
    t_pile *b;
    
    a = (*head_ref_a)->suivant;
    b = *head_ref_b;
    
    *head_ref_b = *head_ref_a;
    (*head_ref_b)->suivant = b;
    (*head_ref_a) = a;
     printf("pb\n");
}
void ft_pa(t_pile **head_ref_b, t_pile **head_ref_a)
{
    t_pile *b;
    t_pile *a;
    
    b = (*head_ref_b)->suivant;
    a = *head_ref_a;
    
    *head_ref_a = *head_ref_b;
    (*head_ref_a)->suivant = a;
    (*head_ref_b) = b;
     printf("pa\n");
}