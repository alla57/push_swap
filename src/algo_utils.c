/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:59:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 16:47:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_smaller_than(int key_nbr, t_stack *head_a, t_stack *head_b)
{
	while (there_is_smaller_than(key_nbr, head_a))
	{
		if (head_a->next->value <= key_nbr)
			push(head_a, head_b, "pb\n");
		else
			rotate(head_a, "ra\n");
	}
	if (head_a->next->value <= key_nbr)
		push(head_a, head_b, "pb\n");
}

void	push_greatest_in_a(t_stack *head_a, t_stack *head_b)
{
	while (index_of_greatest(head_b) != 0)
	{
		if (index_of_greatest(head_b) > (len_stack(head_b) / 2))
			reverse_rotate(head_b, "rrb\n");
		else
			rotate(head_b, "rb\n");
	}
	push(head_b, head_a, "pa\n");
}

void	push_smallest_in_b(t_stack *head_a, t_stack *head_b)
{
	while (index_of_smallest(head_a) != 0)
	{
		if (index_of_smallest(head_a) > (len_stack(head_a) / 2))
			reverse_rotate(head_a, "rra\n");
		else
			rotate(head_a, "ra\n");
	}
	push(head_a, head_b, "pb\n");
}
