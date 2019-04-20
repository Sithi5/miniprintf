/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:47:22 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/20 17:56:00 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_error_miniprintf(t_s *s, int error)
{
	ft_putstr("An error occured in Miniprintf.\n");
	if (error == -1)
		free(s);
	if (error == -2)
	{
		ft_strdel(&(s->format));
		free(s);
	}
	if (error == -3)
	{
		ft_strdel(&(s->format));
		ft_strdel(&(s->output));
		free(s);
	}
	exit(0);
}
