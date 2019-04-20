/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:15:08 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/20 19:15:34 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_check_width(t_s *s)
{
	if (ft_isdigit(s->format[s->i]))
	{
		s->width = ft_atoi(s->format + s->i);
		while (ft_isdigit(s->format[s->i]))
			s->i++;
		ft_putnbr(s->width);
	}
	else
		s->i++;
}
