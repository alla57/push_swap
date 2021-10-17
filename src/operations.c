/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:17:46 by alla              #+#    #+#             */
/*   Updated: 2021/10/17 16:18:17 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack *head)
{
	t_stack	*last;
	t_stack	*before_last;

	last = head->prev;
	before_last = last->next;
	head->next = last;
	head->prev = before_last;
}

void	rotate(t_stack *head)
{
	t_stack	*first;
	t_stack	*second;

	first = head->next;
	second = first->next;
	head->next = second;
	head->prev = first;
}

void	push(t_stack *head_src, t_stack *head_dest)
{
	t_stack	*first_src;
	t_stack	*second_src;
	t_stack	*first_dest;

	if (!head_src->next)
		return ;
	first_src = head_src->next;
	second_src = first_src->next;
	head_src->next = second_src;
	second_src->prev = head_src->prev;
	first_dest = head_dest->next;
	head_dest->next = first_src;
	first_src->prev = first_dest->prev;
	first_src->next = first_dest;
	first_dest->prev = first_src;
}

void	swap(t_stack *head)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	first = head->next;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}
