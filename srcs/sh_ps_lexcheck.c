/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ps_lexcheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:44:25 by yoyohann          #+#    #+#             */
/*   Updated: 2022/10/25 18:35:43 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

// use this function for checking every character from the input command.
// to verify whether every character is a valid character or not.

void sh_ps_lexcheck(char *str)
{
    int i = 0;

    while (str[i])
    {
        if (sh_ps_isnum(str[i]))
            printf("[%c] is number\n", str[i]);
        else if (sh_ps_ischar(str[i]))
            printf("[%c] is character\n", str[i]);
        else if (sh_ps_isspechar(str[i]))
            printf("[%c] is special character\n", str[i]);
        else if (sh_ps_isdelimeter(str[i]))
            printf("[%c] is delimeter\n", str[i]);
        else if (sh_ps_isquate(str[i]))
            printf("[%c] is quate\n", str[i]);
        else
            printf("[%c] is invalid character\n", str[i]);
        i++;
    }
}