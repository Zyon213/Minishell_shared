/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ps_lexcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:44:25 by yoyohann          #+#    #+#             */
/*   Updated: 2022/10/25 18:17:46 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// use this function for checking every character from the input command.
// to verify whether every character is a valid character or not.

void sh_ps_lexcheck(char *str)
{
    int i = 0;
    int len = ft_strlen(str);

    while (str[i])
    {
        if (ft_isnum(str[i]))
            printf("[%c] is number\n", str[i]);
        else if (ft_ischar(str[i]))
            printf("[%c] is character\n", str[i]);
        else if (ft_isspchar(str[i]))
            printf("[%c] is special character\n", str[i]);
        else if (ft_isdelimeter(str[i]))
            printf("[%c] is delimeter\n", str[i]);
        else if (ft_isquate(str[i]))
            printf("[%c] is quate\n", str[i]);
        else
            printf("[%c] is invalid character\n", str[i]);
        i++;
    }
}