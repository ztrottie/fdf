/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ztrottie <ztrottie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:42:49 by ztrottie          #+#    #+#             */
/*   Updated: 2023/05/09 10:37:52 by ztrottie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# define HEIGHT 720
# define WIDTH 1280
# define WHITE_COLOR -1
# define BLACK_COLOR 255
# ifndef
#  define PARSE 0
# endif

# include "../../lib/libft/libft.h"
# include "../../lib/MLX42/include/MLX42/MLX42.h"
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>

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
	int	color;
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
	int	color;
}	t_coords;

typedef struct s_fdf
{
	mlx_t				*mlx;
	mlx_image_t			*hud[6];
	mlx_image_t			*img;
	char				*file;
	struct s_map		*map;
	struct s_coords		*coords;
	struct s_coords		*points;
	int					total_coord;
	int					map_height;
	int					map_width;
	int					speed;
	int					proj_selec;
	int					z_min;
	int					z_max;
	int					x_trans;
	int					y_trans;
	int					z_deg;
	int					x_deg;
	int					y_deg;
	float				scale;
}	t_fdf;


//Initialize
void		init_coords(t_fdf *var);

//Input error
int			args_error(int argc, char **argv);

//Maps
void		parse_map(t_fdf	*var);
void		convert_map(t_fdf *var);

//Hooks
void		my_scrollhook(double xdelta, double ydelta, void *param);
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		key_rotate_z(mlx_key_data_t keydata, t_fdf *var);
void		key_rotate_x(mlx_key_data_t keydata, t_fdf *var);
void		key_rotate_y(mlx_key_data_t keydata, t_fdf *var);
void		key_translate_up_down(mlx_key_data_t keydata, t_fdf *var);
void		key_translate_left_right(mlx_key_data_t keydata, t_fdf *var);

//Color
int			convert_color(char *str);

//Exit
void		ft_exit(char *error, t_fdf *var, int type);
void		free_all(t_fdf *var);

//Matrices
t_coords	matrice_calculus(t_coords coords, t_fdf *var);

//Backrgoud
void		set_backgroud(t_fdf *var);

//Points Drawing
void		print_points(t_fdf *var);

//Lines Drawing
t_draw		p_calculus_low(t_draw draw);
t_draw		p_calculus_high(t_draw draw);
void		print_lines(t_fdf *var);
void		x_lines(t_lines lines, t_fdf *var, int i);
void		y_lines(t_lines lines, t_fdf *var, int i);
void		draw_line(t_fdf *var, t_lines lines);

//Utils
char		**split_get_next_line(int fd, char split);
size_t		ft_strlen_double(char **str);

#endif