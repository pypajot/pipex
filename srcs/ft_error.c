/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 19:05:14 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/23 21:52:08 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_error(int err, char *str)
{
	if (err == CMD_NOT_FOUND)
		ft_printf("command not found: %s\n", str);
	if (err == NO_SUCH_FILE)
		ft_printf("No such file or directory: %s\n", str);
	return (0);
}
