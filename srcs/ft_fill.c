/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:46:42 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/20 19:25:09 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_fill_conv(t_s *s)
{
	int		i;
	char	*(*function[13])(t_s *s);

	function[0] = ft_char;
	function[1] = ft_string;
	function[2] = ft_int;
	function[3] = ft_int;
	function[4] = ft_mod;
	i = 0;
	while (s->conv[i])
	{
		if (s->conv[i] == s->format[s->i])
			break ;
		i++;
	}
	return (function[i](s));
}

char	*ft_fill_text(t_s *s)
{
	s->k = 0;
	if (!(s->tmp = (char *)malloc(sizeof(char) * (s->i - s->j + 1))))
		ft_error_miniprintf(s, -3);
	while (s->j < s->i)
	{
		s->tmp[s->k] = s->format[s->j];
		s->j++;
		s->k++;
	}
	s->tmp[s->k] = '\0';
	return (s->tmp);
}
