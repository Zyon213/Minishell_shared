/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ps_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <yoyohann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 12:38:28 by yoyohann          #+#    #+#             */
/*   Updated: 2022/10/26 18:10:03 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/* int sh_ps_issinglequoted(char *str, int i)
{
    int start;
    int end;
    int index;

    while (str[i])
    {
        if (sh_ps_isdelimeter(str[i]))
        {
            index = i;
            start = i - 1;
            while(start >= 0 )
            {
                if (sh_ps_issinglequote(str[start]))
                    break;
                start--;
            }
            end = i + 1;
            while (end < ft_strlen(str))
            {
                if (sh_ps_issinglequote(str[end]))
                    break;
                end++;
            }
        }
        i++;
    }
    if (index > start && index < end)
        return (1);
    return (0);
} */

int sh_ps_issinglequoted(char *str)
{
    int left;
    int right;
    int i;
    int l = 0;
    int r = 0;

    i = 0;
    while (str[i])
    {
        if (sh_ps_isdelimeter(str[i]))
        {
            left = i;
            while (left >= 0)
            {
                if (sh_ps_issinglequote(str[left]))
                    l++;
                left--;
            }
            right = i;
            while (right < ft_strlen(str))
            {
                if (sh_ps_issinglequote(str[right]))
                    r++;
                right++;
            }
        }
        i++;
    }
    if (l % 2 == 1 && r % 2 == 1)
        return (1);
    return (0);
}