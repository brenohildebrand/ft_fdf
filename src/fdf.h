/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:34:53 by brenohildeb       #+#    #+#             */
/*   Updated: 2023/10/25 11:44:27 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_vec3 {
	int	x;
	int	y;
	int	z;
}	t_vec3;

typedef struct s_llist {
	t_vec3			point;
	struct s_llist	*next;
}	t_llist;

void	validate_args(int argc, char *argv[]);
void	validate_argc(int argc);
void	validate_argv(char *argv[]);

void	read_the_file(char **file, char *path);
void	open_the_file(int *fd, char *path);
void	read_the_file_till_the_end(int *fd, char **file);
void	close_the_file(int *fd);

void	parse_the_file(t_llist **map, char *file);
void	parse_number(t_llist **map, char **file, int *x, int *y);
void	parse_space_or_newline(char **file, int *x, int *y, int line_size);
void	store_number_in_map(t_llist **map, int x, int y, int z);

#endif
