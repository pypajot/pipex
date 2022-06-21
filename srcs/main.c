/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:04 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/21 19:31:19 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	run_cmd1(int pfd[], int fd1, char *str1, char *new_av[])
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

void	run_cmd2(int pfd[], int fd2, char *str2, char *new_av2[])
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
	if (ac != 5)
		return (0);
	char *new_av[] = {0, 0, 0};
	char *new_av2[] = {0, 0, 0};
	char *str1;
	char *str2;
	char **cmd1;
	char **cmd2;
	
	cmd1 = ft_split(av[2], ' ');
	cmd2 = ft_split(av[3], ' ');
	str1 = ft_strjoin("/bin/", cmd1[0]);
	str2 = ft_strjoin("/bin/", cmd2[0]);
	
	
	int	pfd[2];
	pipe(pfd);
	int	fd1;
	fd1 = open (av[1], 0);
	int fd2;
	fd2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 00777);
	new_av[0] = str1;
	new_av[1] = cmd1[1];
	new_av2[0] = str2;
	new_av2[1] = cmd2[1];
	run_cmd1(pfd, fd1, str1, new_av);
	run_cmd2(pfd, fd2, str2, new_av2);
	close (pfd[0]);
	close(pfd[1]);
	close(fd1);
	close(fd2);
	exit (0);
}