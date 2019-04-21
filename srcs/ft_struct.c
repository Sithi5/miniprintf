/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:38:29 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/21 15:27:27 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_set_struct(t_s *s)
{
	if (!(s->output = ft_strnew(0)))
		ft_error_miniprintf(s, -2);
	s->width = 0;
	s->accu = 0;
	s->conv = "csdi%";
	s->zero_fill = 0;
}
