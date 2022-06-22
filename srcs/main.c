/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:04 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/22 23:05:07 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run_cmd_in(t_data data)
{
	int	cpid;
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.fd1, 0);
		dup2(data.pfd[0][1], 1);
		close(data.pfd[0][0]);
		close(data.pfd[1][1]);
		close(data.pfd[1][0]);
		execve(data.cmd_array[0].path, data.cmd_array[0].av, 0);
	}
}

void	run_cmd_i(t_data data, int i)
{
	int	cpid; 
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.pfd[i][0], 0);
		close(data.pfd[i][1]);
		dup2(data.pfd[i + 1][1], 1);
		close(data.pfd[i + 1][0]);
		execve(data.cmd_array[i + 1].path, data.cmd_array[i + 1].av, 0);
	}
}

void	run_cmd_out(t_data data, int i)
{
	int	cpid;
	
	cpid = fork();
	if (cpid == 0)
	{
		dup2(data.pfd[i][0], 0);
		close(data.pfd[i][1]);
		dup2(data.fd2, 1);
		close(data.pfd[0][1]);
		close(data.pfd[0][0]);
		execve(data.cmd_array[i + 1].path, data.cmd_array[i + 1].av, 0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	
	if (ac < 5)
		return (0);
	
	data.cmd_nbr = ac - 3;
	data.cmd_array = (t_cmd *)malloc(sizeof(t_cmd) * data.cmd_nbr);
	data.fd1 = open (av[1], 0);
	data.fd2 = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 00777);
	data.pfd = (int **)malloc(sizeof(int *) * data.cmd_nbr - 1);
	i = 0;
	while (i < data.cmd_nbr)
	{
		data.cmd_array[i].av = ft_split(av[i + 2], ' ');
		data.cmd_array[i].path = get_path(data.cmd_array[i].av[0]);
		free(data.cmd_array[i].av[0]);
		data.cmd_array[i].av[0] = data.cmd_array[i].path;
		if (i != data.cmd_nbr - 1)
		{
			data.pfd[i] = (int *)malloc(sizeof(int) * 2);
			pipe(data.pfd[i]);
		}
		i++;
	}
	run_cmd_in(data);
	i = 0;
	while (i < data.cmd_nbr - 2)
	{
		run_cmd_i(data, i);
		i++;
	}
	run_cmd_out(data, i);
	wait(0);
	i = 0;
	while (i < data.cmd_nbr)
	{
		free_array(data.cmd_array[i].av);
		if (i != data.cmd_nbr - 1)
		{
			close(data.pfd[i][0]);
			close(data.pfd[i][1]);
			free(data.pfd[i]);
		}
		i++;	
	}
	free(data.pfd);
	free(data.cmd_array);
	close(data.fd1);
	close(data.fd2);
	exit (0);
}
