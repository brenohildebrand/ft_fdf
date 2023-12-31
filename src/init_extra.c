/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 15:15:11 by bhildebr          #+#    #+#             */
/*   Updated: 2023/11/11 10:54:16 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../kit/actions/actions.h"

void	init_extra(t_extra *extra)
{
	(*extra) = smalloc(sizeof(struct s_extra));
	(*extra)->max_z = (1 << 31);
	(*extra)->min_z = ~(1 << 31);
}
