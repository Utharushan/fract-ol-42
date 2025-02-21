/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuthayak <tuthayak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:43:09 by tuthayak          #+#    #+#             */
/*   Updated: 2024/12/19 16:43:09 by tuthayak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/libft.h"

int	ft_isdigit(int c)
{
	return (48 <= c && c <= 57);
}
