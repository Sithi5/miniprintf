/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 15:46:42 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/23 13:36:40 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*(*g_function[13])(t_stru *stru) = {ft_char, ft_string, ft_int, ft_int};

char	*ft_fill_conv(t_stru *stru)
{
	int	i;

	i = 0;
	while (stru->conv[i])
	{
		if (stru->conv[i] == stru->format[stru->i])
			break ;
		i++;
	}
	return (g_function[i](stru));
}

char	*ft_fill_text(t_stru *stru)
{
	stru->k = 0;
	if (!(stru->tmp = (char *)malloc(sizeof(char) * (stru->i - stru->j + 1))))
		ft_error_miniprintf();
	while (stru->j < stru->i)
	{
		stru->tmp[stru->k] = stru->format[stru->j];
		stru->j++;
		stru->k++;
	}
	stru->tmp[stru->k] = '\0';
	return (stru->tmp);
}
