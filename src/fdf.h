/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhildebr <bhildebr@student.42.sp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 03:34:53 by brenohildeb       #+#    #+#             */
/*   Updated: 2023/10/24 18:24:20 by bhildebr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

void	validate_args(int argc, char *argv[]);
void	validate_argc(int argc);
void	validate_argv(char *argv[]);

void	read_the_file(char **file, char *path);
void	open_the_file(int *fd, char *path);
void	read_the_file_till_the_end(int *fd, char **file);
void	close_the_file(int *fd);

#endif
