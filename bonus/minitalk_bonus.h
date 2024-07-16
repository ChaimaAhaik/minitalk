
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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
void	signal_handler(int sig);

#endif