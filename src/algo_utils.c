/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:59:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/19 17:49:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_smallest_in_b(t_stack *head_a, t_stack *head_b)
{
	while (index_of_smallest(head_a) != 0)
	{
		if (index_of_smallest(head_a) > (len_stack(head_a) / 2))
			reverse_rotate(head_a);
		else
			rotate(head_a);
	}
	push(head_a, head_b);
}

int	index_of_smallest(t_stack *head)
{
	t_stack	*tmp;
	int		value;
	int		index;

	tmp = head->next;
	value = tmp->value;
	index = tmp->index;
	while (tmp != head->prev)
	{
		if (tmp->value < value)
		{
			value = tmp->value;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp->value < value)
		index = tmp->index;
	return (index);
}

int	len_stack(t_stack *head)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (!head->next)
		return (0);
	tmp = head->next;
	while (tmp != head->prev)
	{
		++i;
		tmp = tmp->next;
	}
	return (i);
}
