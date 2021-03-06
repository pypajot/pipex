/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:05:14 by ppajot            #+#    #+#             */
/*   Updated: 2022/07/02 18:13:41 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_error(int err, char *str)
{
	if (err == CMD_NOT_FOUND)
	{
		write(2, "command not found: ", 19);
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	if (err == NOT_ENOUGH_ARG)
		write(2, "not enough arguments\n", 21);
	if (err == INVALID_ARG)
		write(2, "invalid argument\n", 17);
	return (0);
}
