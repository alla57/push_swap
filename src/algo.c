/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:15:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/17 22:16:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
