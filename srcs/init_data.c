/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:48:19 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 21:32:34 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	alloc_data(t_data *data, char **av)
{
	int	i;

	i = -1;
	data->cmd_array = (t_cmd *)malloc(sizeof(t_cmd) * data->cmd_nbr);
	data->pfd = (int **)malloc(sizeof(int *) * (data->cmd_nbr - 1 + data->hd));
	while (++i < data->cmd_nbr)
	{
		data->cmd_array[i].av = ft_split(av[i + 2 + data->hd], ' ');
		data->cmd_array[i].path = get_path(data->cmd_array[i].av[0]);
		free(data->cmd_array[i].av[0]);
		data->cmd_array[i].av[0] = data->cmd_array[i].path;
		if (i != data->cmd_nbr - 1 + data->hd)
		{
			data->pfd[i] = (int *)malloc(sizeof(int) * 2);
			pipe(data->pfd[i]);
		}
	}
}

void	init_data(t_data *data, int ac, char **av)
{
	data->cmd_nbr = ac - (3 + data->hd);
	if (!data->hd)
	{
		data->fd1 = open (av[1], 0);
		if (data->fd1 < 0)
			ft_printf("%s: %s\n", strerror(errno), av[1]);
		data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
	}
	else
		data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 00777);
	alloc_data(data, av);
}
