/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:01:04 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/20 21:00:19 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char *ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	while (dest[j])
	{
		src[i + j] = dest[j];
		j++;
	}
	return (src);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	char *new_av[] = {0, 0};
	char *str;
	str = (char *)malloc(50 * sizeof(char));
	str[0] = 0;
	str = ft_strcat("/bin/", str);
	str = ft_strcat(av[1], str);
	new_av[0] = str;
	execve(str, new_av, 0);
}