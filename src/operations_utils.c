/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:58:16 by user42            #+#    #+#             */
/*   Updated: 2021/10/20 13:00:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	refresh_index(t_stack *head)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	if (!head->next)
		return ;
	tmp = head->next;
	while (tmp != head->prev)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
	tmp->index = i;
}

void	changes_on_src(t_stack *head_src)
{
	t_stack	*first_src;
	t_stack	*second_src;
	t_stack	*last_src;

	first_src = head_src->next;
	second_src = first_src->next;
	last_src = head_src->prev;
	if (len_stack(head_src) == 1)
	{
		head_src->next = NULL;
		head_src->prev = NULL;
	}
	else if (len_stack(head_src) > 1)
	{
		head_src->next = second_src;
		second_src->prev = head_src->prev;
		last_src->next = second_src;
	}
}

void	changes_on_dest(t_stack **first_src, t_stack *head_dest)
{
	t_stack	*first_dest;
	t_stack	*last_dest;

	first_dest = head_dest->next;
	last_dest = head_dest->prev;
	if (len_stack(head_dest) == 0)
	{
		head_dest->next = (*first_src);
		head_dest->prev = (*first_src);
		(*first_src)->next = (*first_src);
		(*first_src)->prev = (*first_src);
	}
	else if (len_stack(head_dest) > 0)
	{
		head_dest->next = (*first_src);
		(*first_src)->next = first_dest;
		(*first_src)->prev = head_dest->prev;
		first_dest->prev = (*first_src);
		last_dest->next = (*first_src);
	}
}
