/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ps_isspechar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:40:16 by yoyohann          #+#    #+#             */
/*   Updated: 2022/10/26 13:29:21 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int sh_ps_isspechar(char c)
{
    if (c == '&' || c == ';' || c == '\\' || c == '\t'
        || c == '(' || c == ')' || c == '\n' || c == '*'
        || c == '?' || c == '#' || c == '-' || c == '='
        || c == '%')
        return (1);
    return (0);
}