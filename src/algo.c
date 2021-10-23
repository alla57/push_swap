/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 22:15:36 by user42            #+#    #+#             */
/*   Updated: 2021/10/21 21:44:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void insertion_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < n)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		++i;
	}
}

int	*sort_stack(t_stack *head_a)
{
	t_stack	*tmp;
	int		*arr;
	int		i;
	int		n;

	i = 0;
	tmp = head_a->next;
	arr = malloc(sizeof(int) * len_stack(head_a));
	while (i < len_stack(head_a))
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	n = len_stack(head_a);
	insertion_sort(arr, n);
	return (arr);
}

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

void	push_smaller_than(int key_nbr, t_stack *head_a, t_stack *head_b)
{
	while (there_is_smaller_than(key_nbr, head_a))
	{
		if (head_a->next->value <= key_nbr)
			push(head_a, head_b);
		else
			rotate(head_a);
	}
	if (head_a->next->value <= key_nbr)
		push(head_a, head_b);
}

void	algo_five_hundred(t_stack *head_a, t_stack *head_b)
{
	int *stack_c;
	int	key_nbr;
	int	i;

	stack_c = sort_stack(head_a);
	i = len_stack(head_a) / 8;
	key_nbr = stack_c[i];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 2];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 3];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 4];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 5];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 6];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 7];
	push_smaller_than(key_nbr, head_a, head_b);
	while (head_a->prev != head_a->next)
		push_smallest_in_b(head_a, head_b);
	while (head_b->next)
		push_greatest_in_a(head_a, head_b);
	free(stack_c);
}

void	algo_hundred(t_stack *head_a, t_stack *head_b)
{
	int *stack_c;
	int	key_nbr;
	int	i;

	stack_c = sort_stack(head_a);
	i = len_stack(head_a) / 4;
	key_nbr = stack_c[i];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 2];
	push_smaller_than(key_nbr, head_a, head_b);
	key_nbr = stack_c[i * 3];
	push_smaller_than(key_nbr, head_a, head_b);
	while (head_a->prev != head_a->next)
		push_smallest_in_b(head_a, head_b);
	while (head_b->next)
		push_greatest_in_a(head_a, head_b);
	free(stack_c);
}

void	algo_ten_or_less_values(t_stack *head_a, t_stack *head_b)
{
	while (len_stack(head_a) > 3)
		push_smallest_in_b(head_a, head_b);
	algo_three_values(head_a);
	while (head_b->next)
	{
		push(head_b, head_a);
	}
}

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
