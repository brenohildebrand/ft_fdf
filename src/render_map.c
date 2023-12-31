/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 00:12:48 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/11 10:59:23 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../kit/actions/actions.h"
#include "fdf.h"
#include "MLX42/MLX42.h"
#include <stdio.h>

#define WIDTH (1920)
#define HEIGHT (1080)

static void	transform_and_draw(t_fdf fdf, t_u32 p0_index, t_u32 p1_index)
{
	struct s_point	p0;
	struct s_point	p1;

	p0.position = fdf->map->position->data[p0_index];
	p1.position = fdf->map->position->data[p1_index];
	p0.color = fdf->map->color->data[p0_index];
	p1.color = fdf->map->color->data[p1_index];
	// printf(
		// "p0 (%.2f, %.2f) and p1 (%.2f, %.2f)\n",
		// p0.position.x, p0.position.y,
		// p1.position.x, p1.position.y);
	normalize_z(fdf, &p0);
	normalize_z(fdf, &p1);
	scale(fdf, &p0);
	scale(fdf, &p1);
	move_to_origin(fdf, &p0);
	move_to_origin(fdf, &p1);
	rotate(fdf, &p0);
	rotate(fdf, &p1);
	move_back_from_origin(fdf, &p0);
	move_back_from_origin(fdf, &p1);
	centralize(fdf, &p0);
	centralize(fdf, &p1);
	bresenham(fdf->img, p0, p1);
}

static void	draw_wireframe(t_fdf fdf)
{
	t_u32	x;
	t_u32	y;

	y = 0;
	while (y < fdf->map->height)
	{
		x = 0;
		while (x < fdf->map->width)
		{
			if (x + 1 < fdf->map->width)
				transform_and_draw(
					fdf,
					x + y * fdf->map->width,
					x + 1 + y * fdf->map->width);
			if (y + 1 < fdf->map->height)
				transform_and_draw(
					fdf,
					x + y * fdf->map->width,
					x + (y + 1) * fdf->map->width);
			x++;
		}
		y++;
	}
}

void	loop(void *param)
{
	static struct s_vec3	rotation_speed = {.x = 30, .y = 30, .z = 30};
	t_fdf					fdf;

	fdf = (t_fdf)param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->properties->rotation->x += fdf->mlx->delta_time * rotation_speed.x;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->properties->rotation->x -= fdf->mlx->delta_time * rotation_speed.x;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->properties->rotation->y += fdf->mlx->delta_time * rotation_speed.y;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->properties->rotation->y -= fdf->mlx->delta_time * rotation_speed.y;
	draw_background(fdf->img);
	draw_wireframe(fdf);
}

void	render_map(t_fdf fdf)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	fdf->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!(fdf->mlx))
		sexit(1);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img || (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0))
		sexit(1);
	fdf->properties->rotation->z = 0;
	fdf->properties->rotation->x = 0;
	fdf->properties->rotation->y = 0;
	fdf->properties->scale->x = (1.0 / 3.0) * 1920.0 / (t_f64)(fdf->map->width - 1);
	fdf->properties->scale->y = (1.0 / 3.0) * 1080.0 / (t_f64)(fdf->map->height - 1);
	// fdf->properties->scale->x = 50;
	// fdf->properties->scale->y = 50;
	// fdf->properties->rotation->x = -57.4;
	mlx_loop_hook(fdf->mlx, loop, fdf);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
}
