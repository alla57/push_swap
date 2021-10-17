/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 21:16:23 by user42            #+#    #+#             */
/*   Updated: 2021/10/17 21:16:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack	*stack_a;

	stack_a = head->next;
	while (stack_a != head->prev)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("%d\n", stack_a->value);
}

int is_in_order(t_stack *head)
{
	t_stack	*stack_a;

	stack_a = head->next;
	while(stack_a != head->prev)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
