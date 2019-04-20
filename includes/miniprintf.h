/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:16:27 by mabouce           #+#    #+#             */
/*   Updated: 2019/04/20 19:08:26 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIPRINTF_H
# define MINIPRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef struct				s_s
{
	int						buff;
	int						i;
	int						j;
	int						k;
	int						width;

	char					*format;
	char					*tmp;
	char					*output;
	char					*conv;
	va_list					va;
}							t_s;

int							miniprintf(const char *format, ...);
int							ft_is_conv(char c, t_s *s);
void						ft_check_width(t_s *s);
void						ft_read_format(t_s *s);

char						*ft_char(t_s *s);
char						*ft_mod(t_s *s);
char						*ft_string(t_s *s);
char						*ft_ptr(t_s *s);
char						*ft_int(t_s *s);
char						*ft_fill_conv(t_s *s);
char						*ft_fill_text(t_s *s);

void						ft_error_miniprintf(t_s *s, int error);

void						ft_set_struct(t_s *s);

#endif
