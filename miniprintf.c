/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:57:45 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/17 15:17:04 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

int		ft_is_conv(char c, t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->conv[i])
	{
		if (c == stru->conv[i])
			return (1);
		i++;
	}
	return (0);
}	

void	ft_error(t_stru *stru)
{
	ft_strdel(&(stru->format));
	ft_strdel(&(stru->tmp));
	ft_strdel(&(stru->output));
	ft_putstr("\nAn error occured.\n");
	exit (0);
}

char	*ft_fill_conv(t_stru *stru)
{
		stru->output = ft_strdjoind(stru->output, ft_fill_conv(stru));
}

char	*ft_fill_text(t_stru *stru)
{
	stru->k = 0;
	if (!(stru->tmp = (char *)malloc(sizeof(char) * (stru->i - stru->j + 1))))
		ft_error(stru);
	while (stru->j < stru->i)
	{
		stru->tmp[stru->k] = stru->format[stru->j];
		stru->j++;
		stru->k++;
	}
	stru->tmp[stru->k] = '\0';
	return (stru->tmp);
}

void	ft_read_format(t_stru *stru)
{
	stru->i = 0;
	stru->j = 0;
	if (!(stru->output = ft_strnew(0)))
		ft_error(stru);
	while (stru->format[stru->i])
	{
		if (stru->format[stru->i] == '%')
		{
			stru->output = ft_strdjoind(stru->output, ft_fill_text(stru));
			while (!(ft_is_conv(stru->format[stru->i], stru)))
				stru->i++;
			stru->output = ft_strdjoind(stru->output, ft_fill_conv(stru));
			stru->i++;
			stru->j = stru->i;
		}
		stru->i++;
	}
	stru->output = ft_strdjoind(stru->output, ft_fill_text(stru));
}

void	ft_set_conv(t_stru *stru)
{
		stru->conv = "diouxXcspf";
}

int		miniprintf(const char *format, ...)
{
	t_stru		*stru;

	if (!(stru = (t_stru *)malloc(sizeof(t_stru))))
		ft_error(stru);
	va_start(stru->va, format);
	stru->format = (char *)format;
	ft_set_conv(stru);
	ft_read_format(stru);
	ft_putstr(stru->output);
	va_end(stru->va);
	return (0);
}
