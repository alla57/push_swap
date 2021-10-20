/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:15:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 12:57:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_ten_or_less_values(t_stack *head_a, t_stack *head_b)
{
	while (len_stack(head_a) > 3)
		push_smallest_in_b(head_a, head_b);
	algo_three_values(head_a);
	while (head_b->next)
	{
		push(head_b, head_a);
	}
}

void	algo_three_values(t_stack *head)
{
	t_stack	*first;
	t_stack	*mid;
	t_stack *last;

	first = head->next;
	last = head->prev;
	mid = first->next;
	if (last->value > first->value && first->value > mid->value)
		swap(head);
	else if (first->value > mid->value && mid->value > last->value)
	{
		swap(head);
		reverse_rotate(head);
	}
	else if (first->value > last->value && last->value > mid->value)
		rotate(head);
	else if (mid->value > last->value && last->value > first->value)
	{
		swap(head);
		rotate(head);
	}
	else if (mid->value > first->value && first->value > last->value)
		reverse_rotate(head);
}
