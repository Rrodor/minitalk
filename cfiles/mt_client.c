/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:41:52 by romeo             #+#    #+#             */
/*   Updated: 2023/05/25 20:10:13 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int main(int argc, char **argv)
{
	pid_t pid;
	char *mes;
	
	if (argc > 3)
		ft_printf("too many argument\n");
	if (argc == 2)
		ft_printf("need a message to send");
	if (argc != 3)
		return (0);
	//pid = atoi(argv[1]);
	ft_printf("PID = %d\n", getpid());
	mes = mt_getmes(argv[2]);
	ft_printf("%s\n", mes);
	kill(pid, SIGUSR1);
	/*kill(pid, SIGUSR2);
	usleep(100);
	kill(pid, SIGUSR2);
	kill(pid, SIGUSR1);*/
	return (0);
}
	
char	*mt_getmes(char *mes)
{
	char *mesbin;

	mesbin = mt_dectoint((int)mes[0]);
	return (mesbin);
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