/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:45:49 by ztrottie          #+#    #+#             */
/*   Updated: 2023/04/30 09:46:10 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus/bonus.h"

/// @brief argv_error verify that the only arguments passed is correctly parse
/// so that its *.fdf
/// @param argv arguments value from main function
/// @return return 1 if an error is found or 0 if everything is good
static int	argv_error(char **argv)
{
	int		error;
	char	**tmp;
	char	*msg;

	tmp = ft_split(argv[1], '.');
	error = 0;
	if (ft_strncmp(tmp[1], "fdf\0", 4) != 0)
		error = 1;
	ft_x2free((void **)tmp);
	if (error == 1)
	{
		msg = ft_strjoin(argv[1], " : Invalid map should be *.fdf\n");
		ft_putstr_fd(msg, 2);
		ft_free(msg);
	}
	return (error);
}

/// @brief args_error function handle verify that there is no error in the
/// arguments passed
/// @param argc number of arguments
/// @param argv arguments value from main function
/// @return return 1 if and error is found or 0 if everything is good
int	args_error(int argc, char **argv)
{
	if (argc > 2)
		return (ft_putstr_fd("Too much arguments\n", 2), 1);
	if (argc < 2)
		return (ft_putstr_fd("Not enough arguments\n", 2), 1);
	if (argv_error(argv))
		return (1);
	return (0);
}
