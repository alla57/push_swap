/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:15:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 17:34:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_five_hundred(t_stack *head_a, t_stack *head_b)
{
	int	*stack_c;
	int	key_nbr;
	int	i;
	int	chunk;

	stack_c = sort_stack(head_a);
	i = len_stack(head_a) / 13;
	chunk = 1;
	while (chunk < 13)
	{
		key_nbr = stack_c[i * chunk++];
		push_smaller_than(key_nbr, head_a, head_b);
	}
	while (head_a->prev != head_a->next)
		push_smallest_in_b(head_a, head_b);
	while (head_b->next)
		push_greatest_in_a(head_a, head_b);
	free(stack_c);
}

void	algo_hundred(t_stack *head_a, t_stack *head_b)
{
	int	*stack_c;
	int	key_nbr;
	int	i;
	int	chunk;

	stack_c = sort_stack(head_a);
	i = len_stack(head_a) / 4;
	chunk = 1;
	while (chunk < 4)
	{
		key_nbr = stack_c[i * chunk++];
		push_smaller_than(key_nbr, head_a, head_b);
	}
	while (head_a->prev != head_a->next)
		push_smallest_in_b(head_a, head_b);
	while (head_b->next)
		push_greatest_in_a(head_a, head_b);
	free(stack_c);
}

void	algo_ten_or_less_values(t_stack *head_a, t_stack *head_b)
{
	while (len_stack(head_a) > 3)
		push_smallest_in_b(head_a, head_b);
	algo_three_values(head_a);
	while (head_b->next)
	{
		push(head_b, head_a, "pa\n");
	}
}

void	algo_three_values(t_stack *head)
{
	t_stack	*first;
	t_stack	*mid;
	t_stack	*last;

	first = head->next;
	last = head->prev;
	mid = first->next;
	if (last->value > first->value && first->value > mid->value)
		swap(head, "sa\n");
	else if (first->value > mid->value && mid->value > last->value)
	{
		swap(head, "sa\n");
		reverse_rotate(head, "rra\n");
	}
	else if (first->value > last->value && last->value > mid->value)
		rotate(head, "ra\n");
	else if (mid->value > last->value && last->value > first->value)
	{
		swap(head, "sa\n");
		rotate(head, "ra\n");
	}
	else if (mid->value > first->value && first->value > last->value)
		reverse_rotate(head, "rra\n");
}
