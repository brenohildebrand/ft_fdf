/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_z.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 13:17:31 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/08 16:18:30 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	compute_max_z(t_fdf fdf)
{
	t_i32	i;

	i = 0;
	while (i < fdf->map->position->size)
	{
		if (fdf->map->position->data[i].z > fdf->extra->max_z)
			fdf->extra->max_z = fdf->map->position->data[i].z;
		i++;
	}
}

static void	compute_min_z(t_fdf fdf)
{
	t_i32	i;

	i = 0;
	while (i < fdf->map->position->size)
	{
		if (fdf->map->position->data[i].z < fdf->extra->min_z)
			fdf->extra->min_z = fdf->map->position->data[i].z;
		i++;
	}
}

void	normalize_z(t_fdf fdf, t_point p)
{
	if (fdf->extra->max_z == (1 << 31))
		compute_max_z(fdf);
	if (fdf->extra->min_z == ~(1 << 31))
		compute_min_z(fdf);
	if (fdf->extra->max_z == fdf->extra->min_z)
		p->position.z = 0;
	else
		p->position.z = (1080.0 / 3.0) * (t_f64)(p->position.z - fdf->extra->min_z) * (1.0 / (t_f64)(fdf->extra->max_z - fdf->extra->min_z));
}
