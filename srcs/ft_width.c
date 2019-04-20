/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:15:08 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/20 20:06:47 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_check_width(t_s *s)
{
	if (s->format[s->i] && ft_isdigit(s->format[s->i]))
	{
		s->width = ft_atoi(s->format + s->i);
		while (s->format[s->i] && ft_isdigit(s->format[s->i]))
			s->i++;
	}

}

char	*ft_set_width(t_s *s, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (s->width > 0)
			s->width--;
		i++;
	}
	ft_putstr("ici\n");
	while (s->width > 0)
	{
		if (!(str = ft_strjoind(" ", str)))
		{
			ft_strdel(&str);
			ft_error_miniprintf(s, -3);
		}
		s->width--;
	}
	s->width = 0;
	return (str);
}
