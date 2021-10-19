/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:17:46 by alla              #+#    #+#             */
/*   Updated: 2021/10/19 13:59:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack *head)
{
	t_stack	*last;
	t_stack	*before_last;

	if (len_stack(head) < 2)
		return ;
	last = head->prev;
	before_last = last->next;
	head->next = last;
	head->prev = before_last;
	refresh_index(head);
}

void	rotate(t_stack *head)
{
	t_stack	*first;
	t_stack	*second;

	if (len_stack(head) < 2)
		return ;
	first = head->next;
	second = first->next;
	head->next = second;
	head->prev = first;
	refresh_index(head);
}

void	push(t_stack *head_src, t_stack *head_dest)
{
	if (len_stack(head_src) == 0)
		return ;
	changes_on_src(head_src);
	changes_on_dest(head_src, head_dest);
	refresh_index(head_src);
	refresh_index(head_dest);
}

void	swap(t_stack *head)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (len_stack(head) < 2)
		return ;
	first = head->next;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}
