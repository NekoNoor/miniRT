/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:16:28 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/18 19:25:56 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	begin;
	size_t	end;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	if (s1[begin] == '\0')
		return (ft_strdup(""));
	end = ft_strlen(s1) - 1;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	len = end - begin + 1;
	trimmed = ft_substr(s1, begin, len);
	return (trimmed);
}
