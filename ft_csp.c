/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_csp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/17 17:34:52 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniprintf.h"

char	*ft_char(t_stru *stru)
{
	char	c;
	char	*tmp;

	tmp = ft_strnew(2);
	c = va_arg(stru->va, int);
	ft_memset((void *)tmp, c, 1);
	return (tmp);
}

char	*ft_string(t_stru *stru)
{
	char	*tmp;

	tmp = ft_strdup(va_arg(stru->va, char *));
	return (tmp);
}
