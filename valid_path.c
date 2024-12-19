/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thilefeb <thilefeb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 10:15:00 by thilefeb          #+#    #+#             */
/*   Updated: 2024/05/02 01:56:37 by thilefeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_reach_exit(struct s_mlx_var *s_mlx_var)
{
	find_car(s_mlx_var, 'P', 1);
	if (!car_around_coordinates(s_mlx_var, '0') \
		&& !car_around_coordinates(s_mlx_var, 'C'))
		return (0);
	replace_car_around_coordinates(s_mlx_var);
	while (should_we_continue(s_mlx_var))
		replace_zero_and_c_by_x_if_around_x(s_mlx_var);
	find_car(s_mlx_var, 'E', 1);
	if (!car_around_coordinates(s_mlx_var, 'X') \
		|| (check_at_least_one_car(s_mlx_var, 'C') >= 1))
		return (0);
	return (1);
}
