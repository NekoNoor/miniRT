/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nschat <nschat@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/27 12:24:18 by nschat        #+#    #+#                 */
/*   Updated: 2020/05/27 12:32:24 by nschat        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		main(int ac, char **av)
{
	char	*filecontents;

	if (ac > 1)
		filecontents = read_file(av[1]);
	if (ac > 2 && ft_strcmp(av[2], "--save") == 0)
		
	parse(
	render_window();
}
