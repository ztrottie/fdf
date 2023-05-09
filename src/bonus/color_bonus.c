/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:46:50 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/03 14:03:56 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

static int	convert_hexa(int c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (0);
}

int	convert_color(char *str)
{
	int	i;
	int	nb;
	int	len;

	i = -1;
	nb = 0;
	while (str[++i])
		str[i] = ft_toupper(str[i]);
	len = ft_strlen(str);
	while (len >= 0)
	{
		nb += convert_hexa(str[i - len]) * pow(16, len);
		len--;
	}
	return (nb);
}
