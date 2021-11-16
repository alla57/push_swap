/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:49:38 by user42            #+#    #+#             */
/*   Updated: 2021/11/16 18:12:28 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		++num;
	while (num[i] && ft_isdigit(num[i]))
		++i;
	if (i && !num[i])
		return (1);
	return (0);
}

int	is_over_intmax(const char *str)
{
	int		i;
	long	nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
		sign = ++i * -1;
	if (ft_strlen(str + i) > 10)
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		if (nb * sign > 2147483647 || nb * sign < -2147483648)
			return (1);
		++i;
	}
	return (0);
}

int	is_in_order(t_stack *head)
{
	t_stack	*stack_a;

	stack_a = head->next;
	while (stack_a != head->prev)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
