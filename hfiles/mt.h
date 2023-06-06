/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrodor <rrodor@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:41:49 by romeo             #+#    #+#             */
/*   Updated: 2023/06/06 18:01:17 by rrodor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
# define MT_H

# include <signal.h>
# include <linux/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

//client
char	*mt_dectoint(int c);
char	*mt_getmes(char *mes);
void	sigcli(int signum, siginfo_t *info, void *unknow);
int		mt_errorclient(int argc);
char	*mt_strjoin(char *s1, char *s2);
size_t	mt_strlen2(char *s);
int		mt_isdigit(int c);
int		mt_atoi(char *nptr);

//server
char	*mt_strjoinc(char *s, char c);
size_t	mt_strlen(char *str);
void	sigserv(int signum, siginfo_t *info, void *unknow);
char	bintochar(char *bin);

#endif
