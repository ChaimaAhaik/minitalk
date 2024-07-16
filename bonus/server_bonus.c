/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:12:27 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/13 11:32:05 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_var	g_ptr;

static void	length_bits(int rof)
{
	if (rof == 0)
	{
		if (g_ptr.i == 7)
		{
			g_ptr.character[g_ptr.index] = g_ptr.signal_received;
			g_ptr.i = 0;
			(g_ptr.index)++;
			g_ptr.signal_received = 0;
		}
		else
			(g_ptr.i)++;
		(g_ptr.j)++;
	}
	else
	{
		free(g_ptr.character);
		g_ptr.character = NULL;
		g_ptr.j = 0;
		g_ptr.i = 0;
		g_ptr.len = 0;
		g_ptr.index = 0;
		g_ptr.old_pid = 0;
		g_ptr.signal_received = 0;
	}
}

int	alloc_ation(void)
{
	if (g_ptr.len <= 0)
		return (1);
	g_ptr.character = malloc(g_ptr.len);
	if (!g_ptr.character)
		return (1);
	return (0);
}

static void	shift_length(int sig, int loc)
{
	if (loc == 0)
	{
		if (sig == SIGUSR1)
			g_ptr.len = g_ptr.len << 1;
		else if (sig == SIGUSR2)
			g_ptr.len = (g_ptr.len << 1) | 1;
	}
	else
	{
		if (sig == SIGUSR1)
			g_ptr.signal_received = g_ptr.signal_received << 1;
		else if (sig == SIGUSR2)
			g_ptr.signal_received = (g_ptr.signal_received << 1) | 1;
	}
}

void	sig_received(int sig, struct __siginfo *info, void *context)
{
	(void)context;
	if (g_ptr.old_pid != 0 && g_ptr.old_pid != info->si_pid)
		length_bits(1);
	g_ptr.old_pid = info->si_pid;
	if (g_ptr.j < 32)
	{
		shift_length(sig, 0);
		(g_ptr.j)++;
		if (g_ptr.j == 32 && alloc_ation() == 1)
			length_bits(1);
	}
	else
	{
		shift_length(sig, 1);
		length_bits(0);
		if (g_ptr.index == g_ptr.len)
		{
			g_ptr.character[g_ptr.index] = '\0';
			kill(info->si_pid, SIGUSR2);
			ft_printf("%s", g_ptr.character);
			length_bits(1);
			return ;
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID: %d\n", pid);
	sa.sa_sigaction = sig_received;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
