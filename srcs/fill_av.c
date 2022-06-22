/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_av.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:52:01 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/22 18:55:56 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex"

char	**fill_av(char *str, char **cmd)
{
	int		i;
	char	**new_av;

	i = 0;
	while (cmd[i])
		i++;
	new_av = (char **)malloc(sizeof(char *) * (i + 1));
	new_av[i] = 0;
	new_av[0] = str;
	i = 0;
	while (cmd[++i])
		new_av[i] = cmd[i];
	return (new_av);
}