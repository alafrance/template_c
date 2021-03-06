/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_rate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 17:20:14 by alafranc          #+#    #+#             */
/*   Updated: 2021/03/26 06:59:19 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_rate(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.space_reverse)
		flags.display_zero = 0;
	if (!flags.space_reverse && !flags.display_zero)
		count += ft_display_repeat(' ', flags.lmc - 1);
	if (flags.display_zero && flags.lmc > 1)
		count += ft_display_repeat('0', flags.lmc - 1);
	count += ft_putchar_1('%');
	if (flags.space_reverse && !flags.display_zero)
		count += ft_display_repeat(' ', flags.lmc - 1);
	return (count);
}
