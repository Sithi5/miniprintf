/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:15:08 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/21 15:29:17 by mabouce          ###   ########.fr       */
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

void	ft_apply_width_zero(t_s *s)
{
	while (s->width > 0)
	{
		if (s->width >= 2)
		{
			if (!(s->str = ft_strjoind("00", s->str)))
			{
				ft_strdel(&s->str);
				ft_error_miniprintf(s, -3);
			}
			s->width -= 2;
		}
		else
		{
			if (!(s->str = ft_strjoind("0", s->str)))
			{
				ft_strdel(&s->str);
				ft_error_miniprintf(s, -3);
			}
			s->width--;
		}
	}
}

void	ft_apply_width_blanc(t_s *s)
{
	while (s->width > 0)
	{
		if (s->width >= 2)
		{
			if (!(s->str = ft_strjoind("  ", s->str)))
			{
				ft_strdel(&s->str);
				ft_error_miniprintf(s, -3);
			}
			s->width -= 2;
		}
		else
		{
			if (!(s->str = ft_strjoind(" ", s->str)))
			{
				ft_strdel(&s->str);
				ft_error_miniprintf(s, -3);
			}
			s->width--;
		}
	}
}

char	*ft_apply_width(t_s *s, char *str)
{
	int i;

	i = 0;
	if (!(s->str = ft_strdupd(str)))
	{
		ft_strdel(&str);
		ft_error_miniprintf(s, -3);
	}
	while (s->str[i])
	{
		if (s->width > 0)
			s->width--;
		i++;
	}
	if (s->zero_fill == 0 )
		ft_apply_width_blanc(s);
	else if (s->zero_fill == 1)
		ft_apply_width_zero(s);
	s->width = 0;
	s->zero_fill = 0;
	return (s->str);
}
