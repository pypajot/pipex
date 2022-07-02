/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:48:19 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 22:08:21 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	check_alloc(t_data data)
{
	int	i;

	i = 0;
	if (!data.cmd_arr || !data.pid)
		return (0);
	while (i < data.cmd_nbr)
	{
		if (!data.cmd_arr[i].av)
			return (0);
		i++;
	}
	return (1);
}

static void	alloc_data(t_data *data, char **av/*, char **envp*/)
{
	int	i;

	i = -1;
	data->cmd_arr = (t_cmd *)malloc(sizeof(t_cmd) * data->cmd_nbr);
	data->pid = (int *)malloc((data->cmd_nbr + data->hd) * sizeof(int));
	while (++i < data->cmd_nbr)
	{
		if (data->cmd_arr != 0)
		{
			data->cmd_arr[i].av = ft_split(av[i + 2 + data->hd], ' ');
			/*if (data->cmd_arr[i].av != 0)
			{
				data->cmd_arr[i].path = get_path(data->cmd_arr[i].av[0], envp);
				if (data->cmd_arr[i].path != 0)
				{
					free(data->cmd_arr[i].av[0]);
					data->cmd_arr[i].av[0] = data->cmd_arr[i].path;
				}
			}	*/	
		}
	}
}

int	init_data(t_data *data, int ac, char **av)
{
	data->cmd_nbr = ac - (3 + data->hd);
	if (!data->hd)
	{
		data->fd1 = open(av[1], 0);
		if (data->fd1 < 0)
			perror(av[1]);
		data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 00777);
	}
	else
		data->fd2 = open(av[ac - 1], O_WRONLY | O_CREAT | O_APPEND, 00777);
	if (data->fd2 < 0)
		perror(av[ac - 1]);
	alloc_data(data, av);
	if (!check_alloc(*data) || data->fd2 < 0)
	{
		close_all_fd(*data);
		free_data(*data);
		return (0);
	}
	data->pfd[0][0] = -1;
	data->pfd[0][1] = -1;
	data->pfd[1][0] = -1;
	data->pfd[1][1] = -1;
	return (1);
}
