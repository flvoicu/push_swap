/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flvoicu <flvoicu@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:11:01 by flvoicu           #+#    #+#             */
/*   Updated: 2024/04/17 17:41:42 by flvoicu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				moves;
	int				up;
	int				off;
	int				st;
	int				check;
	struct s_stack	*next;
	struct s_stack	*top;
}					t_stack;
void	print_s(char *a);
int		ft_strlen(char *s);
t_stack	*ft_st_last(t_stack *st);
t_stack	*ft_stnew(int i);
int		main(int ac, char **av);
void	create_stack(t_stack **a, int cnt, char **av);
void	set_index(t_stack **one);
void	move(t_stack **a, t_stack **b, t_stack *n);
t_stack	*get_node(t_stack **a);
void	set_off(t_stack **a, t_stack **b, int n);
void	check_node(t_stack **node, t_stack *a);
void	set_moves(t_stack **a);
int		get_length(t_stack *a);
void	set_top(t_stack **a, t_stack **b);
t_stack	*ft_get_smallest(t_stack **a);
t_stack	*ft_get_biggest(t_stack **a);
char	**ft_split(char const *s, char c);
int		ft_atoi(char *str);
void	error_exit(char *s);
int		check(t_stack *a, t_stack *b);
void	arrange_three_min(t_stack **a);
void	arrange_three_max(t_stack **a);
void	free_stack(t_stack **a);

void	sa(t_stack **a, int pt);
void	pa(t_stack **a, t_stack **b, int pt);
void	ra(t_stack **a, int pt);
void	rra(t_stack **a, int pt);

void	sb(t_stack **a, int pt);
void	pb(t_stack **a, t_stack **b, int pt);
void	rb(t_stack **a, int pt);
void	rrb(t_stack **a, int pt);

void	ss(t_stack **a, t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	push(t_stack **a, t_stack **b, int st);
void	nor_rot(t_stack **a, t_stack **b, int st);
void	rev_rot(t_stack **a, t_stack **b, int st);
void	rotate(t_stack **a, t_stack **b, t_stack *n);
void	dou_rot(t_stack **a, t_stack **b, t_stack *n);

#endif
