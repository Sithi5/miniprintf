/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:47:22 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/23 12:41:57 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

void	ft_error_miniprintf(t_stru *stru)
{
	ft_strdel(&(stru->format));
	ft_strdel(&(stru->tmp));
	ft_strdel(&(stru->output));
	ft_putstr("\nAn error occured.\n");
	exit(0);
}
