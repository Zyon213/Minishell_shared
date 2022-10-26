/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ps_isquote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:42:14 by yoyohann          #+#    #+#             */
/*   Updated: 2022/10/26 16:54:01 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int sh_ps_issinglequote(char c)
{
    if (c == 39)
        return (1);
    return (0);
}

int sh_ps_isdoublequote(char c)
{
    if (c == 34)
        return (1);
    return (0);
}

int sh_ps_isescape(char c)
{
    if (c == 27)
        return (1);
    return (0);
}