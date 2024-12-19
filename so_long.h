/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:05:26 by thilefeb          #+#    #+#             */
/*   Updated: 2024/05/01 17:44:15 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>

# include "ft_printf/ft_printf.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define ESCAPE 256
# define WINDOW_CLOSE_EVENT 17
# define IMAGE_SIZE 70

struct s_mlx_var
{
	void			*connection;
	int				coordinates[2];
	int				fd;
	int				num_cols;
	int				num_rows;
	int				window_height;
	int				window_width;
	char			buffer[2];
	char			*raw_content;
	char			**map_content;
	char			**map_content_copy;
	size_t			items_collected;
	size_t			number_of_moves;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*grass_texture;
	mlx_texture_t	*item_texture;
	mlx_texture_t	*exit_texture;
	mlx_image_t		*player_image;
	mlx_image_t		*wall_image;
	mlx_image_t		*grass_image;
	mlx_image_t		*item_image;
	mlx_image_t		*exit_image;
};

int		can_reach_exit(struct s_mlx_var *s_mlx_var);
int		check_at_least_one_car(struct s_mlx_var *s_mlx_var, char car);
int		rectangular_shape(struct s_mlx_var *s_mlx_var);
int		replace_zero_and_c_by_x_if_around_x(struct s_mlx_var *s_mlx_var);
int		should_we_continue(struct s_mlx_var *s_mlx_var);
int		car_around_coordinates(struct s_mlx_var *s_mlx_var, char car);
int		is_closed_by_walls(struct s_mlx_var *s_mlx_var);
int		no_foreign_car_in_map(struct s_mlx_var *s_mlx_var);
int		check_map_1(struct s_mlx_var *s_mlx_var);
int		check_map_2(struct s_mlx_var *s_mlx_var);
int		setup_window(struct s_mlx_var *s_mlx_var);
void	create_textures(struct s_mlx_var *s_mlx_var);
void	create_images(struct s_mlx_var *s_mlx_var);
void	resize_window(struct s_mlx_var *s_mlx_var);
void	resize_images(struct s_mlx_var *s_mlx_var);
void	key_detected(mlx_key_data_t keydata, void *p);
void	close_window(void *p);
void	find_car(struct s_mlx_var *s_mlx_var, char car, int num);
void	move_player(struct s_mlx_var *s_mlx_var, int dx, int dy);
void	replace_car_around_coordinates(struct s_mlx_var *s_mlx_var);

#endif
