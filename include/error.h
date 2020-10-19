/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 00:28:42 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:16:59 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# include <stddef.h>

void	puterror(const char *file, size_t line, const char *message);

#endif
