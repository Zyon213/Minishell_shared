/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ps_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 13:36:59 by yoyohann          #+#    #+#             */
/*   Updated: 2022/10/26 13:40:24 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void sh_ps_token(char *cmd)
{
    char **split;
    int len;
    int i;

    char del[] = {' ', '|', '<', '>'};

    split = ft_split_set(cmd, del);
    len = sizeof(split) / sizeof(split[0]);
    i = 0;

    while (split[i])
        printf("[%s] is a token\n", split[i++] );    

}