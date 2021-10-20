/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:23:55 by alla              #+#    #+#             */
/*   Updated: 2021/10/20 12:46:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

int		is_valid_args(int argc, char **argv);
int		is_number(char *num);
int		is_duplicates_num(char **argv);
int		atoi_moded(const char *str);
int		is_over_intmax(const char *str);
int		print_error(int code_err);
void	refresh_index(t_stack *head);
void	add_node_front(t_stack *head, t_stack *new);
void	add_node_back(t_stack *head, t_stack *new);
t_stack	*create_new_node(int value, int index);
void	create_stack_a(char **argv, t_stack **head);
void	reverse_rotate(t_stack *head);
void	rotate(t_stack *head);
void	push(t_stack *head_src, t_stack *head_dest);
void	swap(t_stack *head);
int		is_in_order(t_stack *head);
void	print_stack(t_stack *head);
void	algo_three_values(t_stack *head);
int		len_stack(t_stack *head);
void	changes_on_dest(t_stack **first_src, t_stack *head_dest);
void	changes_on_src(t_stack *head_src);
void	refresh_index(t_stack *head);
int		index_of_smallest(t_stack *head);
void	push_smallest_in_b(t_stack *head_a, t_stack *head_b);
void	algo_ten_or_less_values(t_stack *head_a, t_stack *head_b);




#endif