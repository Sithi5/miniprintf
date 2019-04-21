/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:57:45 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/21 15:34:29 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

int		ft_is_conv(char c, t_s *s)
{
	int	i;

	i = 0;
	while (s->conv[i])
	{
		if (c == s->conv[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_read_format(t_s *s)
{
	s->i = -1;
	s->j = 0;
	while (s->format[++s->i])
	{
		if (s->format[s->i] == '%')
		{
			if (!(s->output = ft_strdjoind(s->output
							, ft_fill_text(s))))
				ft_error_miniprintf(s, -3);
			s->i++;
			if (s->format[s->i] == '0')
				s->zero_fill = 1;
			ft_check_width(s);
			ft_check_accu(s);
			while (s->format[s->i]
					&& ft_is_conv(s->format[s->i], s) != 1)
				s->i++;
			if (!(s->output = ft_strdjoind(s->output
							, ft_fill_conv(s))))
				ft_error_miniprintf(s, -3);
			s->i++;
			s->j = s->i;
		}
	}
	if (!(s->output = ft_strdjoind(s->output, ft_fill_text(s))))
		ft_error_miniprintf(s, -3);
}

int		miniprintf(const char *format, ...)
{
	t_s		*s;

	if (!(s = (t_s *)malloc(sizeof(t_s))))
		ft_error_miniprintf(s, 0);
	va_start(s->va, format);
	if (!(s->format = ft_strdup((char *)format)))
		ft_error_miniprintf(s, -1);
	ft_set_struct(s);
	ft_read_format(s);
	ft_putstr(s->output);
	ft_strdel(&(s->format));
	ft_strdel(&(s->output));
	free(s);
	va_end(s->va);
	return (0);
}
