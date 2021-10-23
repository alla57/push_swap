/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:22:51 by alla              #+#    #+#             */
/*   Updated: 2021/10/21 20:42:19 by user42           ###   ########.fr       */
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
	t_stack *head_a;
	t_stack	*head_b;

	if (!is_valid_args(argc, argv + 1))
		return (0);
	create_stack_a(argv, &head_a);
	if (is_in_order(head_a))
		return (printf("deja in order\n"));
	if (argc == 3)
		swap(head_a);
	else if (argc == 4)
		algo_three_values(head_a);
	else if (argc <= 11)
	{
		head_b = create_new_node(0, 0);
		algo_ten_or_less_values(head_a, head_b);
	}
	else if (argc <= 101)
	{
		head_b = create_new_node(0, 0);
		algo_hundred(head_a, head_b);
	}
	else
	{
		head_b = create_new_node(0, 0);
		algo_five_hundred(head_a, head_b);
	}
	//printf("%d\n", argc);
	// printf("is the stack in order ? %d\n", is_in_order(head_a));
	//print_stack(head_a);
	//printf("gg\n");
	return (0);
}
