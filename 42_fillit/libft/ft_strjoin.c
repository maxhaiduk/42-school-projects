/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:46:58 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 13:44:38 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = ft_strnew(len1 + len2);
	if (dest)
	{
		while ((*dest = *s1))
		{
			dest++;
			s1++;
		}
		while ((*dest = *s2))
		{
			dest++;
			s2++;
		}
		return (dest - (len1 + len2));
	}
	return (NULL);
}
