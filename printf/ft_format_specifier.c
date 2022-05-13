/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinychoi <jinychoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:52 by jinychoi          #+#    #+#             */
/*   Updated: 2022/04/05 16:46:19 by jinychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_s(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[i])
		length += write(1, &str[i++], 1);
	return (length);
}

int	ft_di(int n, int init)
{
	static int	length;

	if (init)
		length = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		length += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_di(n / 10, 0);
	length += write(1, &"0123456789"[n % 10], 1);
	return (length);
}

int	ft_p(unsigned long long n, int init)
{
	static int	length;

	if (init)
		length = write(1, "0x", 2);
	if (n >= 16)
		ft_p(n / 16, 0);
	length += write(1, &"0123456789abcdef"[n % 16], 1);
	return (length);
}

int	ft_u(unsigned int n, int init)
{
	static int	length;

	if (init)
		length = 0;
	if (n > 9)
		ft_u(n / 10, 0);
	length += write(1, &"0123456789"[n % 10], 1);
	return (length);
}

int	ft_x(unsigned int n, const char format, int init)
{
	static int	length;

	if (init)
		length = 0;
	if (n >= 16)
		ft_x(n / 16, format, 0);
	if (format == 'x')
		length += write(1, &"0123456789abcdef"[n % 16], 1);
	else if (format == 'X')
		length += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (length);
}
