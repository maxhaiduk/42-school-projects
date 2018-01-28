/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaiduk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:53:34 by mhaiduk           #+#    #+#             */
/*   Updated: 2018/01/19 17:58:14 by mhaiduk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_get_len(long long n)
{
	size_t len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char			*ft_itoa_abs(long long n)
{
	long long	num;
	char		temp;
	size_t		len;
	char		*str;

	num = n;
	len = ft_get_len(n);
	str = ft_strnew(len);
	if (n == 0)
		str[0] = '0';
	len--;
	while (num)
	{
		temp = num % 10;
		temp = FT_ABS(temp);
		str[len] = temp + '0';
		num /= 10;
		len--;
	}
	return (str);
}
