/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_mediocre_list.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/21 19:22:20 by nschat        #+#    #+#                 */
/*   Updated: 2020/10/19 14:09:19 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf_mediocre.h"

t_pflist	*ft_pflstnew(t_data *data)
{
	t_pflist	*new;

	new = (t_pflist *)malloc(sizeof(t_pflist));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_pflist	*ft_pflstlast(t_pflist *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_pflstadd_back(t_pflist **alst, t_pflist *new)
{
	if (*alst)
		ft_pflstlast(*alst)->next = new;
	else
		*alst = new;
}

void	free_list(t_pflist **alst)
{
	t_pflist	*node;
	t_pflist	*next;

	node = *alst;
	while (node)
	{
		next = node->next;
		if (node->data->type == 't')
			free(node->data->arg.s);
		free(node->data);
		free(node);
		node = next;
	}
	*alst = NULL;
}
