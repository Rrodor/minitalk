/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:41:18 by romeo             #+#    #+#             */
/*   Updated: 2023/05/29 19:30:01 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"
#include <stdio.h>

char *mes;

void sigserv(int signum, siginfo_t *info, void *unknow)
{
	if (signum == SIGUSR1)
		mes = mt_strjoinc(mes, '0');
	else if (signum == SIGUSR2)
		mes = mt_strjoinc(mes, '1');
	kill(info->si_pid, SIGUSR1);
	if (mt_strlen(mes) == 8)
	{
		ft_printf("message received : %c\n", bintochar(mes));
		mes = 0;
		free(mes);
	}
}

char	bintochar(char *bin)
{
	int	c;
	int	x;

	c = 0;
	x = 1;
	while (mt_strlen(bin))
	{
		c += (bin[mt_strlen(bin) - 1] - 48) * x;
		bin[mt_strlen(bin) - 1] = 0;
		x *= 2;
	}
	return ((char) c);
}

char	*mt_strjoinc(char *s, char c)
{
	char	*str;
	size_t	l;
	int 	i;

	if (!s)
	{
		str = (char *)malloc (2 * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = c;
		str[1] = 0;
		return (str);
	}
	l = mt_strlen((char *)s);
	str = malloc((l + 2) * sizeof(char));
	if (!str)
		return (0);
	l = -1;
	while (s[++l])
		str[l] = s[l];
	free(s);
	str[l] = c;
	str[l + 1] = 0;
	return (str);
}

size_t	mt_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int main()
{
	struct sigaction sig;

	ft_printf("PID = %d\n", getpid());
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sigserv;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
