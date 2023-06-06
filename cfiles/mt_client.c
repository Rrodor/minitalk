/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:41:52 by romeo             #+#    #+#             */
/*   Updated: 2023/06/06 17:59:28 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char	*g_mes;

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sig;

	if (mt_errorclient(argc) == 0)
		return (0);
	pid = mt_atoi(argv[1]);
	sigemptyset(&sig.sa_mask);
	g_mes = mt_getmes(argv[2]);
	if (g_mes[0] == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = sigcli;
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		pause();
	return (0);
}

void	sigcli(int signum, siginfo_t *info, void *unknow)
{
	pid_t		pid;
	static int	i = 1;

	pid = info->si_pid;
	if (g_mes[i] == '0')
		kill(pid, SIGUSR1);
	else if (g_mes[i] == '1')
		kill(pid, SIGUSR2);
	usleep(100);
	if (g_mes[i] == 0)
	{
		free(g_mes);
		ft_printf("message received\n");
		exit(0);
	}
	i++;
}

int	mt_errorclient(int argc)
{
	if (argc > 3)
	{
		ft_printf("too many argument, format is ");
		ft_printf("./client [target pid] [message to send]\n");
	}
	if (argc < 3)
	{
		ft_printf("too few argument, format is ");
		ft_printf("./client [target pid] [message to send]\n");
	}
	if (argc != 3)
		return (0);
	return (1);
}

char	*mt_getmes(char *mes)
{
	char	*mesbin;
	int		i;
	char	*nulbin;

	i = 0;
	nulbin = (char *) malloc (8 * sizeof(char));
	while (i < 8)
	{
		nulbin[i] = '0';
		i++;
	}
	nulbin[i] = 0;
	i = 1;
	mesbin = mt_dectoint((int)mes[0]);
	while (mes[i])
	{
		mesbin = mt_strjoin(mesbin, mt_dectoint((int)mes[i]));
		i++;
	}
	mesbin = mt_strjoin(mesbin, nulbin);
	return (mesbin);
}

char	*mt_dectoint(int c)
{
	char	*mesbin;
	int		i;

	mesbin = (char *)malloc(9 * sizeof(char));
	if (c < 0)
	{
		c = 256 + c;
		mesbin[0] = '1';
	}
	else
		mesbin[0] = '0';
	i = 7;
	while (i >= 1)
	{
		if (c % 2 == 0)
			mesbin[i] = '0';
		else
			mesbin[i] = '1';
		c /= 2;
		i--;
	}
	mesbin[8] = 0;
	return (mesbin);
}
