/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <zakytrottier@hotmail.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:08:27 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/18 14:23:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/comparison.h"
#include "../../includes/conversion.h"
#include "../../includes/string.h"
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	ft_isint(char *str)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (ft_isdigit(str[i]) == 0)
			return(1);
		i++;
	}
	if (len > 11)
		return (1);
	if (len == 11 && ft_li_atoi(str) < INT_MIN)
		return (1);
	if (len == 10 && ft_li_atoi(str) > INT_MAX)
		return (1);
	return (0);
}