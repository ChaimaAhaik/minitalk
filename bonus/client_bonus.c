/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:12:31 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/13 11:32:54 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_signal(int pid, int *ptr, int len)
{
	int	i;

	i = len;
	while (i >= 0)
	{
		if (ptr[i] == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	*length(int len)
{
	int			i;
	static int	ar[32];

	i = 0;
	while (i < 32)
	{
		if ((len & 1) == 1)
			ar[i] = 1;
		else
			ar[i] = 0;
		i++;
		len = len >> 1;
	}
	return (ar);
}

int	*my_string_bits(char str)
{
	int			j;
	static int	ar[8];

	j = 0;
	while (j < 8)
	{
		if ((str & 1) == 1)
			ar[j] = 1;
		else
			ar[j] = 0;
		j++;
		str = str >> 1;
	}
	return (ar);
}

void	client(pid_t pid, char *str)
{
	int	i;
	int	j;
	int	*ptr;

	i = 4;
	j = 0;
	ptr = length(ft_strlen(str));
	send_signal(pid, ptr, 31);
	i = 0;
	while (str && str[i])
	{
		ptr = my_string_bits(str[i]);
		send_signal(pid, ptr, 7);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	signal (SIGUSR2, signal_handler);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid > 2)
			client(pid, argv[2]);
		else
			exit(1);
	}
	else
		exit(1);
	return (0);
}
