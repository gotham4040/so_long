/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:23:29 by thilefeb          #+#    #+#             */
/*   Updated: 2024/04/09 21:11:43 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_textures(struct s_mlx_var *s_mlx_var)
{
	s_mlx_var->grass_texture = mlx_load_png("assets/grass.png");
	s_mlx_var->player_texture = mlx_load_png("assets/slime.png");
	s_mlx_var->wall_texture = mlx_load_png("assets/wall.png");
	s_mlx_var->item_texture = mlx_load_png("assets/item.png");
	s_mlx_var->exit_texture = mlx_load_png("assets/exit.png");
}

void	create_images(struct s_mlx_var *s_mlx_var)
{
	s_mlx_var->grass_image \
	= mlx_texture_to_image(s_mlx_var->connection, s_mlx_var->grass_texture);
	s_mlx_var->player_image \
	= mlx_texture_to_image(s_mlx_var->connection, s_mlx_var->player_texture);
	s_mlx_var->wall_image \
	= mlx_texture_to_image(s_mlx_var->connection, s_mlx_var->wall_texture);
	s_mlx_var->item_image \
	= mlx_texture_to_image(s_mlx_var->connection, s_mlx_var->item_texture);
	s_mlx_var->exit_image \
	= mlx_texture_to_image(s_mlx_var->connection, s_mlx_var->exit_texture);
}

void	resize_window(struct s_mlx_var *s_mlx_var)
{
	s_mlx_var->window_width = s_mlx_var->num_cols * IMAGE_SIZE;
	s_mlx_var->window_height = s_mlx_var->num_rows * IMAGE_SIZE;
	mlx_set_window_size(s_mlx_var->connection, \
	s_mlx_var->window_width, s_mlx_var->window_height);
}

void	resize_images(struct s_mlx_var *s_mlx_var)
{
	mlx_resize_image(s_mlx_var->grass_image, \
	s_mlx_var->window_width, s_mlx_var->window_height);
	mlx_resize_image(s_mlx_var->wall_image, IMAGE_SIZE, IMAGE_SIZE);
	mlx_resize_image(s_mlx_var->player_image, IMAGE_SIZE, IMAGE_SIZE);
	mlx_resize_image(s_mlx_var->player_image, IMAGE_SIZE, IMAGE_SIZE);
	mlx_resize_image(s_mlx_var->item_image, IMAGE_SIZE, IMAGE_SIZE);
	mlx_resize_image(s_mlx_var->exit_image, IMAGE_SIZE, IMAGE_SIZE);
}
