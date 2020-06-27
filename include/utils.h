/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/26 16:24:21 by nschat        #+#    #+#                 */
/*   Updated: 2020/06/27 13:52:05 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int				pack_trgb(int t, int r, int g, int b);
int				unpack_t(int trgb);
int				unpack_r(int trgb);
int				unpack_g(int trgb);
int				unpack_b(int trgb);

#endif
