/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:41:52 by romeo             #+#    #+#             */
/*   Updated: 2023/05/22 18:47:01 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mt.h"

int main(int argc, char **argv)
{
	pid_t pid;
	if (argc > 2)
		ft_printf("too many argument\n");
	if (argc == 1)
		ft_printf("need a message to send");
	if (argc != 2)
		return (0);
	pid = atoi(argv[1]);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	sleep(1);
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return (0);
}
	