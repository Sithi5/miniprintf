/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:16:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/16 14:26:14 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPRINTF_H
# define MINIPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct				s_stru
{
	int						buff;
	int						i;
	int						j;
	int						k;
}							t_stru;

int							miniprintf(const char *format, ...);

#endif
