
#include "minitalk_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(char *str)
{
	size_t	i;
	int		sign;
	int		number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + sign * (str[i] - '0');
		i++;
	}
	return (number);
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_printf("message received successfuly\n");
	exit(0);
}
