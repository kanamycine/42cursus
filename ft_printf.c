/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinychoi <jinychoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:02:02 by jinychoi          #+#    #+#             */
/*   Updated: 2022/04/05 16:45:25 by jinychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format_specifier(va_list *ap, const char format)
{
	char	c;

	if (format == 'c')
	{
		c = va_arg(*ap, int);
		return (write(1, &c, 1));
	}
	else if (format == 's')
		return (ft_s(va_arg(*ap, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_di(va_arg(*ap, int), 1));
	else if (format == 'p')
		return (ft_p(va_arg(*ap, unsigned long long), 1));
	else if (format == 'u')
		return (ft_u(va_arg(*ap, unsigned int), 1));
	else if (format == 'x' || format == 'X')
		return (ft_x(va_arg(*ap, unsigned int), format, 1));
	else if (format == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	int		length;
	int		i;
	va_list	ap;

	length = 0;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			length += ft_format_specifier(&ap, str[++i]);
		else
			length += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (length);
}
