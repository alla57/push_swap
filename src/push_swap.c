/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:22:51 by alla              #+#    #+#             */
/*   Updated: 2021/10/15 15:15:24 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int print_error(int code_err)
{
	if (code_err == 0)
		ft_putstr_fd("Error\nwrong number of arguments !", 2);
	else if (code_err == 1)
		ft_putstr_fd("Error\nbad arguments type !", 2);
	else if (code_err == 2)
		ft_putstr_fd("Error\nat least one argument is over intmax !", 2);
	else if (code_err == 3)
		ft_putstr_fd("Error\nthere are duplicates !", 2);
	return (0);
}

int		is_over_intmax(const char *str)
{
	int i;
	int nb;
	int tmp;

	i = 0;
	nb = 0;
	if (str[i] == '-')
		++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = nb;
		nb = nb * 10 + (str[i] - 48);
		if (tmp != ((nb - (str[i] - 48)) / 10))
			return (1);
		++i;
	}
	return (0);
}

int		atoi_moded(const char *str)
{
	int i;
	int nb;
	int sign;

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

int is_duplicates_num(char **argv)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (argv[j] && atoi_moded(argv[i]) != atoi_moded(argv[j]))
	{
		++j;
		if (!argv[j])
			j = ++i + 1;
	}
	if (argv[i + 1])
		return (1);
	return (0);
}

int is_number(char *num)
{
	int i;

	i = 0;
	if (num[0] == '-')
		++num;
	while (num[i] && ft_isdigit(num[i]))
		++i;
	if (i && !num[i])
		return (1);
	return (0);
}

int is_valid_args(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc < 3)
		return (print_error(0));
	while (argv[i] && is_number(argv[i]))
		++i;
	if (!i || argv[i])
		return (print_error(1));
	i = 0;
	while (argv[i])
	{
		if (is_over_intmax(argv[i++]))
			return (print_error(2));
	}
	if (is_duplicates_num(argv))
		return (print_error(3));
	return (1);
}

int main(int argc, char **argv)
{
	if (!is_valid_args(argc, argv + 1))
		return (0);
	printf("gg\n");
	return (0);
}