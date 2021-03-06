/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szverhov <szverhov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:54:24 by szverhov          #+#    #+#             */
/*   Updated: 2017/10/30 12:15:13 by szverhov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	check_width(const char **str, t_flags **formatt, va_list **list)
{
	int res;

	res = 0;
	while (**str && ((**str >= '0' && **str <= '9') ||
	iis(**str, &(*formatt)) || **str == '*'))
	{
		if (**str >= '0' && **str <= '9')
		{
			if (*(*str - 1) == '*')
				res = 0;
			res = (**str - 48) + (res * 10);
		}
		if (**str == '*')
			res = va_arg(**list, int);
		(*str)++;
	}
	(*formatt)->width_len = res;
}
