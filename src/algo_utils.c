/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:59:54 by user42            #+#    #+#             */
/*   Updated: 2021/10/19 14:01:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
