/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:23:55 by alla              #+#    #+#             */
/*   Updated: 2021/10/17 22:16:17 by user42           ###   ########.fr       */
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
	struct s_stack	*next;
	struct s_stack	*prev;
}t_stack;

int		is_valid_args(int argc, char **argv);
int		is_number(char *num);
int		is_duplicates_num(char **argv);
int		atoi_moded(const char *str);
int		is_over_intmax(const char *str);
int		print_error(int code_err);
void	add_node_front(t_stack *head, t_stack *new);
void	add_node_back(t_stack *head, t_stack *new);
t_stack	*create_new_node(int value);
void	create_stack_a(char **argv, t_stack **head);
void	reverse_rotate(t_stack *head);
void	rotate(t_stack *head);
void	push(t_stack *head_src, t_stack *head_dest);
void	swap(t_stack *head);
int		is_in_order(t_stack *head);
void	print_stack(t_stack *head);
void	algo_three_values(t_stack *head);




#endif