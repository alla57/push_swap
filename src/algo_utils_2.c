/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:44:44 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 17:34:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	there_is_smaller_than(int key_nbr, t_stack *head)
{
	t_stack	*tmp;

	tmp = head->next;
	while (tmp != head->prev)
	{
		if (tmp->value <= key_nbr)
			return (1);
		tmp = tmp->next;
	}
	if (tmp->value <= key_nbr)
		return (1);
	return (0);
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

int	index_of_greatest(t_stack *head)
{
	t_stack	*tmp;
	int		value;
	int		index;

	tmp = head->next;
	value = tmp->value;
	index = tmp->index;
	while (tmp != head->prev)
	{
		if (tmp->value > value)
		{
			value = tmp->value;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	if (tmp->value > value)
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
