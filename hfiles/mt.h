/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romeo <romeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:41:49 by romeo             #+#    #+#             */
/*   Updated: 2023/05/28 12:37:29 by romeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MT_H
#define MT_H

# include <signal.h>
# include <linux/types.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"

char	*mt_dectoint(int c);
char	*mt_getmes(char *mes);

#endif