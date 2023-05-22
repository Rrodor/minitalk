/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:41:18 by romeo             #+#    #+#             */
/*   Updated: 2023/05/22 18:45:48 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"
#include <stdio.h>

void testfunc(int test)
{
	ft_printf("Signal1 : %d\n", test);
}

void testfunc2(int test)
{
	ft_printf("signal2 : %d\n", test);
}

int main()
{
	struct sigaction prepaSignal;
	
	ft_printf("PID = %d\n", getpid());
	prepaSignal.sa_handler= &testfunc;
	prepaSignal.sa_flags=0;
	sigemptyset(&prepaSignal.sa_mask);
	sigaction(SIGUSR1, &prepaSignal,0);
	sigaction(SIGUSR2, &prepaSignal,0);
	//pause();
	//signal(SIGUSR1, testfunc);
	//signal(SIGUSR2, testfunc2);
	while (1)
	{
		ft_printf("server is waiting..\n");
		sleep(3);
	}
	return (0);
}