/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:04 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/22 20:48:43 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run_cmd_in(int pfd[], int fd1, char *str1, char *new_av[])
{
	int	cpid = fork();

	if (cpid == 0)
	{
		close(pfd[0]);
		dup2(pfd[1], 1);
		dup2(fd1, 0);
		execve(str1, new_av, 0);	
	}
	
}

void	run_cmd_out(int pfd[], int fd2, char *str2, char *new_av2[])
{
	int	cpid = fork();
	
	if (cpid == 0)
	{
		close(pfd[1]);
		dup2(pfd[0], 0);
		dup2(fd2, 1);
		execve(str2, new_av2, 0);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		i;
	
	if (ac < 5)
		return (0);
	
	data.cmd_nbr = ac - 3;
	data.cmd_array = malloc(sizeof(t_cmd) * data.cmd_nbr);
	i = 0;
	while (i < data.cmd_nbr)
	{
		data.cmd_array[i].av = ft_split(av[i + 2], ' ');
		data.cmd_array[i].path = get_path(data.cmd_array[i].av[0]);
		data.cmd_array[i].av[0] = data.cmd_array[i].path;
	}
	data.fd1 = open (av[1], 0);
	data.fd2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 00777);
	data.pfd = (int *)malloc(sizeof(int[2]) * data.cmd_nbr - 1);
	
	pipe(pfd);
	run_cmd1(pfd, fd1, str1, new_av);
	run_cmd2(pfd, fd2, str2, new_av2);
	close (pfd[0]);
	close(pfd[1]);
	close(fd1);
	close(fd2);
	exit (0);
}