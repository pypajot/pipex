/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:04 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/24 19:45:35 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (0);
	if (ft_strcmp(av[1], "here_doc"))
		data.hd = 0;
	else
	{
		data.hd = 1;
		data.lim = av[2];
	}
	init_data(&data, ac, av, envp);
	run_all_cmd(data);
	close_all_fd(data);
	free_data(data);
	exit (0);
}
