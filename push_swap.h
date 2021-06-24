/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbensarg <sbensarg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 23:39:01 by chicky            #+#    #+#             */
/*   Updated: 2021/06/18 15:22:50 by sbensarg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <unistd.h>

typedef struct s_pile {
	int				nbr;
	struct s_pile	*suivant;
}				t_pile;

typedef struct s_data {
	int	top;
	int	bottom;
	int	pos1;
	int	pos2;
	int	start;
	int	end;
	int	size;
	int	interval;
	int	check;
}			t_data;

int		ft_atoi(const char *str, int *check);
int		empiler(t_pile **head_ref, char **argv);
void	print_pile(t_pile *pile);
void	ft_sa(t_pile **head_ref, int flag);
void	ft_sb(t_pile **head_ref_b, int flag);
void	ft_ra(t_pile **head_ref, int flag);
void	ft_rb(t_pile **head_ref_b, int flag);
void	ft_rr(t_pile **head_ref, t_pile **head_ref_b, int flag);
void	ft_rra(t_pile **head_ref, int flag);
void	ft_rrb(t_pile **head_ref_b, int flag);
void	ft_rrr(t_pile **head_ref, t_pile **head_ref_b, int flag);
void	ft_pb(t_pile **head_ref_a, t_pile **head_ref_b, int flag);
void	ft_pa(t_pile **head_ref_b, t_pile **head_ref_a, int flag);
void	ft_ss(t_pile **head_ref, t_pile **head_ref_b, int flag);
int		ft_check(int n, t_pile *actuel, int *check);
void	ft_sort_3(t_pile **head_ref);
int		ft_find_smallest_nbr(t_pile **head_ref);
void	ft_sort_5(t_pile **head_ref, t_pile **head_ref_b);
void	rec_pa(t_pile **head_ref, t_pile **head_ref_b);
int		ft_size(t_pile *actuel);
void	ft_sort_100_global(t_pile **head_ref, t_pile **head_ref_b);
int		ft_find_end_of_interval(t_pile **head_ref, int i, int size);
int		reverse_scan(t_pile *head, int start, int end, int *pos);
int		scan(t_pile *head, int start, int end, int *pos);
int		pos_biggest_nbr(t_pile **head_ref, int nbr);
int		ft_find_biggest_nbr(t_pile **head_ref, int s);
void	ft_sort_500_inter(t_pile **head_ref, t_pile **head_ref_b, int interval);
void	ft_sort_500_global(t_pile **head_ref, t_pile **head_ref_b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	freelist(t_pile *head_ref);
#endif