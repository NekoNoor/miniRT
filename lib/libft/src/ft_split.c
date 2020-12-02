/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 18:16:28 by nschat        #+#    #+#                 */
/*   Updated: 2019/11/26 13:00:08 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_arr_size(char const *s, char c)
{
	size_t size;

	size = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			size++;
		s++;
	}
	return (size);
}

static size_t	ft_split_size(char const *s, char c)
{
	char	*delim;

	delim = ft_strchr(s, c);
	if (delim == NULL)
		delim = (char *)s + ft_strlen(s);
	return (delim - s);
}

static void		ft_free_arr(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int		ft_split_str(char **arr, const char *s, char c)
{
	size_t	split_size;

	if (*s == '\0')
	{
		*arr = NULL;
		return (0);
	}
	if (*s == c)
		return (ft_split_str(arr, s + 1, c));
	split_size = ft_split_size(s, c);
	*arr = ft_substr(s, 0, split_size);
	if (*arr == NULL)
		return (1);
	return (ft_split_str(arr + 1, s + split_size, c));
}

char			**ft_split(char const *s, char c)
{
	char		**arr;
	size_t		size;

	if (s == NULL)
		return (NULL);
	size = ft_arr_size(s, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	if (ft_split_str(arr, s, c) == 1)
		ft_free_arr(arr);
	return (arr);
}
