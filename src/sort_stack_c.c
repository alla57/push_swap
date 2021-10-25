/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 16:43:09 by user42            #+#    #+#             */
/*   Updated: 2021/10/25 17:35:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	insertion_sort(int *arr, int n)
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
