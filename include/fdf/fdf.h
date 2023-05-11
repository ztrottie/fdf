/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 12:18:01 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/11 14:19:35 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define HEIGHT 720
# define WIDTH 1280
# include "../../lib/libft/libft.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>

typedef struct s_map
{
	char			**line;
	struct s_map	*next;
}	t_map;

typedef struct s_lines
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
}	t_lines;

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	yi;
	int	xi;
	int	p;
	int	x;
	int	y;
}	t_draw;

typedef struct s_coords
{
	int	x;
	int	y;
	int	z;
}	t_coords;

typedef struct s_fdf
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	char				*file;
	struct s_map		*map;
	struct s_coords		*coords;
	struct s_coords		*points;
	int					x_mod;
	int					y_mod;
	int					total_coord;
	int					map_height;
	int					map_width;
}	t_fdf;

int		args_error(int argc, char **argv);
int		open_map(t_fdf *var);
void	ft_exit(char *error, t_fdf *var, int type);
void	set_backgroud(t_fdf *var);
char	**split_get_next_line(int fd, char split);
size_t	ft_strlen_double(char **str);
void	parse_map(t_fdf	*var);
void	init_coords(t_fdf *var, int scale);
void	add_line_end(t_fdf *var, char **line);
void	convert_map(t_fdf *var);
void	print_points(t_fdf *var);
void	print_lines(t_fdf *var);
void	brensen_algo(t_fdf *var, t_lines line_points);
t_draw	p_calculus_low(t_draw draw);
t_draw	p_calculus_high(t_draw draw);
void	free_all(t_fdf *var);

#endif