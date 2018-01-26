/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 18:12:12 by mhaiduk           #+#    #+#             */
/*   Updated: 2017/11/09 16:06:03 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	while (n)
	{
		if ((*((unsigned char *)dst++) = *((unsigned char *)src++)) ==
			(unsigned char)c)
			return (dst);
		n--;
	}
	return (NULL);
}
