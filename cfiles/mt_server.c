/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:41:18 by romeo             #+#    #+#             */
/*   Updated: 2023/05/28 12:42:59 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"
#include <stdio.h>

void sigrecept(int signum, siginfo_t *info, void *unknow)
{
	ft_printf("receive message from : %d\n", info->si_pid);
	if (signum == SIGUSR1)
		ft_printf("0");
	else if (signum == SIGUSR2)
		ft_printf("1");
	//ft_printf("Signal1 : %d\n", test);
}

void sigrecept2(int signum)
{
	//ft_printf("receive message from : %d\n", info->si_pid);
	if (signum == SIGUSR1)
		ft_printf("0");
	else if (signum == SIGUSR2)
		ft_printf("1");
	//ft_printf("Signal1 : %d\n", test);
}

int main()
{
	struct sigaction sig;
	
	ft_printf("PID = %d\n", getpid());
	sig.sa_flags= SA_SIGINFO;
	sig.sa_sigaction= sigrecept;
	//sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, 0);
	//signal(SIGUSR1, testfunc);
	//signal(SIGUSR2, testfunc2);
	pause();
	return (0);
}