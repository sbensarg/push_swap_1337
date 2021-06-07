/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:45:48 by chicky            #+#    #+#             */
/*   Updated: 2021/06/07 18:58:01 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_print(t_pile *head) 
{
    t_pile *newHead = NULL, *cur = head;

    if(!head) return;

    // Reverse the link list O(n) time O(1) space
    while(cur){
        head = head->suivant;
        cur->suivant = newHead;
        newHead = cur;
        cur = head;
    }

    // Print the list O(n) time O(1) space
    cur = newHead;
    while(cur) {
        printf(" %d", cur->nbr);
        cur = cur->suivant;
    }

    // Reverse the link list again O(n) time O(1) space
    cur = newHead;
    while(cur){
        newHead = newHead->suivant;
        cur->suivant = head;
        head = cur;
        cur = newHead;
    }
    // Total complexity O(n) time O(1) space
}


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

int ft_find_smallest_nbr(t_pile **head_ref, int *pos)
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
    actuel = *head_ref;
    while (actuel->nbr != max_value)
    {
        *pos = *pos + 1;
        actuel = actuel->suivant;
    }
    return (max_value); 
}
int ft_find_biggest_nbr(t_pile **head_ref, int *pos)
{
    int max_value;
    
    max_value = 0;
    t_pile *actuel;
    
    actuel = *head_ref;
    
    while (actuel != NULL)
    {
        if(actuel->nbr > max_value)
            max_value = actuel->nbr;
        actuel = actuel->suivant;
    } 
    actuel = *head_ref;
    while (actuel->nbr != max_value)
    {
        *pos = *pos + 1;
        actuel = actuel->suivant;
    }
    return (max_value); 
}

// void    ft_sort_5(t_pile **head_ref,t_pile **head_ref_b)
// {
//     int smallest_value;
//     smallest_value = ft_find_smallest_nbr(head_ref);
//     t_pile *actuel;

//     actuel = *head_ref;
//     while (actuel != NULL && actuel->nbr != smallest_value)
//     {
//         ft_ra(head_ref);
//         actuel = *head_ref;
//     }
//     ft_pb(head_ref, head_ref_b);
//     smallest_value = ft_find_smallest_nbr(head_ref);
//     actuel = *head_ref;
//     while (actuel != NULL && actuel->nbr != smallest_value)
//     {
//         ft_ra(head_ref);
//         actuel = *head_ref;
//     }
//     ft_pb(head_ref, head_ref_b);
//     ft_sort_3(head_ref);
//     ft_pa(head_ref_b, head_ref);
//     ft_pa(head_ref_b, head_ref);
// }


int ft_size(t_pile *actuel)
{
    int i;

    i = 0;
    while (actuel)
    {
        actuel = actuel->suivant;
        i++;
    }
    return (i);
}

void ft_sort_100_inter(t_pile **head_ref,t_pile **head_ref_b, int start, int end, int interval)
{
    t_pile *actuel;
    int j;
    int c;
    
    actuel = *head_ref;
    j = 0;
    c = 0;

    while (j < interval)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= start && actuel->nbr < end)
                    break;
                actuel = actuel->suivant;
                c++;
        }
        
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= ft_size(*head_ref) / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= start && (*head_ref)->nbr < end)
            ft_pb(head_ref, head_ref_b);
        j++;
        actuel = *head_ref;
        c = 0;
    }
}
int ft_find_end_of_interval(t_pile **head_ref, int i)
{
    t_pile *actuel;
    int *tab;
    int temp;
    int j;
    
    j = 0;
    actuel = *head_ref;
    tab = malloc(sizeof((ft_size(actuel) + 1) * sizeof(int)));
    while(actuel != NULL)
    {
        tab[j] = actuel->nbr;
        j++;
        actuel = actuel->suivant;
    }
    tab[j] = '\0';
    j = 0;
    while(tab[j + 1])
    {
        if (tab[j] > tab[j + 1])
        {
            temp = tab[j];
            tab[j] = tab[j + 1];
            tab[j + 1] = temp;
            j = -1;
        }
        j++;
    }
    return (tab[i - 1]);
}

void ft_sort_100_global(t_pile **head_ref,t_pile **head_ref_b)
{
    int s;
    int pos1;
    int i;
    int size;
    int j;
    int ret;
    j = 0;
    
    s = ft_find_smallest_nbr(head_ref, &pos1);
    size = ft_size(*head_ref);
    i = size / 5;
    while (j < 5)
    {
        ft_sort_100_inter(head_ref, head_ref_b, s + (i * j), s + (i * j+1), i);
        j++;
    }  
    
}

void rec_pa(t_pile **head_ref,t_pile **head_ref_b)
{
    int c;
    int biggest_nbr;
    int pos1 = 0;
    int x;
    int y;
    int i;
    int j;
    int size;
    t_pile *actuel;
    
    actuel = *head_ref_b;
    j = 0;
    c = 0;
    size = ft_size(*head_ref_b);
    while (size > 0)
    {
        pos1 = 0;
        biggest_nbr = ft_find_biggest_nbr(head_ref_b, &pos1);
        while (actuel != NULL && actuel->nbr != biggest_nbr) 
        {    
            if (pos1 <= size / 2)
                ft_rb(head_ref_b);
            else
                ft_rrb(head_ref_b);
            actuel = *head_ref_b;
        }
        size--;
        ft_pa(head_ref_b, head_ref);
    }
}

int ft_sort_500(t_pile **head_ref,t_pile **head_ref_b)
{
    int x;
    int y;
    int i;
    int pos1;
    int pos2;
    int j;
    int size;
    t_pile *actuel;
     t_pile *actuel2;
    int c;
    
    actuel = *head_ref;
    actuel2 = *head_ref_b;
    c = 0;
    j = 0;
    x = ft_find_smallest_nbr(head_ref, &pos1);
   // y = ft_find_biggest_nbr(head_ref, &pos2);
   // i = (y - x) / 5;
    size = ft_size(*head_ref);
    i = size / 11;

    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x && actuel->nbr < x + i)
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x && (*head_ref)->nbr < x + i)
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= (x + i) && actuel->nbr < x + (i * 2))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= (x + i) && (*head_ref)->nbr < x + (i * 2))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 2) && actuel->nbr < x + (i * 3))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 2) && (*head_ref)->nbr < x + (i * 3))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 3) && actuel->nbr < x + (i * 4))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 3) && (*head_ref)->nbr < x + (i * 4))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 4) && actuel->nbr < x + (i * 5))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 4) && (*head_ref)->nbr < x + (i * 5))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
        c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 5) && actuel->nbr < x + (i * 6))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 5) && (*head_ref)->nbr < x + (i * 6))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
        c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 6) && actuel->nbr < x + (i * 7))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 6) && (*head_ref)->nbr < x + (i * 7))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
        c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 7) && actuel->nbr < x + (i * 8))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 7) && (*head_ref)->nbr < x + (i * 8))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 8) && actuel->nbr < x + (i * 9))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 8) && (*head_ref)->nbr < x + (i * 9))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < i)
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 9) && actuel->nbr < x + (i * 10))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 9) && (*head_ref)->nbr < x + (i * 10))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    c = 0;
    j = 0;
    while (j < (i + fmod(500, 11)))
    {
        while (actuel != NULL) 
        {
                if (actuel->nbr >= x + (i * 10) && actuel->nbr < x + ((i * 11) + fmod(500, 11)))
                    break;
                actuel = actuel->suivant;
                c++;
        }
        while (actuel->nbr != (*head_ref)->nbr)
        {
            if (c <= size / 2)
                ft_ra(head_ref);
            else
                ft_rra(head_ref);
        }
        if((*head_ref)->nbr >= x + (i * 10) && (*head_ref)->nbr < x + ((i * 11) + fmod(500, 11)))
            ft_pb(head_ref, head_ref_b);
        size--;
        j++;
        actuel = *head_ref;
        c = 0;
    }
    return (0);
}