/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:45:48 by chicky            #+#    #+#             */
/*   Updated: 2021/06/03 19:40:15 by sbensarg         ###   ########.fr       */
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

void rec_pa(t_pile **head_ref,t_pile **head_ref_b)
{
    while (*head_ref_b != NULL)
    {
      ft_pa(head_ref_b, head_ref);
      rec_pa(head_ref, head_ref_b);
    }
}
int ft_size(t_pile *actuel)
{
    int i;

    i = 0;
    if(actuel == NULL || actuel->suivant == NULL)
        return (0);
    while (actuel->suivant != NULL)
    {
        actuel = actuel->suivant;
        i++;
    }
    return (0);
}

// int ft_sort_100(t_pile **head_ref,t_pile **head_ref_b, int  argc)
// {
//     int smallest_value;
//     int pos;
    
//     pos = 0;
//     t_pile *actuel;

//     actuel = *head_ref;
//     int c = 0;
//     while (c != 5)
//     {
//         smallest_value = ft_find_smallest_nbr(head_ref, &pos);
//         while (actuel != NULL && actuel->nbr != smallest_value) 
//         {
//             ft_ra(head_ref);
//             actuel = *head_ref;
//         }
//         ft_pb(head_ref, head_ref_b);
//         c++;
//     }
    
//     return (0);
// }

// int ft_sort_100_b(t_pile **head_ref, int  argc)
// {
//     int smallest_value;
//     int pos;
    
//     pos = 0;
//     t_pile *actuel;
//     t_pile *tmp;

//     actuel = *head_ref;
//     int c = 0;
//     while (c != 5)
//     {
//         if(actuel != NULL)
//         {
//             smallest_value = ft_find_smallest_nbr(&actuel, &pos);
//         //    printf("small= |%d|\n",smallest_value);
//         //    printf("----------------\n");
//              while (actuel != NULL && actuel->nbr > actuel->suivant->nbr) 
//              {
//                 //tmp = actuel;
//                 // ft_rra(head_ref);
//                    actuel = *head_ref;
//              //   if((*head_ref)->nbr > ((*head_ref)->suivant)->nbr)
//                 ft_sa(head_ref);
//               //  printf("actual = |%d|\n",actuel->nbr);
//               //  break;
//               //  actuel = tmp;
//              }
//            //  break;
//           actuel = actuel->suivant;
//         }
//         c++;
//     }
    
//     return (0);
// }

int ft_sort_100(t_pile **head_ref,t_pile **head_ref_b, int  argc)
{
    int smallest_value;
    int pos;
    
    pos = 0;
    smallest_value = ft_find_smallest_nbr(head_ref, &pos);
    t_pile *actuel;

    actuel = *head_ref;
    while (actuel != NULL && actuel->nbr != smallest_value) 
    {
        if (pos <= argc / 2)
            ft_ra(head_ref);
        else
            ft_rra(head_ref);
    //  if((*head_ref)->nbr > ((*head_ref)->suivant)->nbr)
    //          ft_sa(head_ref);
        actuel = *head_ref;
    }
    ft_pb(head_ref, head_ref_b);
    argc--;
     while(*head_ref != NULL)
        ft_sort_100(head_ref, head_ref_b, argc);
    return (0);
}