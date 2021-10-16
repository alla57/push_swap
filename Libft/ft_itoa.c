/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alla <alla@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:21:03 by alboumed          #+#    #+#             */
/*   Updated: 2021/10/16 14:38:16 by alla             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		temp;
	char	*s;

	i = 1;
	if (n < 0)
		i++;
	temp = n;
	while (temp)
	{
		temp /= 10;
		i++;
	}
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s[i] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
		s[0] = '-';
	while (--i >= 0 && n != 0)
	{
		s[i] = ((n >= 0) ? 1 : -1) * (n % 10) + '0';
		n = n / 10;
	}
	return (s);
}
