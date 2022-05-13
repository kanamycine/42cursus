/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinychoi <jinychoi@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:03:19 by jinychoi          #+#    #+#             */
/*   Updated: 2022/04/05 15:08:36 by jinychoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_format_specifier(va_list *ap, const char format);
int	ft_s(char *str);
int	ft_di(int n, int init);
int	ft_p(unsigned long long ptr, int init);
int	ft_u(unsigned int n, int init);
int	ft_x(unsigned int num, const char format, int init);

#endif
