/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:21:14 by alla              #+#    #+#             */
/*   Updated: 2021/10/17 21:07:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	add_node_front(t_stack *head, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	first = head->next;
	last = head->prev;
	last->next = new;
	first->prev = new;
	new->prev = last;
	new->next = first;
}

void	add_node_back(t_stack *head, t_stack *new)
{
	t_stack	*first;
	t_stack	*last;

	first = head->next;
	last = head->prev;
	last->next = new;
	new->prev = last;
	new->next = first;
	first->prev = new;
	head->prev = new;
}

t_stack	*create_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack *));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = node;
	node->next = node;
	return (node);
}

void	create_stack_a(char **argv, t_stack **head)
{
	int	i;
	t_stack	*new;

	i = 1;
	*head = create_new_node(0);
	new = create_new_node(atoi_moded(argv[i++]));
	(*head)->next = new;
	(*head)->prev = new;
	while (argv[i])
	{
		new = create_new_node(atoi_moded(argv[i++]));
		add_node_back(*head, new);
	}
}
