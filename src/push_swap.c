/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:22:51 by alla              #+#    #+#             */
/*   Updated: 2021/10/15 21:09:54 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_error(int code_err)
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

int	main(int argc, char **argv)
{
	if (!is_valid_args(argc, argv + 1))
		return (0);
	printf("gg\n");
	return (0);
}
