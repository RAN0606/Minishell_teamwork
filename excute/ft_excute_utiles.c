/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_excute_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:22:46 by rliu              #+#    #+#             */
/*   Updated: 2022/07/13 14:34:58 by rliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_perror(char *str, int i)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len + 1);
	return (i);
}
