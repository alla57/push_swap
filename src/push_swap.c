/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:22:51 by alla              #+#    #+#             */
/*   Updated: 2021/11/10 20:55:30 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_error(int code_err)
{
	if (code_err == 1)
		ft_putstr_fd("Error\n", 2);
	else if (code_err == 2)
		ft_putstr_fd("Error\n", 2);
	else if (code_err == 3)
		ft_putstr_fd("Error\n", 2);
	return (0);
}

void	free_stack(t_stack *head_a, t_stack *head_b)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = head_a->next;
	tmp2 = tmp->next;
	while (tmp2 != head_a->prev)
	{
		free(tmp);
		tmp = tmp2;
		tmp2 = tmp2->next;
	}
	free(tmp);
	if (tmp != tmp2)
		free(tmp2);
	free(head_a);
	free(head_b);
}

int	check_duplicates(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = head->next;
	tmp2 = tmp->next;
	while (tmp != head->prev)
	{
		while (tmp2 != head->next)
		{
			if (tmp->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	if (tmp != tmp2 && tmp->value == tmp2->value)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*head_a;
	t_stack	*head_b;

	if (!is_valid_args(argc, argv + 1))
		return (0);
	create_stack_a(argv, &head_a);
	head_b = create_new_node(0, 0);
	if (check_duplicates(head_a))
		print_error(3);
	else if (is_in_order(head_a))
		;
	else if (len_stack(head_a) == 2)
		swap(head_a, "sa\n");
	else if (len_stack(head_a) == 3)
		algo_three_values(head_a);
	else if (len_stack(head_a) <= 10)
		algo_ten_or_less_values(head_a, head_b);
	else if (len_stack(head_a) <= 100)
		algo_hundred(head_a, head_b);
	else
		algo_five_hundred(head_a, head_b);
	free_stack(head_a, head_b);
	return (0);
}
