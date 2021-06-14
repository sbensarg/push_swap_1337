#include "push_swap.h"

int ft_write(char *msg, int nb)
{
    write(1, msg, strlen(msg));
    write(1, "\n", 1);
    return (nb);
}
int ft_check_if_sorted(t_pile **head_ref)
{
	t_pile *cur;

	cur = *head_ref;

	while (cur != NULL && cur->suivant != NULL)
	{
		if ((cur->suivant)->nbr < cur->nbr)
			return (-1);
		cur = cur->suivant;
	}
	return (0);
}
int main(int argc, char **argv)
{
    t_pile *pile = NULL;
    t_pile *pile_b = NULL;
	char *line;
	line = NULL;
    int ret;
	int f;
	int ret2;

    if (argc >= 2)
    {
       if ((ret =  empiler(&pile, argv)) != 2)
       {
		   while(1)			
		   {
			   ret2 = get_next_line(0, &line);
			   if(ft_strncmp(line, "ra", 3) == 0)
			   {
				   ft_ra(&pile, 0);
			   }
			   else if (ft_strncmp(line, "rb", 3) == 0)
			   {
				   ft_rb(&pile_b, 0);
			   }
			   else if (ft_strncmp(line, "rra", 4) == 0)
			   {
				   ft_rra(&pile, 0);
			   }
			   else if (ft_strncmp(line, "rrb", 4) == 0)
			   {
				   ft_rrb(&pile_b, 0);
			   }
			   else if(ft_strncmp(line, "sa", 3) == 0)
			   {
				   ft_sa(&pile, 0);
			   }
			   else if (ft_strncmp(line, "pa", 3) == 0)
			   {
				   ft_pa(&pile_b, &pile, 0);
			   }
			   else if (ft_strncmp(line, "pb", 3) == 0)
			   {
				   ft_pb(&pile, &pile_b, 0);
			   }
			      else if (ft_strncmp(line, "sb", 3) == 0)
			   {
				   ft_sb(&pile_b, 0);
			   }
			      else if (ft_strncmp(line, "ss", 3) == 0)
			   {
				   ft_ss(&pile, &pile_b, 0);
			   }
			      else if (ft_strncmp(line, "rr", 3) == 0)
			   {
				   ft_rr(&pile, &pile_b, 0);
			   }
			      else if (ft_strncmp(line, "rrr", 3) == 0)
			   {
				   ft_rrr(&pile, &pile_b, 0);
			   }
			   else if (ret2 == 1 && strlen(line) == 0)
			   {
				   continue ;
			   }
			   else if (ret2 == 0 && strlen(line) == 0)
			   {
			   		break ;
			   }
			   else
			   {
            		printf("Error\n");
					return (0);
			   }
		   }
		   f = ft_check_if_sorted(&pile);
		   if (f == -1)
		   		return (ft_write("KO", 0));
			else 
				return (ft_write("OK", 0));
       }
	    else
		{
			printf("Error\n");
			return (0);
		}
    }
    return 0;
}