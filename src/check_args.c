/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 20:48:21 by alla              #+#    #+#             */
/*   Updated: 2021/10/28 21:55:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	atoi_moded(const char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

int check_is_over_intmax(char **argv)
{
	int		i;
	char	**nums;
	int		j;

	i = -1;
	while (argv[++i])
	{
		if (!is_number(argv[i]))
		{
			nums = ft_split(argv[i], ' ');
			j = -1;
			while (nums[++j])
			{
				if (is_over_intmax(nums[j]))
				{
					ft_free_double((void **)nums);
					return (0);
				}
			}
			ft_free_double((void **)nums);
		}
		else if (is_over_intmax(argv[i]))
			return (0);
	}
	return (1);
}

int check_is_number(char **argv)
{
	int		i;
	char	**nums;
	int		j;

	i = -1;
	while (argv[++i])
	{
		if (!is_number(argv[i]))
		{
			nums = ft_split(argv[i], ' ');
			j = 0;
			while (nums[j] && is_number(nums[j]))
				++j;
			if (j == 0 || nums[j])
			{
				ft_free_double((void **)nums);
				return (0);
			}
			ft_free_double((void **)nums);
		}
	}
	if (i == 0)
		return (0);
	return (1);
}

int	is_valid_args(int argc, char **argv)
{
	if (argc < 2)
		return (print_error(0));
	if (check_is_number(argv) == 0)
		return (print_error(1));
	if (check_is_over_intmax(argv) == 0)
		return (print_error(2));
	return (1);
}
