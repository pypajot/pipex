/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:03:10 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 22:06:46 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac < 5)
		return (ft_error(NOT_ENOUGH_ARG, 0), 0);
	if (ft_strcmp(av[1], "here_doc"))
		data.hd = 0;
	else
	{
		if (ac < 6)
			return (ft_error(NOT_ENOUGH_ARG, 0), 0);
		data.hd = 1;
		data.lim = av[2];
	}
	if (!init_data(&data, ac, av))
		return (0);
	run_all_cmd(data, envp);
	close_all_fd(data);
	free_data(data);
	exit (0);
}
