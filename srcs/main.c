/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:04 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 22:06:40 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	if (ac != 5)
		return (ft_error(NOT_ENOUGH_ARG, 0), 0);
	data.hd = 0;
	if (!init_data(&data, ac, av))
		return (0);
	run_all_cmd(data, envp);
	close_all_fd(data);
	free_data(data);
	exit (0);
}
