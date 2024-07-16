/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cahaik <cahaik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:02:49 by cahaik            #+#    #+#             */
/*   Updated: 2024/06/12 18:40:18 by cahaik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

typedef struct var
{
	int		j;
	int		i;
	int		index;
	int		len;
	pid_t	old_pid;
	char	*character;
	char	signal_received;
}			t_var;

size_t	ft_strlen(const char *str);
int		ft_atoi(char *str);
int		ft_printf(const char *format, ...);
int		ft_putstr(char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
