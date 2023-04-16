/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaraban <akaraban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:39:45 by akaraban          #+#    #+#             */
/*   Updated: 2023/04/15 23:12:00 by akaraban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include<stdlib.h>
# include<unistd.h>
# include<stddef.h>
# include<stdio.h>	//testing

typedef struct linked_list
{
	int					value;
	int					index;
	struct linked_list	*next;
}	t_stack;

// algorithm.c
void	sort3(t_stack **top, void (*rot)(t_stack**, t_stack**),
			t_stack **other, void (*revrot)(t_stack**, t_stack**));
int		rot_dir3(t_stack **stack);
void	sort_3elem(t_stack **stack_a, t_stack **stack_b, int aorb);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size);

//  algorithm2.c
void	presort_nelem(t_stack **stack_a, t_stack **stack_b, int length);
void	elem_tosort(int min, int max, t_stack **stack_a, t_stack **stack_b);
int		movetop_cost(t_stack *trav, t_stack **stack);
int		cost_r(t_stack *elem, t_stack **stack);
int		cost_rr(t_stack *trav);

// algorithm3.c
int		is_min_elem(t_stack *elem, t_stack **stack);
int		get_cost(t_stack **stack_a, t_stack **stack_b,
			t_stack *elem, t_stack *targ);
t_stack	*get_targ_elem(t_stack *elem, t_stack **stack);
t_stack	*lcost_elem(t_stack **stack_a, t_stack **stack_b);
void	put_back(t_stack **stack_a, t_stack **stack_b, int size_b);

// algorithm4.c
void	final_operation(t_stack *elem, t_stack **stack_a, t_stack **stack_b);
void	do_individual_operation(t_stack *elem, t_stack **stack_a,
			t_stack *targ, t_stack **stack_b);
void	do_simultaneous_operation(t_stack *elem, t_stack **stack_a,
			t_stack **stack_b, void (*opn)(t_stack **, t_stack **));
void	send_elem_back(t_stack *elem, t_stack **stack_a, t_stack **stack_b);

// algorithm5.c
int		which_stack(t_stack *elem, t_stack **stack_a, t_stack **stack_b);
int		get_rot_opn(t_stack *elem, t_stack **stack);
void	apply_move(t_stack **stack_a, t_stack **stack_b,
			t_stack *elem, void (*opn)(t_stack **, t_stack **));
void	apply_push(t_stack *elem, t_stack **stack_a, t_stack **stack_b);
void	move_elem(t_stack *elem, t_stack **stack_a, t_stack **stack_b);

// combined_opns.c
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// error_check.c
void	display_error(void);
int		error_check(int count, char **strs);
// + 3 static functions

//indices.c
void	initialize_indices(t_stack **st);
void	assign_indices(int size, t_stack **stack);

//input_processing.c
void	argtostack(int count, char **args, t_stack **stack_a);

// push_swap_opns.c 
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	st_swap(t_stack **stack);
void	sa(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_a, t_stack **stack_b);

//rotate_opns.c
void	rotate(t_stack **stack, int reverse);
void	ra(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_a, t_stack **stack_b);

//stack_utilities.c 
t_stack	*ft_create_elem(int data);
void	ft_list_push_front(t_stack **begin_list, int data);
void	apply_operation(t_stack **stack_a, t_stack **stack_b,
			void (*st_opn)(t_stack**, t_stack**));
t_stack	*get_min(t_stack **stack);
int		is_min(t_stack **elem, t_stack **stack);

//stack_utilities.c
int		is_sorted(t_stack **stack);
void	free_stack(t_stack **stack);

// utilities.c
int		ft_isdigit(int c);
long	ft_atoi(char *nptr);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_strcmp(char *s1, char *s2);

//utilities2.c
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_maxima(int x, int y);
int		ft_minima(int x, int y);

#endif
