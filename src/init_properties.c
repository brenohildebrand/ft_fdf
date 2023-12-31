/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_properties.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:19:45 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/04 17:23:07 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	init_properties(t_properties *properties)
{
	(*properties) = smalloc(sizeof(struct s_properties));
	init_vec3(&((*properties)->location));
	init_vec3(&((*properties)->rotation));
	init_vec3(&((*properties)->scale));
}
