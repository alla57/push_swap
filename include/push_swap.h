/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:23:55 by alla              #+#    #+#             */
/*   Updated: 2021/10/15 21:10:19 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

int	is_valid_args(int argc, char **argv);
int	is_number(char *num);
int	is_duplicates_num(char **argv);
int	atoi_moded(const char *str);
int	is_over_intmax(const char *str);
int	print_error(int code_err);

#endif