/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:01:25 by mabouce           #+#    #+#             */
/*   Updated: 2019/01/17 14:41:47 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniprintf.h"

int		main(void)
{
	miniprintf("mine: bidonjour%s", "\nlalala\n");
	printf("\npf: bidou\n");
}