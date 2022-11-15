# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int sh_ps_isdelimeter(char c)
{
    if (c == ' ' || c == '>' || c == '<' || c == '|')
        return (1);
    return (0);
}

int sh_ps_issinglequote(char c)
{
    if (c == 39)
        return (1);
    return (0);
}

int sh_ps_issinglequoted(char *str, int i)
{
    int left;
    int right;
    int l = 0;
    int r = 0;

    if (sh_ps_isdelimeter(str[i]))
    {
        left = i;
        while (--left >= 0)
        {
            if (sh_ps_issinglequote(str[left]))
                l++;
        }
        right = i;
        while (++right < ft_strlen(str))
        {
            if (sh_ps_issinglequote(str[right]))
                r++;
        }
    }
    if (l % 2 == 1 && r % 2 == 1)
        return (1);
    return (0);
}

int	count_words(char *str, char c)
{
	int		i;
    int j;
	int		trigger;

	i = 0;
    j = 0;
	trigger = 0;
	while (str[j])
	{
		if (str[j] != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (str[j] == c && !sh_ps_issinglequoted(str, j))
			trigger = 0;
		j++;
	}
	return (i);
}

char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0 && !sh_ps_issinglequoted(s, i)) 
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

int main(int argc, char **argv)
{
    char *str = "ab'cd'ef ghi 'fasdf asdf' fasf jhjh";
    char **splt;
    splt = ft_split(str, ' ');

    int len = count_words(str, ' ');
    for (int i = 0; i < len; i++)
        printf("%s \n", splt[i]);

   /*  char str[] = "yo'''n yo'h 'dfasd'''a";

    int i = 0;
    while (str[i])
    {
        if (sh_ps_isdelimeter(str[i]))
        {
            printf("[%d] ", i);
            sh_ps_issinglequoted(str, i);
            printf("\n");
        }
        i++;
    } */
    return (0);
 }