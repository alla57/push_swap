/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:21:14 by alla              #+#    #+#             */
/*   Updated: 2021/10/28 22:02:43 by user42           ###   ########.fr       */
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

t_stack	*create_new_node(int value, int index)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack *));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	create_stack_str(char *str, int index, t_stack **head)
{
	int		i;
	char	**nums;
	t_stack	*new;

	i = 0;
	nums = ft_split(str, ' ');
	while (nums[i])
	{
		new = create_new_node(atoi_moded(nums[i++]), index++);
		if (index == 1)
		{
			(*head)->next = new;
			(*head)->prev = new;
		}
		add_node_back(*head, new);
	}
	ft_free_double((void **)nums);
	return (index);
}

void	create_stack_a(char **argv, t_stack **head)
{
	int		i;
	int		index;
	t_stack	*new;

	i = 1;
	index = 0;
	*head = create_new_node(0, 0);
	while (argv[i])
	{
		if (!is_number(argv[i]))
			index = create_stack_str(argv[i++], index, head);
		else
		{
			new = create_new_node(atoi_moded(argv[i++]), index++);
			if (index == 1)
			{
				(*head)->next = new;
				(*head)->prev = new;
			}
			add_node_back(*head, new);
		}
	}
}
