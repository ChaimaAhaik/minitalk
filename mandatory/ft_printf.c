/* ************************************************************************** */
/*                                                                           */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:17:56 by cahaik            #+#    #+#             */
/*   Updated: 2024/04/04 14:30:47 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count += ft_putstr("-2");
		n = 147483648;
	}
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n; 
	}
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
	{
		n = n + '0';
		count += ft_putchar(n);
	}
	return (count);
}

static	int	ft_formatsp(va_list args, const char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_putchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_putstr(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		counter += ft_putnbr(va_arg(args, int));
	else if (c == '%')
		counter += ft_putchar('%');
	else
		counter += ft_putchar(c);
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				break ;
			else
			{
				count += ft_formatsp(args, format[i]);
				i++;
			}
		}
		else
			count += ft_putchar(format[i++]);
	}
	va_end(args);
	return (count);
}
