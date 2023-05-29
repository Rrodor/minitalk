/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:41:52 by romeo             #+#    #+#             */
/*   Updated: 2023/05/29 19:50:19 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

char *mes;

int main(int argc, char **argv)
{
	pid_t pid;
	struct sigaction sig;

	if (mt_errorclient(argc) == 0)
		return (0);
	pid = atoi(argv[1]);
	sigemptyset(&sig.sa_mask);
	ft_printf("PID = %d\n", getpid());
	mes = mt_getmes(argv[2]);
	ft_printf("%s\n", mes);
	if (mes[0] == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	sig.sa_flags= SA_SIGINFO;
	sig.sa_sigaction= sigcli;
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		pause();
	//ft_printf("%s\n", mt_strjoin(mt_dectoint('a'), mt_dectoint('b')));
	return (0);
}

void	sigcli(int signum, siginfo_t *info, void *unknow)
{
	pid_t		pid;
	static int	i = 1;

	ft_printf("test mes=%s i=%d\n", mes, i);
	pid = info->si_pid;
	if (mes[i] == '0')
		kill(pid, SIGUSR1);
	else if (mes[i] == '1')
		kill(pid, SIGUSR2);
	else
		exit(0);
	i++;
}
int	mt_errorclient(int argc)
{
	if (argc > 3)
		ft_printf("too many argument\n");
	if (argc == 2)
		ft_printf("need a message to send");
	if (argc != 3)
		return (0);
	return (1);
}

char	*mt_getmes(char *mes)
{
	char	*mesbin;
	int		i;

	i = 0;
	while (mes[i])
	{
		mesbin = mt_strjoin(mesbin, mt_dectoint((int)mes[i]));
		i++;
	}
	return (mesbin);
}

char	*mt_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;

	i = -1;
	if (!s1)
		return (s2);
	str = malloc(17 * sizeof(char));
	if (!str)
		return (0);
	while (++i < 8)
		str[i] = s1[i];
	i = -1;
	while (++i < 8)
		str[i + 8] = s2[i];
	//free (s1);
	//free (s2);
	return (str);
}

char	*mt_dectoint(int c)
{
	char	*mesbin;
	int		i;

	mesbin = (char *)malloc(9 * sizeof(char));
	i = 7;
	while (i >= 0)
	{
		mesbin[i] = c % 2 + 48;
		c /= 2;
		i--;
	}
	mesbin[9] = 0;
	return (mesbin);
}
