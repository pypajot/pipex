/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppajot <ppajot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:10:05 by ppajot            #+#    #+#             */
/*   Updated: 2022/06/24 17:14:50 by ppajot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (dest[n])
		n++;
	while (src[i] != '\0')
	{
		dest[i + n] = src[i];
		i++;
	}
	dest[i + n] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2, char *sep)
{
	size_t	len;
	char	*res;
	int		i;

	i = 0;
	if (sep != 0)
		i = ft_strlen(sep);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)malloc(len + 1 + i);
	if (!res)
		return (0);
	*res = 0;
	res = ft_strcat(res, s1);
	if (sep != 0)
		res = ft_strcat(res, sep);
	res = ft_strcat(res, s2);
	return (res);
}
